#ifndef __PQ_M_H__
#define __PQ_M_H__

#include "ATOMIC_MODELS.h"
#include "MACROS.h"

#define PQ_NAME	"PQ"

class PQ: public ATOMIC_MODELS
{
protected:
	STATE_VARS job_id;
	STATE_VARS queue;
	STATE_VARS processing_time;

public:
	PORT* in;
	PORT* out;

	PQ( string name );
	~PQ();

	void externalTransitionFunc( timetype e, CONTENT x );
	void internalTransitionFunc();
	CONTENT outputFunc();
	
};
#endif		//#ifndef __PQ_M_H__
