#include "mul_arch.m.h"

MUL_ARCH::MUL_ARCH( string name )
{
	setName( name );

	mul_c	= new MUL_C( MUL_C_NAME );
	pl1		= new PL( "pl1" );
	pl2		= new PL( "pl2" );
	pl3		= new PL( "pl3" );

	addModel( mul_c );
	addModel( pl1 );
	addModel( pl2 );
	addModel( pl3 );

	in	= new PORT( "in" );
	out= new PORT( "out" );
	
	addOutport( *in );
	addOutport( *out );

	// External Input Coupling
	addCoupling( this, this->in, mul_c, mul_c->in );
	
	// External Output Coupling
	addCoupling( mul_c, mul_c->out, this, this->out );

	// Internal Coupling
	addCoupling( mul_c, mul_c->x1, pl1, pl1->in );
	addCoupling( pl1, pl1->out, mul_c, mul_c->y1 );
	addCoupling( mul_c, mul_c->x2, pl2, pl2->in );
	addCoupling( pl2, pl2->out, mul_c, mul_c->y2 );
	addCoupling( mul_c, mul_c->x3, pl3, pl3->in );
	addCoupling( pl3, pl3->out, mul_c, mul_c->y3 );
}


MUL_ARCH::~MUL_ARCH(void)
{
	delete mul_c;
	delete pl1;
	delete pl2;
	delete pl3;
	delete in;
	delete out;
}
