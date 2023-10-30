#ifndef __SCH_M_H__
#define __SCH_M_H__

#include "ATOMIC_MODELS.h"
#include "MACROS.h"

#define SCH_NAME	"SCH"

class SCH: public ATOMIC_MODELS
{
protected:
	STATE_VARS job_id;
	STATE_VARS temp;

	STATE_VARS processing_time_sleep;
    STATE_VARS processing_time_nap;
    STATE_VARS processing_time_walk;
    STATE_VARS processing_time_lecture;
    STATE_VARS processing_time_eat;
    STATE_VARS processing_time_study;
    STATE_VARS processing_time_workout;

	STATE_VARS time_remaining;
	STATE_VARS interrupt_handling_time;

public:
	PORT* assignment_left;
    PORT* feeling;
    PORT* day_finish;

    PORT* feeling_changed;
	PORT* out;
	PORT* message;

	SCH( string name );
	~SCH();

	void externalTransitionFunc( timetype e, CONTENT x );
	void internalTransitionFunc();
	CONTENT outputFunc();
	
};
#endif