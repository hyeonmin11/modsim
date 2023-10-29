#include "TWIOP.m.h"

TWIOP::TWIOP(string name)
{
    linkSimulator(name);

    
    in1 = new PORT("in1");
    in2 = new PORT("in2");
    out1 = new PORT("out1");
    out2 = new PORT("out2");

    addInport(*in1);
    addInport(*in2);
    addOutport(*out1);
    addOutport(*out2);

    //job_id("job_id"); //  cannot understand
    processing_time1("processing_time1"); // cannot understand
    processing_time2("processing_time2");
    processing_time3("processing_time3");
    sigma = INFINITY;
    phase = "passive";

    //job_id = "-";
    id_inport = "-";
    processing_time1 = 3.0;
    processing_time2 = 5.0;
    processing_time3 = 4.0;

}

TWIOP::~TWIOP()
{
    delete out1;
    delete out2;
    delete in1;
    delete in2;
}

void TWIOP::externalTransitionFunc(timetype e, CONTENT x)
{
    
    if(phase == "passive")
    {
        //job_id = x.getValue();
        PORT* temp = x.getPort();
        id_inport = (*temp).getName();
        //*id_inport = x.getPort();
        holdIn("busy1", STR_TO_DBL(processing_time1.getV()));
    }
    else{
        Continue(e);
    }
    

    //Continue(e);
    
}

void TWIOP::internalTransitionFunc()
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
    
    
   
    //passivate();
    
}

CONTENT TWIOP::outputFunc()
{
    
    CONTENT y;


    
    if(id_inport == "in1"){

        if(phase == "busy1"){   // 큰 따옴표
            string id = "g1";//job_id.getV();
            y.setContent(out1, id);
        }
        else if(phase == "busy2"){
            string id = "g2";
            y.setContent(out1, id);
        }
        
        else{
            string id = "g3";
            y.setContent(out2, id);
        }

    }
    else{

        if(phase == "busy1"){   // 큰 따옴표
            string id = "g1";//job_id.getV();
            y.setContent(out2, id);
        }
        else if(phase == "busy2"){
            string id = "g2";
            y.setContent(out2, id);
        }
        
        else{
            string id = "g3";
            y.setContent(out1, id);
        }

    }
    
    

    
    
   // y.setContent(out1, "g1");
    
    return y;

}

