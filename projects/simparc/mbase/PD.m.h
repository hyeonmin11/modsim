#ifndef __PD_M_H__
#define __PD_M_H__

#include "ATOMIC_MODELS.h"
#include "MACROS.h"

#define PD_NAME	"PD"

class PD: public ATOMIC_MODELS
{
protected: // state variables
	STATE_VARS job_id;
	STATE_VARS processing_time;

public:
	PORT*	in;
	PORT*	out;

	PD( string name );
	~PD();

	void		externalTransitionFunc( timetype e, CONTENT x );
	void		internalTransitionFunc();
	CONTENT		outputFunc();
};
#endif