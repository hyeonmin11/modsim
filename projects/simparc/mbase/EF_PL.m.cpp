#include "EF_PL.m.h"

EF_PL::EF_PL(string name)
{
	setName(name);

	ef = new EF(EF_NAME);
	pl = new PL(PL_NAME);

	addModel(ef);
	addModel(pl);

	out = new PORT("out");
	addOutport(*out);

	addCoupling(ef, ef->result, this, this->out);
	addCoupling(ef, ef->out, pl, pl->in);
	addCoupling(pl, pl->out, ef, ef->in);

	setPriorityList(2, pl, ef);
}


EF_PL::~EF_PL()
{
	delete ef;
	delete pl;
	delete out;
}