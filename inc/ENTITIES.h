#ifndef __ENTITIES_H__
#define __ENTITIES_H__

//Common Header Files (A-Z)
#include "DEVS-ObjectC.h"
#include "MACROS.h"

#include "base_type.h"

class DLL_EXPORT ENTITIES
{
private:

protected:
	string name;


public:
	// Constructure & Desconstructure
	ENTITIES();
	ENTITIES( string name );
	~ENTITIES();

	// Accessor & Mutator
	void setName( string name );
	void linkSimulator( string name );
	void setenttype(string name);
	string getName();
	ENTITIES* getEntity();
	string enttype;

};

#endif // __ENTITIES_H__
