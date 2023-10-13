#ifndef __BROADCAST_MODELS_H__
#define __BROADCAST_MODELS_H__

//Common Header Files (A-Z)
#include "DEVS-ObjectC.h"

//DEVS system Header Files (A-Z)
#include "KERNEL_MODELS.h"

#include "base_type.h"

#define SET_CONTROLLEE( model, name ) \
	model* child = new model( name ); \
	addModel( child ); \
	controllee = child; \
	this->controllee_list.push_back( child ); \

#define MAKE_MEMBERS( model, name, members ) for ( int i = 1; i <= members; i++ ) { SET_CONTROLLEE( model, name + INT_TO_STR( i ) ); }

class DLL_EXPORT BROADCAST_MODELS: public KERNEL_MODELS
{
private:

public:
	MODELS* controllee;

public:
	// 持失切, 社瑚切
	BROADCAST_MODELS();
	~BROADCAST_MODELS();

	void addCoupling( MODELS* src_model, PORT* src_port, MODELS* dst_model, PORT* dst_port );
	virtual ModelPortList translate( int coupling_type, MODELS* src, PORT* port );
};
#endif
