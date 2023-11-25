#include "digraph_models.h"
#include "pip_arch.m.h"
#include "ef.m.h"

#define EF_PIP_ARCH_NAME "EF_PIP_ARCH"

class EF_PIP_ARCH : public DIGRAPH_MODELS
{
public:
	EF			*ef;
	PIP_ARCH	*pip_arch;

	PORT		*out;

	EF_PIP_ARCH( string name );
	~EF_PIP_ARCH();
};