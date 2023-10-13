#ifndef __CONTENT_H__
#define __CONTENT_H__

//System Header Files (A-Z)
#include <vector>

//Common Header Files (A-Z)
#include "DEVS-ObjectC.h"

//DEVS system Header Files (A-Z)
#include "PORT.h"

#include "base_type.h"

class DLL_EXPORT CONTENT
{
	typedef vector<string> StrVector;
	typedef vector<StrVector> StrVectorlist;
	typedef vector<PORT*> PortList;

private:
	PortList portlist;
	PORT* port;
	StrVector value;
	StrVectorlist valuelist;
public:
	// ������, �Ҹ���
	CONTENT();
	CONTENT( PORT* port, string value );
	CONTENT( PORT* port, StrVector value );
	~CONTENT();

	void setContent( PORT* port, string value );
	void setContent( PORT* port, StrVector value );

	CONTENT* getContent();
	PORT* getPort();

	// ���� �𵨿��� ���ٿ� �Լ�
	bool getPort( PORT* port );
	vector<PORT*> getPortList();
	string getValue();
	StrVector getValueList();
	StrVectorlist getValueLists();
	void eraseportval();
	void eraseportvallist();
};
#endif
