#ifndef __P_M_H__
#define __P_M_H__

#include "ATOMIC_MODELS.h"
#include "MACROS.h"

#define P_NAME	"P"

class P: public ATOMIC_MODELS
{
protected: // state variables
	STATE_VARS job_id;
	STATE_VARS processing_time;

public:
	PORT*	in;
	PORT*	out;

	P( string name );
	~P();

	void		externalTransitionFunc( timetype e, CONTENT x );
	void		internalTransitionFunc();
	CONTENT		outputFunc();
};
#endif
