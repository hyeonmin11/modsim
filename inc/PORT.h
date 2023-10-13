#ifndef __PORT_H__
#define __PORT_H__

//Common Header Files (A-Z)
#include "DEVS-ObjectC.h"

#include "base_type.h"

class DLL_EXPORT PORT
{
private:
	string name;

public:
	// ������, �Ҹ���
	PORT();
	PORT( string name );
	~PORT();

	// ������
	void setName( string name );
	string getName();

	bool operator==( const PORT* port );
	bool operator==( PORT port ) const;
	bool operator<( PORT port ) const;
};
#endif
