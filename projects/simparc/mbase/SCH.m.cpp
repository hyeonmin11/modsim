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

	sigma = INFINITY;
	phase = "sleep";
	id_inport = "-";


	job_id("job_id");
	feeling_id("feeling_id");
	date_id("date_id");
	job_id = "-";
	//temp = "-";
	feeling_id = "-";
	date_id = "-";

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
	printf("%s", job_id);
	if(id_inport == "in" ){
		if(job_id == "alarm"){
			//Continue(e);
			holdIn("wakeup", STR_TO_DBL(processing_time_wakeup.getV()));
		}
		else if(job_id == "mealtime2"){
			//Continue(e);
			// this is only for weekday and for lunch, dinner and snack. not for breakfast
			holdIn( "mealtime2", STR_TO_DBL( processing_time_mealtime.getV()));
		}
	}
	else if(id_inport == "date"){
		//Continue(e);
		if( job_id == "weekday" ){
			date_id = "weekday";
		}
		else if( job_id == "weekend") {
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
    
	if( date_id == "weekday" ){

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
		else if ( phase == "wakeup" ){
			holdIn( "mealtime", STR_TO_DBL( processing_time_mealtime.getV()));
		}
		else if ( phase == "mealtime" ){ // this is for breakfast
			holdIn( "lecture", STR_TO_DBL( processing_time_lecture.getV()));
		}
		else if ( phase == "mealtime2" ){ // this is for lunch dinner and snack
			holdIn( "study", STR_TO_DBL( processing_time_study.getV()));
		}
		else if ( phase == "lecture"){
			holdIn( "study", STR_TO_DBL( processing_time_study.getV()));
		}
	}
	else if( date_id == "weekend"){
		if( phase == "mealtime"){
			holdIn( "sleep", STR_TO_DBL( processing_time_sleep.getV()));
		}
		else if ( phase == "sleep"){
			holdIn( "wakeup", STR_TO_DBL( processing_time_wakeup.getV()));
		}
		else if ( phase == "wakeup" ){
			holdIn( "mealtime", STR_TO_DBL( processing_time_mealtime.getV()));
		}
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
		y.setContent(out, " Gohome, shower and go to bed. Good night");
	}
	if(phase == "wakeup"){
		y.setContent(out, " sleep");
	}
	if(phase == "mealtime"){
		y.setContent(out, " stuffed");
	}
    
	return y;
}