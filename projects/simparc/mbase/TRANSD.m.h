#ifndef __TRANSD_M_H__
#define __TRANSD_M_H__

#include <fstream>
#include <map>

#include "ATOMIC_MODELS.h"
#include "MACROS.h"

#define TRANSD_NAME "TRANSD"

typedef map<string, double> List;

class TRANSD: public ATOMIC_MODELS
{
private:
	List	list_arrived;
	List	list_solved;

public:
	timetype		observation_interval;
	STATE_VARS		arrived_list;
	STATE_VARS		solved_list;
	STATE_VARS		clock;
	STATE_VARS		total_ta;

public:
	PORT*		solved;
	PORT*		arrived;
	PORT*		out;

	TRANSD( string name );
	~TRANSD();

	void externalTransitionFunc( timetype e, CONTENT x );
	void internalTransitionFunc();
	CONTENT outputFunc();

	double getArrivalTime( string id );
	string convertListToString( List list );
	void writeLog();
};

#endif
