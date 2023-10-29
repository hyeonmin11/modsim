#ifndef __PCOPY_M_H__
#define __PCOPY_M_H__

#include "ATOMIC_MODELS.h"
#include "MACROS.h"

#define PCOPY_NAME	"PCOPY"

class PCOPY: public ATOMIC_MODELS
{
protected: // state variables
	STATE_VARS job_id;
	STATE_VARS processing_time;

public:
	PORT*	in;
	PORT*	out;

	PCOPY( string name );
	~PCOPY();

	void		externalTransitionFunc( timetype e, CONTENT x );
	void		internalTransitionFunc();
	CONTENT		outputFunc();
};
#endif