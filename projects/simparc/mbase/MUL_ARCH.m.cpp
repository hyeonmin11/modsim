#include "mul_arch.m.h"

MUL_ARCH::MUL_ARCH( string name )
{
	setName( name );

	mul_c	= new MUL_C( MUL_C_NAME );
	p1		= new P( "P1" );
	p2		= new P( "P2" );
	p3		= new P( "P3" );

	addModel( mul_c );
	addModel( p1 );
	addModel( p2 );
	addModel( p3 );

	in	= new PORT( "in" );
	out= new PORT( "out" );
	
	addOutport( *in );
	addOutport( *out );

	// External Input Coupling
	addCoupling( this, this->in, mul_c, mul_c->in );
	
	// External Output Coupling
	addCoupling( mul_c, mul_c->out, this, this->out );

	// Internal Coupling
	addCoupling( mul_c, mul_c->x1, p1, p1->in );
	addCoupling( p1, p1->out, mul_c, mul_c->y1 );
	addCoupling( mul_c, mul_c->x2, p2, p2->in );
	addCoupling( p2, p2->out, mul_c, mul_c->y2 );
	addCoupling( mul_c, mul_c->x3, p3, p3->in );
	addCoupling( p3, p3->out, mul_c, mul_c->y3 );
}


MUL_ARCH::~MUL_ARCH(void)
{
	delete mul_c;
	delete p1;
	delete p2;
	delete p3;
	delete in;
	delete out;
}
