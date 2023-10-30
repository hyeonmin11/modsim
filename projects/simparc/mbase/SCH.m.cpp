#include "SCH.m.h"

SCH::SCH( string name )
{
	linkSimulator( name );

	feeling = new PORT( "feeling" );
	out = new PORT( "out" );
	message = new PORT( "message" );

	addInport( *feeling );
	addOutport( *out );
	addOutport( *message );

	assignment_left = new PORT( "assignment_left" );
	day_finish = new PORT( "day_finish" );
	feeling_changed = new PORT( "feeling_changed" );

	addInport( *assignment_left );
	addInport( *day_finish );
	addOutport( *feeling_changed );

	job_id( "job_id" );
	time_remaining( "time_remaining" );
	interrupt_handling_time( "interrupt_handling_time" );

    processing_time_sleep( "processing_time_sleep" );
    processing_time_nap( "processing_time_nap" );
    processing_time_walk( "processing_time_walk" );
    processing_time_lecture( "processing_time_lecture" );
    processing_time_eat( "processing_time_eat" );
    processing_time_study( "processing_time_study" );
    processing_time_workout( "processing_time_workout" );

	sigma = INFINITY;
	phase = "sleep";

	job_id = "-";
	temp = "-";
	time_remaining = 0.0;
	interrupt_handling_time = 0.1;

    processing_time_eat = 5.0;
    processing_time_lecture = 5.0;
    processing_time_nap = 5.0;
    processing_time_sleep = 5.0;
    processing_time_study = 5.0;
    processing_time_walk = 5.0;
    processing_time_workout = 5.0;

}

SCH::~SCH()
{
	delete day_finish;
	delete feeling;
	delete message;

	delete out;
	delete assignment_left;
	delete feeling_changed;
}

void SCH::externalTransitionFunc( timetype e, CONTENT x )
{
    /*
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
    */
    Continue(e);
}

void SCH::internalTransitionFunc()
{
    /*
	if ( phase == "busy" )
		passivate();
	else if ( phase == "INTERRUPTED" )
		holdIn( "busy", STR_TO_DBL( time_remaining.getV() ) );
	else
		passivate();
    */
    passivate();
}
CONTENT SCH::outputFunc()
{
	CONTENT y;

    string id = job_id.getV();
    y.setContent( out, id );
    
    /*
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
    */
	return y;
}