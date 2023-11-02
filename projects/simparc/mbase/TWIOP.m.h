#ifndef __TWIOP_M_H__
#define __TWIOP_M_H__

#include "ATOMIC_MODELS.h"
#include "MACROS.h"

#define TWIOP_NAME "TWIOP"

class TWIOP: public ATOMIC_MODELS
{
    protected: 
        //STATE_VARS job_id;
        STATE_VARS processing_time1;
        STATE_VARS processing_time2;
        STATE_VARS processing_time3;
        STATE_VARS id_inport;  // -    << 공중에 띄워진 대시 쓰면 안된다;;

    public:
        PORT* in1;
        PORT* in2;
        PORT* out1;
        PORT* out2;
        

        TWIOP(string name);
        ~TWIOP();

        void externalTransitionFunc(timetype e, CONTENT x);
        void internalTransitionFunc();
        CONTENT outputFunc();
};
#endif 