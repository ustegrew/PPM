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
        };

    public:
                                            TJackDAdapter (const char* idClient, const char* idInPortL, const char* idInPortR);
                                           ~TJackDAdapter ();

         EStatus                            Open ();

    private:
         static const jack_options_t        kOptionsClient = (jack_options_t) (JackNoStartServer | JackUseExactName);

    private:
         const char*                        fIDClient;
         const char*                        fIDPortL;
         const char*                        fIDPortR;

         jack_client_t*                     fObjClient;
         jack_port_t*                       fObjInputPortL;
         jack_port_t*                       fObjInputPortR;
         jack_status_t                      fStatus;

         int                                Process (jack_nframes_t nFrames, void *arg);
};

#endif // TJACKDADAPTER_H
