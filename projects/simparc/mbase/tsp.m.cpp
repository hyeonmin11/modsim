#include "TSP.m.h"

TSP::TSP(string name)
{
    linkSimulator(name);

    in = new PORT("in");
    out1 = new PORT("out1");
    out2 = new PORT("out2");

    addInport(*in);
    addOutport(*out1);
    addOutport(*out2);

    job_id("job_id"); //  cannot understand
    processing_time1("processing_time1"); // cannot understand
    processing_time2("processing_time2");
    processing_time3("processing_time3");
    sigma = INFINITY;
    phase = "passive";

    job_id = "-";
    processing_time1 = 2.0;
    processing_time2 = 2.4;
    processing_time3 = 2.5;

}

TSP::~TSP()
{
    delete out1;
    delete out2;
    delete in;
}

void TSP::externalTransitionFunc(timetype e, CONTENT x)
{
    if (*in == x.getPort())
    {
        if(phase == "passive")
        {
            job_id = x.getValue();
            holdIn("busy1", STR_TO_DBL(processing_time1.getV()));
        }
        else{
            Continue(e);
        }
    }
}

void TSP::internalTransitionFunc()
{
    
    if (phase == "busy1"){
        holdIn("busy2", STR_TO_DBL(processing_time2.getV()));
    }
    else if (phase == "busy2"){
        holdIn("busy3", STR_TO_DBL(processing_time3.getV()));
    }
    else if( phase == "busy3"){
        passivate();
    }
    /*
    if(phase == "busy1")
        passivate();
    */
}

CONTENT TSP::outputFunc()
{
    
    CONTENT y;
    
    if(phase == "busy1"){   // 큰 따옴표
        string id = job_id.getV();
        y.setContent(out1, id);
    }
    else if(phase == "busy2"){
        string id = "g2";
        y.setContent(out2, id);
    }
    
    else{
        string id = "( " + job_id.getV() + " g2 g3)";
        y.setContent(out2, id);
    }
    

    
    
    //y.setContent(out1, "g1");
    
    return y;

}

