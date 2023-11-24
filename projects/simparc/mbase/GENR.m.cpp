#include "GENR.m.h"

GENR::GENR( string name )
{
	linkSimulator( name );

	stop = new PORT( "stop" );
	out = new PORT( "out" );

	addInport( *stop );
	addOutport( *out );

	inter_arrival_time( "inter_arrival_time" );

	sigma = 0;
	phase = "active";
	inter_arrival_time = 10;

	inputarr[15] = {};
	count = 1;
	
	holdIn( "active", STR_TO_DBL( sigma.getV() ) );
}


GENR::~GENR()
{
	delete out;
	delete stop;
}


void GENR::externalTransitionFunc( timetype e, CONTENT x )
{
	if ( *stop == x.getPort() )
		passivate();
	else
		Continue( e );
}

void GENR::internalTransitionFunc()
{
	if ( phase == "active" )
		holdIn( "active", STR_TO_DBL( inter_arrival_time.getV() ) );
}

string GENR::gensym()
{
	stringstream st;

	st << "g1 ";

	for(int i=0; i < 15; i++){
		inputarr[i] = rand() % 100;
	}

	for(int i=0; i < 15; i++){

		if(i==0){
			st << "( ";
		}
		st << inputarr[i] << " ";
		if(i==14){
			st << ")";
		}
	}
	//st << count++;

	return st.str();
}


CONTENT GENR::outputFunc()
{
	CONTENT y;

	if ( phase == "active" )
		y.setContent( out, gensym());

	return y;
}

