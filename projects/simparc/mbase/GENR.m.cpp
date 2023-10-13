#include "GENR.m.h"

GENR::GENR( string name )
{
	linkSimulator( name );

	stop = new PORT( "stop" );
	out = new PORT( "out" );

	addInport( *stop );
	addOutport( *out );

	inter_arrival_time( "inter_arrival_time" );

	sigma = 0;
	phase = "active";
	inter_arrival_time = 5;

	holdIn( "active", STR_TO_DBL( sigma.getV() ) );
}


GENR::~GENR()
{
	delete out;
	delete stop;
}


void GENR::externalTransitionFunc( timetype e, CONTENT x )
{
	if ( *stop == x.getPort() )
		passivate();
	else
		Continue( e );
}

void GENR::internalTransitionFunc()
{
	if ( phase == "active" )
		holdIn( "active", STR_TO_DBL( inter_arrival_time.getV() ) );
}

CONTENT GENR::outputFunc()
{
	CONTENT y;

	if ( phase == "active" )
		y.setContent( out, gensym());

	return y;
}

