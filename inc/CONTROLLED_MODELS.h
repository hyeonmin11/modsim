#ifndef __CONTROLLED_MODELS_H__
#define __CONTROLLED_MODELS_H__

//Common Header Files (A-Z)
#include "DEVS-ObjectC.h"

//DEVS system Header Files (A-Z)
#include "KERNEL_MODELS.h"
#include "CONTROLLER.h"

#include "base_type.h"

#define SET_CONTROLLEE( model, name ) \
	model* child = new model( name ); \
	addModel( child ); \
	controllee = child; \
	this->controllee_list.push_back( child ); \

#define MAKE_MEMBERS( model, name, members ) for ( int i = 1; i <= members; i++ ) { SET_CONTROLLEE( model, name + INT_TO_STR( i ) ); }

#define SET_CONTROLLER( cntr ) \
	controller = cntr; \
	addModel( controller );	\
	controller->setControlleeList( controllee_list );	\


class DLL_EXPORT CONTROLLED_MODELS: public KERNEL_MODELS
{
	typedef map<string, string> PortPair;

private:

public:
	CONTROLLER* controller;		
	ModelList controllee_list;	
	MODELS* controllee;			

public:
	// 持失切, 社瑚切
	CONTROLLED_MODELS();
	~CONTROLLED_MODELS();

	void addCoupling( MODELS* src, PORT* src_port, MODELS* dst, PORT* dst_port );
	void addStringCoupling( string src_model_name, string src_port_name, string dst_model_name, string dst_port_name );
	virtual ModelPortList translate( int coupling_type, MODELS* src, PORT* port );
};
#endif
