#ifndef __PS_M_H__
#define __PS_M_H__

#include "ATOMIC_MODELS.h"
#include "MACROS.h"

#define PS_NAME "PS"

class PS: public ATOMIC_MODELS
{
    protected:
        STATE_VARS job_id;
        STATE_VARS stack;
        STATE_VARS processing_time;
    
    public:
        PORT* in;
        PORT* out;

        PS(string name);
        ~PS();

        void externalTransitionFunc( timetype e, CONTENT x);
        void internalTransitionFunc();
        CONTENT outputFunc();
};
#endif