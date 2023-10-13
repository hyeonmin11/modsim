#include "nep.m.h"

NEP::NEP(string name)
{
    linkSimulator(name);

    out = new PORT("out");

    addOutport(*out);

    job_id("job_id");


    sigma = 5; //여기서 왜 시그마 데이터타입 안 지정해주는거?
    phase = "process";
    job_id = "-";
}

NEP::~NEP()
{
    delete out;
}

void NEP::internalTransitionFunc()
{
    if(phase == "process"){
        passivate();
    }
}

CONTENT P::outputFunc()
{
    CONTENT y;
    string id = job_id.getV();

    if (phase == "process"){
        y.setContent(out, id);
    }
    return y;
}