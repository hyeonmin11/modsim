/*
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

}

void PS::internalTransitionFunc()
{

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
*/