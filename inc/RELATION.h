#ifndef __RELATION_H__
#define __RELATION_H__

//System Header Files (A-Z)
#include <list>
#include <map>

//Common Header Files (A-Z)
#include "DEVS-ObjectC.h"

//DEVS system Header Files (A-Z)
#include "ENTITIES.h"
#include "PORT.h"

#include "base_type.h"

enum coupling
{
	EOC, IC, EIC
};

DLL_EXPORT typedef pair<ENTITIES*, PORT*> ModelPort;
DLL_EXPORT typedef multimap<string, ModelPort> CouplingRelation;

// ***********************************************************
// �̸�: ������(sumannam@gmail.com) [2016-10-20]
// �ݿ�����: �Է� argument(model, port)�� ���� ����� Ŀ�ø� �������� ��ȯ�ϱ� ���� �ʿ�
DLL_EXPORT typedef list<ModelPort> ModelPortList;
// ***********************************************************

class DLL_EXPORT RELATION
{
private:

public:
	CouplingRelation coupling_relation;

public:
	// ������, �Ҹ���
	RELATION();
	~RELATION();

	void addCouplingRelation( ENTITIES* src, PORT* src_port, ENTITIES* dst, PORT* dst_port );
	void removeCouplingRelation( ENTITIES* src, PORT* src_port, ENTITIES* dst, PORT* dst_port );
	ModelPortList translate( ENTITIES* model, PORT* port );
	string getModelPortName( ENTITIES* model, PORT* port );
	bool isCoupling( ENTITIES* src, PORT* src_port, ENTITIES* dst, PORT* dst_port );
};
#endif
