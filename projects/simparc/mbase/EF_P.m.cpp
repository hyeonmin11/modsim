#include "EF_P.m.h"

EF_P::EF_P(string name)
{
	setName(name);

	ef = new EF(EF_NAME);
	p = new P(P_NAME);

	addModel(ef);
	addModel(p);

	out = new PORT("out");
	addOutport(*out);

	addCoupling(ef, ef->result, this, this->out);
	addCoupling(ef, ef->out, p, p->in);
	addCoupling(p, p->out, ef, ef->in);
	
	setPriorityList(2, ef, p);

}


EF_P::~EF_P()
{
	delete ef;
	delete p;
	delete out;
}