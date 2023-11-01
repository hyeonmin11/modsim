
#include "ps.m.h"

PS::PS( string name )
{
    linkSimulator( name );

    in = new PORT(" in ");
    out = new PORT(" out ");

    addInport(*in);
    addOutport(*out);

    job_id("job_id");
    processing_time("processing_time");

    sigma = INFINITY;
    phase = "passive";

    job_id = "-";
    processing_time = 10.0;

}

PS::~PS()
{
    delete out;
    delete in;
}

void PS::externalTransitionFunc(timetype e, CONTENT x)
{
	if ( *in == x.getPort() )
	{
		if ( phase == "passive" )
		{
			job_id = x.getValue();
			holdIn( "busy", STR_TO_DBL( processing_time.getV() ) );
		}
		else if ( phase == "busy" )
		{
			_stack.push( x.getValue() );
			Continue( e );
		}
	}
}

void PS::internalTransitionFunc()
{
	if ( phase == "busy" )
	{
		if ( 1 ) //_stack.empty()
			passivate();
		else
		{
			job_id = _stack.top();
            _stack.pop();
			holdIn( "busy", STR_TO_DBL( processing_time.getV() ) );
		}
	}
}

CONTENT PS::outputFunc()
{
    CONTENT y;
    string id = job_id.getV();

    if(phase == "busy"){
        y.setContent(out, id);
    }

    return y;
}
