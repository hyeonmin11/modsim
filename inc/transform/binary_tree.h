#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

// DEVS ObjectC System Headers
#include "MACROS.h"

// DEVS ObjectC System/Transform Headers
#include "node.h"

// DEVS ObjectC System/Util Headers
#include "MESSAGE.h"

#include "base_type.h"

using namespace std;

DLL_EXPORT struct bt_node
{
	NODE* node;

	struct bt_node* left;
	struct bt_node* right;
};


/**
 *
 *	@brief		���� Ʈ���� ó���ϴ� Ŭ����
 *	@details	���� Ʈ�������� �ڽ� ����� �� ����� ���ʿ� �߰��ǰ�,
 *				���� ����� ���� ����� �����ʿ� �߰��ȴ�.
 *	@author		������(sumannam@gmail.com)
 *	@date		2016-12-19
 *	@version	1.2
 *	@remarks	Ver 1.2 ���ο� �Լ� �߰�, ���� �˰��� ����, ���ʿ��� �Լ� ���� \n
 *				Ver 1.1 DEVS ObjectC 1.0���� ������ ���� \n
 *				Ver 1.0 ���� http://www.sanfoundry.com/cpp-program-implement-binary-tree-2/
 *
*/
template<class T>
class DLL_EXPORT BINARY_TREE
{
private:
	const string UNDER_DEC = "_dec";
	const string UNDER_ASP = "_mdec";

	bt_node* root_node;
	bt_node* target_node;
	bt_node* parent_node;

public:
	BINARY_TREE();
	bt_node* GetRootNode();
	void Insert( bt_node* tree, bt_node* new_node );
	void SetTargetNode( bt_node* tmp_node );
	void FindParentNode( bt_node* ptr );
	bt_node* FindNode( string name, bt_node* ptr );
	void RefreshNode();
};


template<class T>
BINARY_TREE<T>::BINARY_TREE()
{
	root_node = NULL;

	target_node = NULL;
	parent_node = NULL;
}


/**
*
*	@brief		root_node �����͸� �ش�.
*	@details
*	@author		������(sumannam@gmail.com)
*	@date		2016-12-19
*
*	@return		���� Ʈ���� root_node �����͸� �ش�.
*
*/
template<class T>
bt_node* BINARY_TREE<T>::GetRootNode()
{
	return root_node;
}


/**
*
*	@fn			void BINARY_TREE<T>::SetTargetNode( bt_node* tmp_node )
*	@brief		target_node ����
*	@details	Insert()�� �Է� �Ķ���� �� new_node�� target_node�� �����Ѵ�.
*
*	@author		������(sumannam@gmail.com)
*	@date		2016-12-19
*
*	@param	tmp_node target_node�� ������ ���
*
*/
template<class T>
void BINARY_TREE<T>::SetTargetNode( bt_node* tmp_node )
{
	target_node = tmp_node;
	target_node->left = NULL;
	target_node->right = NULL;
}


/**
*
*	@brief		���� Ʈ���� ��� �߰�
*	@details	�˰��� ���� \n
*				1) root_node ���� �˻� \n
*				2) target_node�� parent_node ���� \n
*				3) parent_node�� new_node�� ���ǿ� ���� ���� ��� �Ǵ� �ڽ� ���� ����
*				 - ���� ���(������ ��� �߰�)
*				Variables	| Node Name | Parent Name | Depth
*				------------|-----------|-------------|------
*				parent_node | MUL_ARCH	| EF_A		  | 2
*				new_node	| EF		| EF_A		  | 2
*
*				 - �ڽ� ���(���� ��� �߰�)
*				Variables	| Node Name | Parent Name | Depth
*				------------|-----------|-------------|------
*				parent_node | MUL_ARCH	| EF_A		  | 2
*				new_node	| MUL_C		| MUL_ARCH	  | 3
*
*	@author		������(sumannam@gmail.com)
*	@date		2016-12-19
*
*	@param		tree		target_node�� ������ ���
*	@param		new_node	�߰��� ���
*
*	@todo		�� 2016-12-20 ���� �޽��� ���� (ERR_TR01, ERR_TR02)
*
*/
template<class T>
void BINARY_TREE<T>::Insert( bt_node* tree, bt_node* new_node )
{
	if ( root_node == NULL )
	{
		root_node = new bt_node;
		root_node->node = new_node->node;
		root_node->left = NULL;
		root_node->right = NULL;
		return;
	}

	if ( tree->node->getName() == new_node->node->getName() )
	{
		DEBUG_INFO;
		//COUT_ERROR( ERR_TR01 );
		return;
	}
	else
	{
	#ifdef __DEBUG
		if ( new_node->node->getName() == "BP" )
		{
			DEBUG_INFO;
			DEBUG_COUT( new_node->node->getName() );
		}
	#endif

		SetTargetNode( new_node );
		FindParentNode( root_node );

		if ( parent_node == NULL )
		{
			DEBUG_INFO;
			//DEBUG_COUT( ERR_TR02 );
			return;
		}

	#ifdef __DEBUG
		string model_name = parent_node->node->getName();
		if ( model_name == "MUL_ARCH" )
		{
			DEBUG_INFO;
			DEBUG_COUT( model_name );

			DEBUG_COUT( parent_node->node->getParent() );
			DEBUG_COUT( new_node->node->getParent() );
			DEBUG_COUT( parent_node->node->getDepth() );
			DEBUG_COUT( new_node->node->getDepth() );
		}
	#endif

		// parent_node�� new_node�� parent�� depth�� ������ ���� ���(�����ʿ� �߰�)�̰�,
		// �� ������ �ٸ��� �ڽ� ���(���ʿ� �߰�)�� �ȴ�.
		if ( ( parent_node->node->getParent() == new_node->node->getParent() )
			 && ( parent_node->node->getDepth() == new_node->node->getDepth() ) )
		{
			parent_node->right = new_node;
			( parent_node->right )->left = NULL;
			( parent_node->right )->right = NULL;
		}
		else
		{
			parent_node->left = new_node;
			( parent_node->left )->left = NULL;
			( parent_node->left )->right = NULL;
		}
	}
}


