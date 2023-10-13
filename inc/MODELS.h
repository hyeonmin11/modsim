#ifndef __MODELS_H__
#define __MODELS_H__

//System Header Files (A-Z)
#include <set>

//Common Header Files (A-Z)
#include "DEVS-ObjectC.h"

//DEVS system Header Files (A-Z)
#include "ENTITIES.h"
#include "PORT.h"
#include "PROCESSORS.h"
#include "RELATION.h"

#include "base_type.h"

DLL_EXPORT typedef set<PORT> PortSet;

class DLL_EXPORT PROCESSORS;

class DLL_EXPORT MODELS: public ENTITIES
{
private:

protected:
	PROCESSORS* processor;
	MODELS* parent;
	PortSet inports;
	PortSet outports;

public:
	// 생성자, 소멸자
	MODELS();
	~MODELS();

	// 접근자
	void setProcessor( PROCESSORS* processor );
	PROCESSORS* getProcessor();
	void setParent( MODELS* model );
	ENTITIES* getParent();

	void addInport( PORT port );
	void addOutport( PORT port );
	PortSet getInports();
	PortSet getOutports();
	PORT* getInport( string port_name );
	PORT* getInport( MODELS* model, string port_name );
	PORT* getOutport( string port_name );
	PORT* getOutport( MODELS* model, string port_name );

	virtual void externalTransitionFunc( timetype e, CONTENT x );
	virtual void internalTransitionFunc();
	virtual CONTENT outputFunc();
	virtual ModelPortList translate( int coupling_type, MODELS* src, PORT* port );
	virtual bool hasExternalOutputCopling( MODELS* src, PORT* port );
};
#endif
