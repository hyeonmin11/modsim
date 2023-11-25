#include "pl.m.h"

PL::PL( string name )
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
	processing_time = rand()%4 + 6;
}


PL::~PL()
{
	delete out;
	delete in;
}


void PL::externalTransitionFunc( timetype e, CONTENT x )
{
	if ( *in == x.getPort() )
	{
		if ( phase == "passive" )
		{
			job_id = x.getValue();
			holdIn( "busy", STR_TO_DBL( processing_time.getV() ) );
		}
		else if ( phase == "busy" )
			Continue( e );
	}
}


void PL::internalTransitionFunc()
{
	if ( phase == "busy" )
		passivate();
}


CONTENT PL::outputFunc()
{
    //job_id = "g1 ( 90 8 7 32 18 21 56 87 4 7 2 7 4 1 66 )";
	CONTENT y;
	string id = job_id.getV();
    int numbers[15] = {}, encryptions[15] = {};   

    istringstream iss(id);
    ostringstream oss;  oss << "g1 ( ";
    char ch;    int num, index=0;

    while(iss >> ch && ch != '(');
    while(iss >> num && ch != ')'){
        numbers[index++] = num;
        if(index >= 15) break;
    }

    int encryption_key = 3;
    int modulo = 26;

    for(int i=0; i<15; i++){
        encryptions[i] = (numbers[i] + encryption_key) % modulo;
        oss << encryptions[i] << " ";
    }
    oss << ")";

    string res = oss.str();

	if ( phase == "busy" )
		y.setContent( out, res );

	return y;
}