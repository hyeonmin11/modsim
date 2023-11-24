#ifndef __PSM_M_H__
#define __PSM_M_H__

#include "ATOMIC_MODELS.h"
#include "MACROS.h"

#define PSM_NAME	"PSM"

class PSM: public ATOMIC_MODELS
{
protected: // state variables
	STATE_VARS job_id;
	STATE_VARS processing_time;

public:
	PORT*	in;
	PORT*	out;

	PSM( string name );
	~PSM();

	void		externalTransitionFunc( timetype e, CONTENT x );
	void		internalTransitionFunc();
	CONTENT		outputFunc();
};
#endif