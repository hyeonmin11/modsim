#include "transd.m.h"
#include<list>

TRANSD::TRANSD( string name )
{
	linkSimulator( name );

	solved = new PORT( "solved" );
	arrived = new PORT( "arrived" );
	out = new PORT( "out" );

	addInport( *solved );
	addInport( *arrived );
	addOutport( *out );

	observation_interval = 100;

	arrived_list( "arrived_list" );
	solved_list( "solved_list" );
	clock( "clock" );
	total_ta( "total_ta" );

	sigma = observation_interval;
	phase = "active";
	arrived_list = "-";
	solved_list = "-";
	clock = 0.0;
	total_ta = 0.0;

	srand(1);
}


TRANSD::~TRANSD( void )
{
	delete solved;
	delete arrived;
	delete out;
}


void TRANSD::externalTransitionFunc( timetype e, CONTENT x )
{
	string problem_id = x.getValue();
	clock = STR_TO_DBL( clock.getV() ) + e;
	double time = STR_TO_DBL( clock.getV() );

	if( *arrived == x.getPort() )
	{
		list_arrived.insert( pair<string, double>( problem_id, time ) );
		arrived_list = convertListToString( list_arrived );
	}
	else if( *solved == x.getPort() )
	{
		double prob_arrival_time = getArrivalTime( problem_id );
		double turn_around_time = time - prob_arrival_time;

		if ( prob_arrival_time != ERR_NUM )
		{
			total_ta = STR_TO_DBL( total_ta.getV() ) + turn_around_time;
			list_solved.insert( pair<string, double>( problem_id, time ) );
			solved_list = convertListToString( list_solved );
		}
	}

	Continue( e );
}

// internal transition function
void TRANSD::internalTransitionFunc()
{
	if ( phase == "active" )
	{
		passivate();
	}
}

// output function
CONTENT TRANSD::outputFunc()
{
	CONTENT content;
	string value;

	timetype avg_ta_time = 0.;
	timetype throughput = 0.0;
	timetype time = STR_TO_DBL( clock.getV() );

	if( phase == "active" )
	{
		if ( !list_solved.empty() )
			avg_ta_time = STR_TO_DBL( total_ta.getV() ) / list_solved.size();

		if ( time != 0 )
			throughput = ( list_solved.size() - 1 ) / time ;

		cout << "Avg. turnaround time: " << avg_ta_time << endl;
		cout << "ThruPut: " << throughput << endl;

		value = TIME_TO_STR( avg_ta_time );

		content.setContent( out, value );
	}

	writeLog();

	return content;
}


double TRANSD::getArrivalTime( string id )
{
	double result = list_arrived[id];

	if ( result < 0 )
		return ERR_NUM;

	return result;
}


string TRANSD::convertListToString( List list )
{
	string list_string = "";
	List::iterator iter;

	for( iter = list.begin(); iter != list.end(); iter++ )
	{
		list_string += "(";
		list_string += iter->first;
		list_string += " ";
		list_string += TIME_TO_STR( iter->second );
		list_string += ")";
	}

	return list_string;
}

void TRANSD::writeLog()
{
	string file_name;
	ofstream log;
	timetype throughput;
	timetype avg_ta_time = 0;

	if( !list_solved.empty() )
	{
		avg_ta_time = STR_TO_DBL( total_ta.getV() ) / list_solved.size();
		throughput = list_solved.size() / STR_TO_DBL( clock.getV() );
	}
	else
		throughput = 0;

	if( file_name.length() == 0 )
	{
		file_name.append( ".\\" );
		file_name.append( "Log.txt" );
	}
	log.open( file_name, ios::trunc );

	log << "The arrived list: ";
	log << convertListToString( list_arrived ) << endl << endl;
	log << "The solved list: ";
	log << convertListToString( list_solved ) << endl << endl;
	log << "Avg. turnaround time: ";
	log << TIME_TO_STR( avg_ta_time ) << endl << endl;
	log << "ThruPut:";
	log << TIME_TO_STR( throughput ) << endl;
	log.close();
}
