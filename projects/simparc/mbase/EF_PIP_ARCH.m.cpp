#include "ef_pip_arch.m.h"

EF_PIP_ARCH::EF_PIP_ARCH( string name )
{
	setName( name );

	ef		 = new EF( EF_NAME );
	pip_arch = new PIP_ARCH( PIP_ARCH_NAME );
	
	addModel( ef );
	addModel( pip_arch );

	out = new PORT( "out" );
	addOutport( *out );

	// external coupling
	addCoupling( ef, ef->result, this, this->out );

	// internal coupling
	addCoupling( ef, ef->out, pip_arch, pip_arch->in );
	addCoupling( pip_arch, pip_arch->out, ef, ef->in );
}

EF_PIP_ARCH::~EF_PIP_ARCH()
{
	delete ef;
	delete pip_arch;
	delete out;
}