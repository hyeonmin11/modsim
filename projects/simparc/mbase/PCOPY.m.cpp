#include "PCOPY.m.h"

PCOPY::PCOPY( string name )
{
	linkSimulator( name );

	in = new PORT( "in" );
	out = new PORT( "out" );

	addInport( *in );
	addOutport( *out );

	job_id( "job_id" );
	processing_time( "processing_time" );

	sigma = INFINITY;
	phase = "passive";
	job_id = "-";
	processing_time = 5.0;
}


PCOPY::~PCOPY()
{
	delete out;
	delete in;
}


void PCOPY::externalTransitionFunc( timetype e, CONTENT x )
{
	if ( *in == x.getPort() )
	{
		if ( phase == "passive" )
		{
			job_id = x.getValue();
			holdIn( "busy", STR_TO_DBL( processing_time.getV() ) );
		}
		else if ( phase == "busy" )
			Continue( e );
	}
}


void PCOPY::internalTransitionFunc()
{
	if ( phase == "busy" )
		passivate();
}


CONTENT PCOPY::outputFunc()
{
	CONTENT y;
	string id = job_id.getV();

	if ( phase == "busy" )
		y.setContent( out, id );

	return y;
}