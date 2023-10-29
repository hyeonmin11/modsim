#include "PSK.m.h"

PSK::PSK( string name )
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
	processing_time = 10.0;
}

PSK::~PSK()
{
	delete out;
	delete in;
}

void PSK::externalTransitionFunc( timetype e, CONTENT x )
{
	if ( *in == x.getPort() )
	{
		if ( phase == "passive" )
		{
            cnt+=1;
			job_id = x.getValue();
			holdIn( "busy", STR_TO_DBL( processing_time.getV() ) );
		}
		else if ( phase == "busy" )
		{
            bool isEven = (++cnt % 2 == 0);
            if(!isEven){
                queue.addq( x.getValue() );
                Continue( e );
            }

		}
	}

    //Continue(e);
}

void PSK::internalTransitionFunc()
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

    //passivate();
}

CONTENT PSK::outputFunc()
{
	CONTENT y;
	string id = job_id.getV();

	if ( phase == "busy" )
		y.setContent( out, id );


    //y.setContent(out, "g1");
	return y;
}
