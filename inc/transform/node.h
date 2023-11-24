#ifndef __NODE_H__
#define __NODE_H__

#include <vector>

// DEVS ObjectC System Headers
#include "DEVS-ObjectC.h"

#include "base_type.h"

#include "macros.h"

// DEVS ObjectC System/Transform Headers
//#include "tinymain.h"

using namespace std;

class DLL_EXPORT NODE
{
	typedef vector<string> StrVector;
	typedef vector<StrVector> CouplingVector;

private:
	string type;
	string model;
	string parent;
	string name;
	int members;
	int depth;
	string coup_info[4];
	bool bt_flag; // Binary Tree에 추가된 여부

public:
	StrVector priority_vector;
	StrVector line_vector;
	CouplingVector coupling_vector;

public:
	NODE();
	~NODE();

	void setType( string input );
	string getType();
	void setModel( string input );
	string getModel();
	void setParent( string input );
	string getParent();
	void setName( string input );
	string getName();
	void setMembers( string input );
	int getMembers();
	void setDepth( string input );
	int getDepth();
	void setSource( string input );
	string getSource();
	void setInport( string input );
	string getInport();
	void setDestin( string input );
	string getDestin();
	void setOutport( string input );
	string getOutport();
	void setFlag( bool input );
	bool getFlag();

	vector<vector<string>> getCouplingVector();
	vector<string> getPriorityVector();
};

#endif
