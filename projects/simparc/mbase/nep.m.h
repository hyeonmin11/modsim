#ifndef __NEP_M_H__
#define __NEP_M_H__

#include "ATOMIC_MODELS.h"
#include "MACROS.h"

#define NEP_NAME "NEP"

class NEP: public ATOMIC_MODELS
{
    protected:
        STATE_VARS job_id;
    
    public:
        PORT* out;
        NEP(string name);
        ~NEP();

        void internalTransitionFunc();
        CONTENT outputFunc();
};
#endif