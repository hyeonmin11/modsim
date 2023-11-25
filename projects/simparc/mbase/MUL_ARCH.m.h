#pragma once
#include "digraph_models.h"

#include "mul_c.m.h"
#include "pl.m.h"

#define MUL_ARCH_NAME "MUL_ARCH"

class MUL_ARCH : public DIGRAPH_MODELS
{
public:
	MUL_C	*mul_c;
	PL		*pl1;
	PL		*pl2;
	PL		*pl3;

	PORT	*in;
	PORT	*out;

	MUL_ARCH( string name );
	~MUL_ARCH();
};
