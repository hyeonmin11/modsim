#include "ip.m.h"

IP::IP( string name )
{
	linkSimulator( name );

	in = new PORT( "in" );
	out = new PORT( "out" );
	message = new PORT( "message" );

	addInport( *in );
	addOutport( *out );
	addOutport( *message );

	job_id( "job_id" );
	processing_time( "processing_time" );
	time_remaining( "time_remaining" );
	interrupt_handling_time( "interrupt_handling_time" );

	sigma = INFINITY;
	phase = "passive";

	job_id = "-";
	temp = "-";
	processing_time = 5.0;
	time_remaining = 0.0;
	interrupt_handling_time = 0.1;
}

IP::~IP()
{
	delete out;
	delete in;
	delete message;
}

void IP::externalTransitionFunc( timetype e, CONTENT x )
{
	if ( *in == x.getPort() )
	{
		if ( phase == "passive" )
		{
			job_id = x.getValue();
			time_remaining = processing_time;
			holdIn( "busy", STR_TO_DBL( processing_time.getV() ) );
		}
		else if ( phase == "busy" )
		{
			time_remaining = STR_TO_DBL( time_remaining.getV() ) - e;
			processing_time = 5.0;
			temp = x.getValue();
			holdIn( "INTERRUPTED", STR_TO_DBL( interrupt_handling_time.getV() ) );
		}
		else if ( phase == "INTERRUPTED" )
			Continue( e );
	}
}

void IP::internalTransitionFunc()
{
	if ( phase == "busy" )
		passivate();
	else if ( phase == "INTERRUPTED" )
		holdIn( "busy", STR_TO_DBL( time_remaining.getV() ) );
	else
		passivate();

}
CONTENT IP::outputFunc()
{
	CONTENT y;

	if ( phase == "busy" )
	{
		string id = job_id.getV();
		y.setContent( out, id );
	}
	else if ( phase == "INTERRUPTED" )
	{
		string id = "interrupted by " + temp.getV();
		y.setContent( message, id );
	}
	return y;
}
