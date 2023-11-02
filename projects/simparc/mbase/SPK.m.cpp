#include "SPK.m.h"




SPK::SPK( string name )
{
	linkSimulator( name );

	in_a = new PORT( "in_a" );
    in_b = new PORT( "in_b" );
	out = new PORT( "out" );

	addInport( *in_a );
    addInport( *in_b );
	addOutport( *out );

	kick_type_( "kick_type_" );
	processing_time( "processing_time" );
    winner("winner");
    //score("score");

    id_inport = "-";

	sigma = INFINITY;
	phase = "passive";
	kick_type_ = "-";
	processing_time = 1.0;
    winner = "none";
    //score = winner.getV() + ", " + Ascore + " : " + Bscore;

    srand(1);
}


SPK::~SPK()
{
	delete out;
	delete in_a;
    delete in_b;
}


void SPK::externalTransitionFunc( timetype e, CONTENT x )
{
    


    if ( phase == "passive" )
    {
        PORT* temp = x.getPort();
        id_inport = (*temp).getName();

        kick_type_ = x.getValue();
        holdIn( "kick", STR_TO_DBL( processing_time.getV() ) );
    }
    else if ( phase == "kick" )
        Continue( e );
	
	
    
    //Continue(e);
}


void SPK::internalTransitionFunc()
{
    
	if ( phase == "kick" )
		passivate();
   
    //passivate();
}


CONTENT SPK::outputFunc()
{
	CONTENT y;
	string kick_type = kick_type_.getV();
    string goalOrngoal;
    //srand(1);

    if(kick_type == "fz"){
        goalOrngoal = (rand() < RAND_MAX * 0.5) ? "goal" : "no-goal";
    }
    else if(kick_type == "sz"){
        goalOrngoal = (rand() < RAND_MAX * 0.3) ? "goal" : "no-goal";
    }
    else if(kick_type == "foz"){
        goalOrngoal = "no-goal";
    }
    else if(kick_type == "soz"){
        goalOrngoal = "no-goal";
    }
    
    
    if(id_inport == "in_a"){
        if(goalOrngoal == "goal"){
            Ascore += 1;
            if (Ascore == 5) { winner = "a"; }
        }
    }
    else{
        if(goalOrngoal == "goal"){
            Bscore += 1;
            if (Bscore == 5) { winner = "b"; }
        }
    }
    
    y.setContent( out,  winner.getV() + ", a=" + to_string(Ascore) + " : b=" + to_string(Bscore));

	return y;
}