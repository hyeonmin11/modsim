#include "pd.m.h"

PD::PD( string name )
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
	processing_time = rand()%2 + 2;
}


PD::~PD()
{
	delete out;
	delete in;
}


void PD::externalTransitionFunc( timetype e, CONTENT x )
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


void PD::internalTransitionFunc()
{
	if ( phase == "busy" )
		passivate();
}


CONTENT PD::outputFunc()
{
    job_id = "g1 ( 90 8 7 32 18 21 56 87 4 7 2 7 4 1 66 )";
	CONTENT y;
	string id = job_id.getV();

    std::vector<int> numbers;
    istringstream iss(id); char ch;    int num;
    ostringstream oss;

    while(iss >> ch && ch != '(');
    while(iss >> num){
        numbers.push_back(num);
    }

    for(size_t i =0; i<numbers.size(); i++){
        if(i%5 == 0){
            if(i>0){
                oss << ") ) ";
            }
            oss << "(g1 (";
        }
        else{
            oss << " ";
        }
        oss << numbers[i];
    }
    oss << ") )";

    //cout << oss.str() << endl;
    string res = oss.str();


	if ( phase == "busy" )
		y.setContent( out, res );

	return y;
}