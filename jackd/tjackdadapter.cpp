/* -----------------------------------------------------------------------------
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
----------------------------------------------------------------------------- */

/* -----------------------------------------------------------------------------
 * Headnotes
 *
 * [100]    We leave it at activating the client. We won't connect our input ports to
 *          any other jack ports, but leave this to third party tools such as
 *          jack_connect.
 *
 * [110]    Jack2 expects the process callback function to return 0. Otherwise we get
 *          an "Cannot connect ports owned by inactive clients" error.
 * -----------------------------------------------------------------------------
 */

#include "tjackdadapter.h"

/**
 * @brief TJackDAdapter::TJackDAdapter
 * @param idClient
 * @param idInPortL
 * @param idInPortR
 */
TJackDAdapter::TJackDAdapter (const char* idClient, const char* idInPortL, const char* idInPortR)
{
    fIDClient               = idClient;
    fIDPortL                = idInPortL;
    fIDPortR                = idInPortR;
    fStatus                 = kIsClosed;
    fConnectorL             = new TEndpoint_DirectIO (idInPortL);
    fConnectorR             = new TEndpoint_DirectIO (idInPortR);
}

TJackDAdapter::~TJackDAdapter ()
{
    _Close ();
    delete fConnectorL;
    delete fConnectorR;
}

void TJackDAdapter::Close ()
{
    _Close ();
}

TJackDAdapter::EStatus TJackDAdapter::GetStatus ()
{
    return fStatus;
}

bool TJackDAdapter::Open ()
{
    bool    ret;

    ret = _Open ();

    return ret;
}

void TJackDAdapter::RegisterWith (TRouter& r)
{
    r.Register (fConnectorL);
    r.Register (fConnectorR);
}

int TJackDAdapter::_CallbackProcess (jack_nframes_t nFrames, void* host)
{
    sample_t*        samplesL;
    sample_t*        samplesR;
    TJackDAdapter*   h;

    h        = (TJackDAdapter*) host;
    samplesL = (sample_t*) jack_port_get_buffer (h->fObjInputPortL, nFrames);
    samplesR = (sample_t*) jack_port_get_buffer (h->fObjInputPortR, nFrames);

    return 0;               /* [110] */
}

void TJackDAdapter::_CallbackShutdown (void *arg)
{
    exit (-1);
}

void TJackDAdapter::_Close ()
{
    if (fStatus == kIsOpen)
    {
        jack_client_close (fObjClient);
        fStatus = kIsClosed;
    }
}

bool TJackDAdapter::_Open ()
{
    int     success;
    bool    ret;

    ret        = true;
    fStatus    = kIsOpen;

    /*
     * Open a client connection to the running instance of jackd.
     */
    fObjClient = jack_client_open (fIDClient, kOptionsClient, &fSysStatus, NULL);
    if (fObjClient == NULL)
    {
        ret     = false;
        fStatus = kErrorFailedOpenClient;
        std::cerr << "jack_client_open() failed. System status=" << fSysStatus << std::endl;
        if (fSysStatus & JackServerFailed)
        {
            std::cerr << "Unable to connect to JACK server" << std::endl;
        }
    }
    else
    {
        std::cout << "Successfully connected Jack client '" << fIDClient << "' to Jack server." << std::endl;
    }

    /*
     * Register callbacks with the server.
     */

    /* Process callback. Will be called by the Jack server in a regular interval for passing data back and forth. */
    jack_set_process_callback (fObjClient, TJackDAdapter::_CallbackProcess, this);

    /* Shutdown hook. Will be called by the Jack server when it shuts down or decides to stop calling the process callback. */
    jack_on_shutdown (fObjClient, TJackDAdapter::_CallbackShutdown, this);

    /*
     * Register stereo input port (i.e. two mono ports). [100]
     */
    if (ret == true)
    {
        fObjInputPortL  = jack_port_register (fObjClient, fIDPortL, JACK_DEFAULT_AUDIO_TYPE, JackPortIsInput, 0);
        fObjInputPortR  = jack_port_register (fObjClient, fIDPortR, JACK_DEFAULT_AUDIO_TYPE, JackPortIsInput, 0);

        if (fObjInputPortL == NULL)
        {
            ret     = false;
            fStatus = kErrorFailedOpenPort;
            std::cerr << "Failed to open port '" << fIDPortL << "'" << std::endl;
        }
        else
        {
            std::cout << "Successfully registered port '" << fIDPortL << "' to Jack server." << std::endl;
        }
        if (fObjInputPortR == NULL)
        {
            ret     = false;
            fStatus = kErrorFailedOpenPort;
            std::cerr << "Failed to open port '" << fIDPortR << "'" << std::endl;
        }
        else
        {
            std::cout << "Successfully registered port '" << fIDPortR << "' to Jack server." << std::endl;
        }
    }

    /*
     * Notify the Jack server that everything is set up. The server
     * will start calling the registered callback function
     * ( TJackDAdapter::_Process(...) ) in a regular interval.
     * [100]
     */
    if (ret == true)
    {
        success = jack_activate (fObjClient);
        if (success != 0)
        {
            ret         = false;
            fStatus     = kErrorFailedActivateClient;
            std::cerr << "Failed to activate client" << std::endl;
        }
        else
        {
            std::cout << "Successfully activated client '" << fIDClient << "'." << std::endl;
        }
    }

    return ret;
}
