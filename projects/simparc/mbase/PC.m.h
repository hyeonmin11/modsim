#ifndef __PC_M_H__
#define __PC_M_H__

#include "ATOMIC_MODELS.h"
#include "MACROS.h"

#define PC_NAME	"PC"

class PC: public ATOMIC_MODELS
{
protected: // state variables
	STATE_VARS job_id;
	STATE_VARS processing_time;

public:
	PORT*	in;
	PORT*	out;

	PC( string name );
	~PC();

	void		externalTransitionFunc( timetype e, CONTENT x );
	void		internalTransitionFunc();
	CONTENT		outputFunc();
};
#endif