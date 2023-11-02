
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
	stack("stack");
	

    sigma = INFINITY;
    phase = "passive";

	job_id = "-";
	stack = "-";
    
    processing_time = 10.0;

}

PS::~PS()
{
    delete out;
    delete in;
}

void PS::externalTransitionFunc(timetype e, CONTENT x)
{
	if ( phase == "passive" )
	{
		job_id = x.getValue();
		holdIn( "busy", STR_TO_DBL( processing_time.getV() ) );
	}
	else if ( phase == "busy" )
	{
		stack.addq( x.getValue() );
		//_stack.push( x.getValue());
		Continue( e );
	}
	
}

void PS::internalTransitionFunc()
{
	if ( phase == "busy" )
	{
		if ( stack.checkEmptyQueue() ) //_stack.empty()
			passivate();
		else
		{ //pop pop pop push push
			while(1){ // 1 2 3
				string job = stack.deleteq();
				if(stack.checkEmptyQueue()){
					job_id = job; // 3
					break;
				}
				else{
					_stack.push(job); // 1 2
				}
			}
			while(!_stack.empty()){
				stack.addq(_stack.front());
				_stack.pop();
			}

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
