#ifndef __KERNEL_MODELS__
#define __KERNEL_MODELS__

//System Header Files (A-Z)
#include <list>

//Common Header Files (A-Z)
#include "DEVS-ObjectC.h"

//DEVS system Header Files (A-Z)
#include "COUPLED_MODELS.h"

#include "base_type.h"

DLL_EXPORT typedef list<MODELS*> ModelList;

class DLL_EXPORT KERNEL_MODELS: public COUPLED_MODELS
{
private:

protected:
	MODELS* init_cell;
	ModelList controllee_list;

	RELATION external_output_coupling; // EOC
	RELATION internal_coupling; // IC (scheme에서 out-in-coup와 같음)
	RELATION external_input_coupling; // EIC

public:
	// 생성자, 소멸자
	KERNEL_MODELS();
	~KERNEL_MODELS();

	virtual void addCoupling( MODELS* src_model, PORT* src_port, MODELS* dst_model, PORT* dst_port );
	virtual ModelPortList translate( int coupling_type, MODELS* src, PORT* port );
};
#endif
