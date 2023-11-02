#ifndef __SCH_M_H__
#define __SCH_M_H__

#include "ATOMIC_MODELS.h"
#include "MACROS.h"

#define SCH_NAME	"SCH"

class SCH: public ATOMIC_MODELS
{
protected:
	STATE_VARS job_id; // this is for 'in' port
	//STATE_VARS temp;
	STATE_VARS date_id;
	STATE_VARS feeling_id;

	//string date_id;
	//string feeling_id;

	STATE_VARS processing_time_sleep;
	STATE_VARS processing_time_study;
	STATE_VARS processing_time_gohome;
	STATE_VARS processing_time_wakeup;
	STATE_VARS processing_time_mealtime;
	STATE_VARS processing_time_lecture;
    STATE_VARS processing_time_nap;
    STATE_VARS processing_time_workout;

public:
	PORT* in;
	PORT* date;
	PORT* breaktime;
    //PORT* feeling;
    PORT* day_finish;

	PORT* out;
	PORT* message;

	SCH( string name );
	~SCH();

	void externalTransitionFunc( timetype e, CONTENT x );
	void internalTransitionFunc();
	CONTENT outputFunc();
	string id_inport;
	
	
};
#endif