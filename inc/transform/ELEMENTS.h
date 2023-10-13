#ifndef __ELEMENTS_H__
#define __ELEMENTS_H__

// DEVS ObjectC System Headers
#include "digraph_models.h"
#include "CONTROLLER.h"
#include "CONTROLLED_MODELS.h"
#include "BROADCAST_MODELS.h"

// DEVS ObjectC System/Transform Headers
#include "binary_tree.h"

#include "base_type.h"

using namespace std;

/**
 *
 *	@file		ELEMENTS.h
 *	@brief		���� Ʈ�� ������ ���� �𵨷� ǥ���ϴ� Ŭ����
 *	@details	
 *	@author		������(sumannam@gmail.com)
 *	@date		2016-12-16
 *	@version	0.2
 *	@remarks	���� Ʈ���� ��Ī�� ���� ��� \n
 *				���� ��Ī�� ���� ���̶�� �ۼ�
 *
 */
class DLL_EXPORT ELEMENTS: public DIGRAPH_MODELS, public CONTROLLED_MODELS
{
	typedef multimap<string, bt_node*> NodeMmap;
	typedef map<string, ELEMENTS*> ElementMap;
	typedef list<bt_node*> NodeList;

	typedef vector<string> StrVector;
	typedef vector<StrVector> CouplingVector;

private:
	static bt_node* root; ///< 2�� Ʈ���� root ���
	static ElementMap coupled_model_map;
	static NodeMmap mbase_map;

	const string xml_am = "AM"; ///< XML ������ atomic model
	const string xml_cm = "CM"; ///< XML ������ coupled model
	const string xml_br = "BROADCAST"; ///< XML ������ broadcast model
	const string xml_ct = "CONTROLLED"; ///< XML ������ controlled model

	string model_type;

public:
	ELEMENTS();

	void setRootModel( bt_node* btree );
	void createCoupledModel( string model_name );
	void constructModel( bt_node* btree );
	void addChildModel( NodeList child_list );
	void addPorts( CouplingVector coupling_vector );
	void addPriority( vector<string> priority_list );
	void addCouplings( CouplingVector coupling_list );
	
	list<bt_node*> getChildModels( string parent_name );
	string getModelType( string name, bt_node* ptr );
	bool hasControlledModel( string parent_name );
	bool hasBroadcastModel(string parent_name);
	bool isControlleeName( string name );
};

#endif // __ELEMENTS_H__
