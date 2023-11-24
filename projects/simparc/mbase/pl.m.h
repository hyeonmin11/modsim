#ifndef __PL_M_H__
#define __PL_M_H__

#include "ATOMIC_MODELS.h"
#include "MACROS.h"

#define PL_NAME	"PL"

class PL: public ATOMIC_MODELS
{
protected: // state variables
	STATE_VARS job_id;
	STATE_VARS processing_time;

public:
	PORT*	in;
	PORT*	out;

	PL( string name );
	~PL();

	void		externalTransitionFunc( timetype e, CONTENT x );
	void		internalTransitionFunc();
	CONTENT		outputFunc();
};
#endif