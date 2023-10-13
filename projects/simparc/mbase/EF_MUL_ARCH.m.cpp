#include "ef_mul_arch.m.h"

EF_MUL_ARCH::EF_MUL_ARCH( string name )
{
	setName( name );

	ef		 = new EF( EF_NAME );
	mul_arch = new MUL_ARCH( MUL_ARCH_NAME );
	
	addModel( ef );
	addModel( mul_arch );

	out = new PORT( "out" );
	addOutport( *out );

	// external coupling
	addCoupling( ef, ef->result, this, this->out );

	// internal coupling
	addCoupling( ef, ef->out, mul_arch, mul_arch->in );
	addCoupling( mul_arch, mul_arch->out, ef, ef->in );
}

EF_MUL_ARCH::~EF_MUL_ARCH()
{
	delete ef;
	delete mul_arch;
	delete out;
}
