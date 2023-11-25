#include "digraph_models.h"

#include "EF.m.h"
#include "PL.m.h"

#define EF_PL_NAME "EF_PL"

class EF_PL: public DIGRAPH_MODELS
{
public:
	EF*		ef;
	PL*		pl;

	PORT*	out;

	EF_PL( string name );
	~EF_PL();
};