#pragma once
#include "DIGRAPH_MODELS.h"

#include "TRANSD.m.h"
#include "GENR.m.h"

#define EF_NAME "EF"

class EF : public DIGRAPH_MODELS
{
public:
	GENR	*genr;
	TRANSD	*transd;	

	PORT	*result;
	PORT	*in;
	PORT	*out;

	EF( string name );
	~EF();
};
