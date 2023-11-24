#pragma once
#include "digraph_models.h"

#include "mul_c.m.h"
#include "p.m.h"

#define MUL_ARCH_NAME "MUL_ARCH"

class MUL_ARCH : public DIGRAPH_MODELS
{
public:
	MUL_C	*mul_c;
	P		*p1;
	P		*p2;
	P		*p3;

	PORT	*in;
	PORT	*out;

	MUL_ARCH( string name );
	~MUL_ARCH();
};
