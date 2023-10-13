#include "digraph_models.h"
#include "mul_arch.m.h"
#include "ef.m.h"

#define EF_MUL_ARCH_NAME "EF_MUL_ARCH"

class EF_MUL_ARCH : public DIGRAPH_MODELS
{
public:
	EF			*ef;
	MUL_ARCH	*mul_arch;

	PORT		*out;

	EF_MUL_ARCH( string name );
	~EF_MUL_ARCH();
};
