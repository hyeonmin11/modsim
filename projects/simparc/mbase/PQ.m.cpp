#include "pq.m.h"

PQ::PQ( string name )
{
	linkSimulator( name );

	in = new PORT( "in" );
	out = new PORT( "out" );

	addInport( *in );
	addOutport( *out );

	job_id( "job_id" );
	processing_time( "processing_time" );
	queue("queue");
	sigma = INFINITY;
	phase = "passive";
	
	job_id = "-";
	queue = "-";
	processing_time = 10.0;
}

PQ::~PQ()
{
	delete out;
	delete in;
}

void PQ::externalTransitionFunc( timetype e, CONTENT x )
{
	if ( *in == x.getPort() )
	{
		if ( phase == "passive" )
		{
			job_id = x.getValue();
			holdIn( "busy", STR_TO_DBL( processing_time.getV() ) );
		}
		else if ( phase == "busy" )
		{
			queue.addq( x.getValue() );
			Continue( e );
		}
	}
}

void PQ::internalTransitionFunc()
{
	if ( phase == "busy" )
	{
		if ( queue.checkEmptyQueue() )
			passivate();
		else
		{
			job_id = queue.deleteq();
			holdIn( "busy", STR_TO_DBL( processing_time.getV() ) );
		}
	}
}

CONTENT PQ::outputFunc()
{
	CONTENT y;
	string id = job_id.getV();

	if ( phase == "busy" )
		y.setContent( out, id );

	return y;
}
