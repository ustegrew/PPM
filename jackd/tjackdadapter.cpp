#include "tjackdadapter.h"

TJackDAdapter::TJackDAdapter (const char* idClient, const char* idInPortL, const char* idInPortR)
{
    fIDClient               = idClient;
    fIDPortL                = idInPortL;
    fIDPortR                = idInPortR;
}

TJackDAdapter::~TJackDAdapter ()
{

}

TJackDAdapter::EStatus TJackDAdapter::Open ()
{
    fObjClient = jack_client_open (fIDClient, kOptionsClient, &fStatus, NULL);
    if (fObjClient == NULL)
    {
        std::cerr << "jack_client_open() failed. Status=" << fStatus;
    }
}
