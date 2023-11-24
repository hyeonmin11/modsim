#include "pip_c.m.h"

PIP_C::PIP_C(string name)
{
	linkSimulator(name);

	in = new PORT("in");
	out = new PORT("out");
	x1 = new PORT("x1");
	x2 = new PORT("x2");
	x3 = new PORT("x3");
	y1 = new PORT("y1");
	y2 = new PORT("y2");
	y3 = new PORT("y3");

	addInport(*in);
	addInport(*y1);
	addInport(*y2);
	addInport(*y3);

	addOutport(*out);
	addOutport(*x1);
	addOutport(*x2);
	addOutport(*x3);

	out_port("out_port");
	job_id("job_id");

	sigma = INFINITY;
	phase = "passive";
	job_id = "-";
	out_port = "-";
}

PIP_C::~PIP_C(void)
{
	delete in;
	delete out;
	delete x1;
	delete x2;
	delete x3;
	delete y1;
	delete y2;
	delete x3;
}

void PIP_C::externalTransitionFunc(timetype e, CONTENT x)
{
	out_port = "-";
	job_id = x.getValue();

	if (*in == x.getPort())
	{
		out_port = "x1";
	}

	else if (*y1 == x.getPort())
	{
		out_port = "x2";
	}
	
	else if (*y2 == x.getPort())
	{
		out_port = "x3";
	}
	
	else if (*y3 == x.getPort())
	{
		out_port = "out";
	}

	holdIn("busy", 0);

}


void PIP_C::internalTransitionFunc()
{
	if (phase == "busy")
		passivate();
}

CONTENT PIP_C::outputFunc()
{
	CONTENT content;

	if (phase == "busy")
	{
		if ((out_port == "x1") || (out_port == "x2") || \
			(out_port == "x3") || (out_port == "out"))
		{
			PORT* outport = this->getOutport(out_port.getV());
			string id = job_id.getV();

			content.setContent(outport, id);
		}
	}

	return content;
}