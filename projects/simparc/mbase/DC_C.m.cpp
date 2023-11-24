#include "DC_C.m.h"

DC_C::DC_C( string name )
{
	linkSimulator( name );

	in = new PORT( "in" );
	out = new PORT( "out" );
	px = new PORT( "px" );
	py = new PORT( "py" );
	cx = new PORT( "cx" );
	cy = new PORT( "cy" );
	x1 = new PORT( "x1" );
	y1 = new PORT( "y1" );
	x2 = new PORT( "x2" );
	y2 = new PORT( "y2" );
	x3 = new PORT( "x3" );
	y3 = new PORT( "y3" );


	addInport( *in );
	addInport( *py );
	addInport( *y1 );
	addInport( *y2 );
	addInport( *y3 );
	addInport( *cy );
	addOutport( *out );
	addOutport( *px );
	addOutport( *x1 );
	addOutport( *x2 );
	addOutport( *x3 );
	addOutport( *cx );	

	job_id( "job_id" );
	out_port( "out_port" );
	p_cnt("p_cnt");
	
	sigma = INFINITY;
	phase = "passive";
	job_id = "-";
	out_port = "-";
	p_cnt = 3; //count of free processors
}


DC_C::~DC_C()
{
	delete in;
	delete out;
	delete px; 
	delete py;
	delete cx;
	delete cy;
	delete x1;
	delete y1;
	delete x2;
	delete y2;
	delete x3;
	delete y3;
}


void DC_C::externalTransitionFunc( timetype e, CONTENT x )
{
	job_id = x.getValue();
	
	if ( *in == x.getPort() ) 	// case 1. arrival of a problem
	{
		out_port = "px" ;		// Always send to partition processor
	}
	else if ( *py == x.getPort() )	// case 2. input from partition processor 
	{
		out_port = "xin";
	}
	else if ( *y1 == x.getPort() || *y2 == x.getPort() || *y3 == x.getPort()) // case 3. input from partial solution processors
	{
		p_cnt = STR_TO_INT(p_cnt.getValue())+1;
		if (STR_TO_INT(p_cnt.getValue()) == 3)
			out_port = "cx";
	}
	else if ( *cy == x.getPort() )
	{
		out_port = "out";
	}
	holdIn( "busy", 0 );
	
}


void DC_C::internalTransitionFunc()
{
	if ( phase == "busy" )
		passivate();
}


CONTENT DC_C::outputFunc()
{
	CONTENT y;
	string id = job_id.getV();
	string id2 = "hey";
	string id3 = "bye";

	if ( phase == "busy" )
		if (out_port == "xin") {
			if (STR_TO_INT(p_cnt.getValue()) == 3)
			{
				p_cnt = 0;
				y.setContent(x1, id);
				y.setContent(x2, id2);
				y.setContent(x3, id3);

			}
		}
		else if(out_port =="px")
		{
			y.setContent(px, id);
		}
		else if (out_port == "cx")
		{
			y.setContent(cx, id);
		}
		else if (out_port == "out")
		{
			y.setContent(out, id);
		}

	return y;
}
