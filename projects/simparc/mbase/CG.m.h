#ifndef __CG_M_H__ 
#define __CG_M_H__

#include "ATOMIC_MODELS.h"
#include "MACROS.h"

#define CG_NAME "CG"

class CG: public ATOMIC_MODELS
{
    protected: 
        //STATE_VARS job_id;
        STATE_VARS processing_time1;
        STATE_VARS processing_time2;

    public:
        PORT* stop;
        PORT* out1;
        PORT* out2;

        CG(string name);
        ~CG();

        void externalTransitionFunc(timetype e, CONTENT x);
        void internalTransitionFunc();
        CONTENT outputFunc();
};
#endif 