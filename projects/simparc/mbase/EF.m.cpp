#include "EF.m.h"

EF::EF( string name )
{
	setName( name );

	genr = new GENR( GENR_NAME );
	transd = new TRANSD( TRANSD_NAME );

	addModel( genr );
	addModel( transd );

	in		= new PORT( "in" );
	result	= new PORT( "result" );
	out		= new PORT( "out" );

	addInport( *in );
	addOutport( *result );
	addOutport( *out );

	addCoupling( this, this->in, transd, transd->solved );
	addCoupling( genr, genr->out, this, this->out );
	addCoupling( transd, transd->out, this, this->result );
	addCoupling( transd, transd->out, genr, genr->stop );
	addCoupling( genr, genr->out, transd, transd->arrived );
}


EF::~EF()
{
	delete transd;
	delete genr;
	delete result;
	delete in;
	delete out;
}
