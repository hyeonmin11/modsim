#pragma once
#include "digraph_models.h"

#include "pip_c.m.h"
#include "psm.m.h"

#define PIP_ARCH_NAME "PIP_ARCH"

class PIP_ARCH : public DIGRAPH_MODELS
{
public:
	PIP_C	*pip_c;
	PSM		*psm1;
	PSM		*psm2;
	PSM		*psm3;

	PORT	*in;
	PORT	*out;

	PIP_ARCH( string name );
	~PIP_ARCH();
};
