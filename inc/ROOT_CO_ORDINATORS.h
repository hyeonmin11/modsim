#ifndef __ROOT_CO_ORDINATORS_H__
#define __ROOT_CO_ORDINATORS_H__
#define __DEVS_DD
//Common Header Files (A-Z)
#include "DEVS-ObjectC.h"

//DEVS system Header Files (A-Z)
#include "CO_ORDINATORS.h"
#include "PROCESSORS.h"
#include "STATE_VARS.h"
//Utility Header Files (A-Z)
#include "LOG.h"

#include "base_type.h"


class DLL_EXPORT ROOT_CO_ORDINATORS: public PROCESSORS
{
private:
	static timetype clock_base;
	static int log_seq;

	string name;
	PROCESSORS* child;
	bool run_command2 = false;

public:
	// 持失切, 社瑚切
	ROOT_CO_ORDINATORS();
	~ROOT_CO_ORDINATORS();

	void setName( string name );
	void setChild( PROCESSORS* processor );

	void initialize();
	void restart();
	void whenReceiveDone( MESSAGES input_message );
	void setFlashMessage( MESSAGES input_message );
	DWORD WINAPI ThreadFunc(void* data);

	// DEVS-DD
	void initializeModelStructure( int depth );
	void setModelDepth( int depth );
	string generateModelStructure();
	string generateStateVarStructure();
};
#endif
