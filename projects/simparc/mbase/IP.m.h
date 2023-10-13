#ifndef __IP_M_H__
#define __IP_M_H__

#include "ATOMIC_MODELS.h"
#include "MACROS.h"

#define IP_NAME	"IP"

class IP: public ATOMIC_MODELS
{
protected:
	STATE_VARS job_id;
	STATE_VARS temp;
	STATE_VARS processing_time;
	STATE_VARS time_remaining;
	STATE_VARS interrupt_handling_time;

public:
	PORT* in;
	PORT* out;
	PORT* message;

	IP( string name );
	~IP();

	void externalTransitionFunc( timetype e, CONTENT x );
	void internalTransitionFunc();
	CONTENT outputFunc();
	
};
#endif		//#ifndef __IP_M_H__
