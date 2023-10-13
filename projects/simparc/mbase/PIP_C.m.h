#pragma once
#ifndef __PIP_C_M_H__
#define __PIP_C_M_H__

#include <queue>

#include "atomic_models.h"
#include "macros.h"

#define PIP_C_NAME "PIP_C"

class PIP_C : public ATOMIC_MODELS
{
protected:
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

	PIP_C(string name);
	~PIP_C();

	void	externalTransitionFunc(timetype e, CONTENT x);
	void	internalTransitionFunc();
	CONTENT	outputFunc();
};

#endif
