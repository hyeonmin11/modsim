#ifndef __SIO_M_H__
#define __SIO_M_H__

#include "ATOMIC_MODELS.h"
#include "MACROS.h"

#define SIO_NAME	"SIO"

class SIO: public ATOMIC_MODELS
{
protected: // state variables
	STATE_VARS job_id;
	STATE_VARS processing_time;
    STATE_VARS processing_time0;

public:
	PORT*	in1;
    PORT*   in2;
	PORT*	out;

	SIO( string name );
	~SIO();

	void		externalTransitionFunc( timetype e, CONTENT x );
	void		internalTransitionFunc();
	CONTENT		outputFunc();
};
#endif