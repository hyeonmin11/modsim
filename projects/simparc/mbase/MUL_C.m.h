#ifndef __MUL_C_M_H__
#define __MUL_C_M_H__

#include <queue>

#include "atomic_models.h"
#include "macros.h"

#define MUL_C_NAME "MUL_C"

class MUL_C : public ATOMIC_MODELS
{
protected:
	STATE_VARS	p1_s;
	STATE_VARS	p2_s;
	STATE_VARS	p3_s;
	STATE_VARS	out_port;
	STATE_VARS	job_id;

public:
	PORT*	in;
	PORT*	x1;
	PORT*	x2;
	PORT*	x3;
	PORT*	out;
	PORT*	y1;
	PORT*	y2;
	PORT*	y3;

	MUL_C(string name);
	~MUL_C();

	void	externalTransitionFunc(timetype e, CONTENT x);
	void	internalTransitionFunc();
	CONTENT	outputFunc();
};

#endif
