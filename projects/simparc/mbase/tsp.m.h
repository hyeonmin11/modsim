#ifndef __TSP_M_H__
#define __TSP_M_H__

#include "ATOMIC_MODELS.h"
#include "MACROS.h"

#define TSP_NAME "TSP"

class TSP: public ATOMIC_MODELS
{
    protected: 
        STATE_VARS job_id;
        STATE_VARS processing_time1;
        STATE_VARS processing_time2;
        STATE_VARS processing_time3;
    
    public:
        PORT* in;
        PORT* out1;
        PORT* out2;

        TSP(string name);
        ~TSP();

        void externalTransitionFunc();
        void internalTransitionFunc();
        CONTENT outputFunc();
};
#endif 