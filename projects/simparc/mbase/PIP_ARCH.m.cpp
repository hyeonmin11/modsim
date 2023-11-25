#include "pip_arch.m.h"

PIP_ARCH::PIP_ARCH( string name )
{
	setName( name );

	pip_c	= new PIP_C( PIP_C_NAME );
	psm1		= new PSM( "psm1" );
	psm2		= new PSM( "psm2" );
	psm3		= new PSM( "psm3" );

	addModel( pip_c );
	addModel( psm1 );
	addModel( psm2 );
	addModel( psm3 );

	in	= new PORT( "in" );
	out= new PORT( "out" );
	
	addOutport( *in );
	addOutport( *out );

	// External Input Coupling
	addCoupling( this, this->in, pip_c, pip_c->in );
	
	// External Output Coupling
	addCoupling( pip_c, pip_c->out, this, this->out );

	// Internal Coupling
	addCoupling( pip_c, pip_c->x1, psm1, psm1->in );
	addCoupling( psm1, psm1->out, pip_c, pip_c->y1 );
	addCoupling( pip_c, pip_c->x2, psm2, psm2->in );
	addCoupling( psm2, psm2->out, pip_c, pip_c->y2 );
	addCoupling( pip_c, pip_c->x3, psm3, psm3->in );
	addCoupling( psm3, psm3->out, pip_c, pip_c->y3 );
}


PIP_ARCH::~PIP_ARCH(void)
{
	delete pip_c;
	delete psm1;
	delete psm2;
	delete psm3;
	delete in;
	delete out;
}
