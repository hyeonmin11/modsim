#ifndef __SIMULATORS_H__
#define __SIMULATORS_H__

//Common Header Files (A-Z)
#include "DEVS-ObjectC.h"

//DEVS system Header Files (A-Z)
#include "ATOMIC_MODELS.h"
#include "PROCESSORS.h"
#include "ROOT_CO_ORDINATORS.h"

//Utility Header Files (A-Z)
#include "DISPLAY.h"
#include "LOG.h"

#include "base_type.h"

class DLL_EXPORT SIMULATORS: public PROCESSORS
{
private:

public:
	// 持失切, 社瑚切
	SIMULATORS();
	~SIMULATORS();

	void initialize();
	void whenReceiveStar( MESSAGES input_message );
	void whenReceiveX( MESSAGES input_message );

	bool isPairParentCoupling( CONTENT content );
	void setFlashMessage( MESSAGES input_message );

	// DEVS-DD
	void initializeModelStructure( int parentDepth );
	string generateModelStructure();
};
#endif
