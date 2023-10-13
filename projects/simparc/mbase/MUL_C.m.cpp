#include "mul_c.m.h"

MUL_C::MUL_C(string name)
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

	p1_s("p1_s");
	p2_s("p2_s");
	p3_s("p3_s");
	out_port("out_port");
	job_id("job_id");

	sigma = INFINITY;
	phase = "passive";
	p1_s = "passive";
	p2_s = "passive";
	p3_s = "passive";
	out_port = "-";
	job_id = "-";
}


MUL_C::~MUL_C(void)
{
	delete in;
	delete out;
	delete x1;
	delete x2;
	delete y1;
	delete y2;
	delete x3;
	delete y3;
}


void MUL_C::externalTransitionFunc(timetype e, CONTENT x)
{
	out_port = "-";
	job_id = x.getValue();

	if (*in == x.getPort())
	{
		if (p1_s == "passive")
		{
			out_port = "x1";
			p1_s = "busy";
		}
		else if (p2_s == "passive")
		{
			out_port = "x2";
			p2_s = "busy";
		}
		else if (p3_s == "passive")
		{
			out_port = "x3";
			p3_s = "busy";
		}
	}
	else if (*y1 == x.getPort())
	{
		p1_s = "passive";
		out_port = "out";
	}
	else if (*y2 == x.getPort())
	{
		p2_s = "passive";
		out_port = "out";
	}
	else if (*y3 == x.getPort())
	{
		p3_s = "passive";
		out_port = "out";
	}

	holdIn("busy", 0);
}


void MUL_C::internalTransitionFunc()
{
	if (phase == "busy")
		passivate();
}


CONTENT MUL_C::outputFunc()
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
