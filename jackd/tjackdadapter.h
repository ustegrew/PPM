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

#ifndef TJACKDADAPTER_H
#define TJACKDADAPTER_H

#include <iostream>
#include <jack/jack.h>
#include <jack/midiport.h>

class TJackDAdapter
{
    public:
        enum EStatus
        {
            kIsClosed,
            kIsOpen,
            kErrorFailedActivateClient,
            kErrorFailedOpenClient,
            kErrorFailedOpenPort,
            kErrorNoPortsAvailable
        };

    public:
                                            TJackDAdapter           (const char* idClient, const char* idInPortL, const char* idInPortR);
                                           ~TJackDAdapter           ();

         void                               Close                   ();
         EStatus                            GetStatus               ();
         bool                               Open                    ();

    private:
         static const jack_options_t        kOptionsClient = (jack_options_t) (JackNoStartServer | JackUseExactName);

         static int                         _CallbackProcess        (jack_nframes_t nFrames, void *arg);
         static void                        _CallbackShutdown       (void* arg);

    private:
         const char*                        fIDClient;
         const char*                        fIDPortL;
         const char*                        fIDPortR;

         jack_client_t*                     fObjClient;
         jack_port_t*                       fObjInputPortL;
         jack_port_t*                       fObjInputPortR;
         EStatus                            fStatus;
         jack_status_t                      fSysStatus;

         void                               _Close                  ();
         bool                               _Open                   ();
};

#endif // TJACKDADAPTER_H
