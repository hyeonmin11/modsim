#ifndef __GENR_M_H__
#define __GENR_M_H__

#include <sstream>
#include "ATOMIC_MODELS.h"

#define GENR_NAME "GENR"

class GENR: public ATOMIC_MODELS
{
protected:
	STATE_VARS inter_arrival_time;


public:
	PORT* stop;
	PORT* out;

	GENR( string name );
	~GENR();

	void externalTransitionFunc( timetype e, CONTENT x );
	void internalTransitionFunc();
	CONTENT outputFunc();

};

#endif
