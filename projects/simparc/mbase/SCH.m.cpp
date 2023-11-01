#include "SCH.m.h"


SCH::SCH( string name )
{
	linkSimulator( name );

	in = new PORT( "in" );
    date = new PORT( "date" );
	breaktime = new PORT( "breaktime" );
	//feeling = new PORT( "feeling" );
	day_finish = new PORT( "day_finish" );

	out = new PORT( "out" );
	message = new PORT( "message" );

	addInport( *in );
    addInport( *date );
	addInport( *breaktime );
	//addInport( *feeling );
	addInport( *day_finish );

	addOutport( *out );
	addOutport( *message );

	processing_time_sleep("processing_time_sleep");
	processing_time_study("processing_time_study");
	processing_time_gohome("processing_time_gohome");
	processing_time_wakeup("processing_time_wakeup");
	processing_time_mealtime("processing_time_mealtime");
	processing_time_lecture("processing_time_lecture");
	processing_time_nap("processing_time_nap");
	processing_time_workout("processing_time_workout");

	processing_time_sleep = INFINITY;
	processing_time_study = INFINITY;
	processing_time_gohome = 0.0;
	processing_time_wakeup = 0.0;
	processing_time_mealtime = 1.0;
	processing_time_lecture = 2.0;
	processing_time_nap = 1.0;
	processing_time_workout = 2.0;

	sigma = INFINITY;
	phase = "sleep";
	id_inport = "-";

	job_id = "-";
	temp = "-";
	feeling_id = "-";
	date_id = "-";
}

SCH::~SCH()
{
	delete in;
	delete date;
	delete breaktime;
	//delete feeling;
	delete day_finish;
	
	delete out;
	delete message;
}

void SCH::externalTransitionFunc( timetype e, CONTENT x )
{
    PORT* tempP = x.getPort();
    id_inport = (*tempP).getName();

	if(id_inport == "in" ){
		if(job_id == "alarm"){
			Continue(e);
		}
		else if(job_id == "mealtime"){
			Continue(e);
		}
	}
	else if(id_inport == "date"){
		//Continue(e);
		if( job_id == "weekday" ){
			date_id = "weekday";
		}
		else{
			date_id = "weekend";
		}
	}
	else if(id_inport == "breaktime"){
		//Continue(e);
		if( job_id == "tired" ){
			holdIn("nap", STR_TO_DBL(processing_time_nap.getV()));
		}
		else if( job_id == "active" ){
			holdIn("workout", STR_TO_DBL(processing_time_workout.getV()));
		}
	}
	else if(id_inport == "day_finish"){
		//Continue(e);
		//sleep
		holdIn("gohome", STR_TO_DBL(processing_time_gohome.getV()));
	}


    //Continue(e);
}

void SCH::internalTransitionFunc()
{
    
	if ( phase == "gohome" )
		holdIn( "sleep", STR_TO_DBL(processing_time_sleep.getV()));
		//holdIn( "study", STR_TO_DBL(processing_time_study.getV()));
	else if ( phase == "nap" ){
		holdIn( "study", STR_TO_DBL(processing_time_study.getV()));
		feeling_id = "active";
	}
	else if ( phase == "workout"){
		holdIn( "study", STR_TO_DBL( processing_time_study.getV()));
		//passivate();
	}



    //passivate();
}
CONTENT SCH::outputFunc()
{
	CONTENT y;


	if(id_inport == "breaktime"){
		y.setContent(message, id_inport);
	}
	if(phase == "gohome"){
		y.setContent(out, "Gohome, shower and go to bed. Good night");
	}


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