/**
*
*	@fn			void BINARY_TREE<T>::FindParentNode( bt_node* ptr )
*	@brief		���� Ʈ������ �θ� ��� ������ ã��
*	@details	Insert()���� ȣ��Ǵ� �Լ��μ� ��� �Լ��� ����Ͽ� ���� �� ���� ptr�� �θ� ����� �����͸� parent_node�� �����Ѵ�.
*
*	@author		������(sumannam@gmail.com)
*	@date		2016-12-19
*
*	@param	ptr ���� Ʈ���� root ������
*
*/
template<class T>
void BINARY_TREE<T>::FindParentNode( bt_node* ptr )
{
	if ( root_node == NULL )
	{
		DEBUG_INFO;
		//DEBUG_COUT( ERR_TR03 );
		return;
	}

	if ( ptr != NULL )
	{
		string target_node_name = target_node->node->getName();
		string ptr_name = ptr->node->getName();
		string target_node_parent = target_node->node->getParent();

	#ifdef __DEBUG
		
		if ( target_node_name == "P1" )
		{
			DEBUG_INFO;
			DEBUG_COUT( target_node->node->getName() );
		}
		else
		{
			DEBUG_INFO;
			DEBUG_COUT( target_node->node->getName() );
		}
	#endif
		
	#ifdef __DEBUG
		DEBUG_COUT( ptr_name );
		DEBUG_COUT( target_node_parent );
	#endif

		if ( ptr_name == target_node_parent )
		{
			if ( ptr->left == NULL )
			{
				parent_node = ptr;
				return;
			}
			else
			{
				ptr = ptr->left;
				while ( ptr != NULL )
				{
					parent_node = ptr;
					ptr = ptr->right;
				}
				return;
			}
		}

		FindParentNode( ptr->left );
		FindParentNode( ptr->right );

	}
}


/**
*
*	@fn			bt_node* BINARY_TREE<T>::FindNode( string name, bt_node* ptr )
*	@brief		���� Ʈ������ �θ� ��� ������ ã��
*	@details	Transformation�� ���� ��� �Լ��� ����Ͽ� ���� Ʈ������ ���� ���� �ش� ��带 ã�´�.
*
*	@author		������(sumannam@gmail.com)
*	@date		2016-12-19
*
*	@param		name	ã���� �ϴ� ���� �̸�
*	@param		ptr		���� ��� ����Ʈ(ó������ root �Է� �ʿ�)
*
*	@code
*		// TRANSFORM::convertVectortoBinaryTree() ������ �Ʒ��� ���� ���
*		bt_node* coupled_model = Binary_Tree.FindNode( coupled_model_name, root );
*	@endcode
*
*	@todo		�� 2016-12-20 ���� �޽��� ���� (ERR_TR03)
*
*/
template<class T>
bt_node* BINARY_TREE<T>::FindNode( string name, bt_node* ptr )
{
	if ( ptr != NULL )
	{
		if ( ptr->node->getName() == name )
			target_node = ptr;

		FindNode( name, ptr->left );
		FindNode( name, ptr->right );
	}

	return target_node;
}

/**
*
*	@fn			void BINARY_TREE<T>::RefreshNode()
*	@brief		Transform �۾��� Broadcast model�� ������� xml�� ������ �� ó������ �ٽ� �۾��ϱ� ���� �ʱ�ȭ �����ִ� �Լ�
*	@details	 Broadcast model�� Transformation�� �����Ҷ� temp_structure_vector�� �����ϸ� ������� ����Ʈ���� �����Ƿ� �̸� ���� ���� Ʈ�� �ۼ��� ó������ �ٽ� �ۼ��ϵ��� �ʱ�ȭ�� �Ѵ�.
*
*	@author		������
*	@date		2022-11-20
*
*/
template<class T>
void BINARY_TREE<T>::RefreshNode()
{
	root_node = NULL;
	target_node = NULL;
	parent_node = NULL;
}

#endif  // __BINARY_TREE_H__