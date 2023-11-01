#include "SCH.m.h"

SCH::SCH( string name )
{
	linkSimulator( name );

	in = new PORT( "in" );
    date = new PORT( "date" );
	feeling = new PORT( "feeling" );
	day_finish = new PORT( "day_finish" );

	out = new PORT( "out" );
	message = new PORT( "message" );

	addInport( *in );
    addInport( *date );
	addInport( *feeling );
	addInport( *day_finish );

	addOutport( *out );
	addOutport( *message );


	processing_time_wakeup("processing_time_wakeup");
	processing_time_mealtime("processing_time_mealtime");
	processing_time_lecture("processing_time_lecture");
	processing_time_nap("processing_time_nap");
	processing_time_workout("processing_time_workout");

	processing_time_wakeup = 0;
	processing_time_mealtime = 1.0;
	processing_time_lecture = 2.0;
	processing_time_nap = 1.0;
	processing_time_workout = 2.0;

	sigma = INFINITY;
	phase = "sleep";
	id_inport = "-";
	job_id = "-";
	temp = "-";
}

SCH::~SCH()
{
	delete in;
	delete date;
	delete feeling;
	delete day_finish;
	
	delete out;
	delete message;
}

void SCH::externalTransitionFunc( timetype e, CONTENT x )
{
    PORT* tempP = x.getPort();
    id_inport = (*tempP).getName();
    /*
	if ( *assignment_left == x.getPort() )
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

        //Continue(e);
	}
	else if ( *feeling == x.getPort() )
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

        //Continue(e);
	}
	else if ( *day_finish == x.getPort() )
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
        
        //Continue(e);
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

    //string id = job_id.getV();
    //y.setContent( out, id );

    /*

    if(id_inport == "feeling"){
        if( phase == "sleep" ){
            string id = "recharged";
            y.setContent(feeling_changed, id);
        }
    }
    else if(id_inport == "day_finish"){
        string id = "good night";
        y.setContent(out, id);
    }
    else if(id_inport == "assignment_left"){
        if(phase == ""){

        }
        else if(phase == "eat" || phase == "workout"){
            string id = "interuppted by " + phase.getV();
            y.setContent(y.setContent(message, id));
        }
    }
    */

    
	return y;
}