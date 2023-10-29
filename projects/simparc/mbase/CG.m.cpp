#include "CG.m.h"

CG::CG(string name)
{
    
    linkSimulator(name);

    
    stop = new PORT("stop");
    out1 = new PORT("out1");
    out2 = new PORT("out2");

    addInport(*stop);
    addOutport(*out1);
    addOutport(*out2);

    processing_time1("processing_time1"); // cannot understand
    processing_time2("processing_time2");
    sigma = 5;
    phase = "active1";


    processing_time1 = 5.0;
    processing_time2 = 10.0;
    

}

CG::~CG()
{
    
    delete out1;
    delete out2;
    delete stop;
    
}

void CG::externalTransitionFunc(timetype e, CONTENT x)
{
    PORT* temp = x.getPort();
    string id_inport = (*temp).getName();
    if(id_inport == "stop"){
        passivate();
    }
}

void CG::internalTransitionFunc()
{
    
    
    
    if (phase == "active1"){
        holdIn("active2", STR_TO_DBL(processing_time2.getV()));
    }
    else if (phase == "active2"){
        holdIn("active1", STR_TO_DBL(processing_time1.getV()));
    }
    

    //passivate();
    
}

CONTENT CG::outputFunc()
{
    
    CONTENT y;

    
    if(phase == "active1"){   // 큰 따옴표
        string id = "g1";//job_id.getV();
        y.setContent(out1, id);
    }
    else if(phase == "active2"){
        string id = "g2";
        y.setContent(out2, id);
    }
    

   //y.setContent(out1, "g1");
    
    return y;

}