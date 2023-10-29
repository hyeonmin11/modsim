#include "SIO.m.h"

SIO::SIO( string name )
{
	linkSimulator( name );

	in1 = new PORT( "in1" );
    in2 = new PORT( "in2" );
	out = new PORT( "out" );

	addInport( *in1 );
    addInport( *in2 );
	addOutport( *out );

	job_id( "job_id" );
	processing_time( "processing_time" );
    processing_time0( "processing_time0");
	sigma = INFINITY;
	phase = "passive";
	job_id = "-";
	processing_time = 5.0;
    processing_time0 = 0.0;
}


SIO::~SIO()
{
	delete out;
	delete in1;
    delete in2;
}


void SIO::externalTransitionFunc( timetype e, CONTENT x )
{
    

    if ( phase == "passive" )
    {
        job_id = x.getValue();

        PORT* temp = x.getPort();
        string id_inport = (*temp).getName();
        if(id_inport == "in1"){
            holdIn( "temporary", STR_TO_DBL( processing_time0.getV() ) );
        }
        else{
            holdIn( "busy", STR_TO_DBL( processing_time.getV() ) );
        }
        
    }
    else if ( phase == "busy" )
        Continue( e );
	
    
    //Continue(e);
}


void SIO::internalTransitionFunc()
{
    
	if ( phase == "busy" )
		passivate();
    else if(phase == "temporary"){
        holdIn( "busy", STR_TO_DBL( processing_time.getV() ) );
    }
    
    //passivate();
}


CONTENT SIO::outputFunc()
{
	CONTENT y;
	string id = job_id.getV();

    
	if ( phase == "busy" || phase == "temporary")
		y.setContent( out, id );
    
    //y.setContent( out, id );
	return y;
}