#ifndef __PQ_M_H__
#define __PQ_M_H__

#include "ATOMIC_MODELS.h"
#include "MACROS.h"

#define PSK_NAME	"PSK"

class PSK: public ATOMIC_MODELS
{
protected:
	STATE_VARS job_id;
	STATE_VARS queue;
	STATE_VARS processing_time;

public:
	PORT* in;
	PORT* out;

	PSK( string name );
	~PSK();

	void externalTransitionFunc( timetype e, CONTENT x );
	void internalTransitionFunc();
	CONTENT outputFunc();
	int cnt = 0;
};
#endif