#include "digraph_models.h"

#include "EF.m.h"
#include "P.m.h"

#define EF_P_NAME "EF_P"

class EF_P: public DIGRAPH_MODELS
{
public:
	EF*		ef;
	P*		p;

	PORT*	out;

	EF_P( string name );
	~EF_P();
};
