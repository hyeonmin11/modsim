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
 *	@brief		이진 트리를 처리하는 클래스
 *	@details	이진 트리에서는 자식 노드일 때 노드의 왼쪽에 추가되고,
 *				형제 노드일 때는 노드의 오른쪽에 추가된다.
 *	@author		남수만(sumannam@gmail.com)
 *	@date		2016-12-19
 *	@version	1.2
 *	@remarks	Ver 1.2 새로운 함수 추가, 기존 알고리즘 개선, 불필요한 함수 삭제 \n
 *				Ver 1.1 DEVS ObjectC 1.0에서 구현한 내용 \n
 *				Ver 1.0 참고 http://www.sanfoundry.com/cpp-program-implement-binary-tree-2/
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
*	@brief		root_node 포인터를 준다.
*	@details
*	@author		남수만(sumannam@gmail.com)
*	@date		2016-12-19
*
*	@return		이진 트리의 root_node 포인터를 준다.
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
*	@brief		target_node 설정
*	@details	Insert()의 입력 파라미터 중 new_node를 target_node에 저장한다.
*
*	@author		남수만(sumannam@gmail.com)
*	@date		2016-12-19
*
*	@param	tmp_node target_node에 저장한 노드
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
*	@brief		이진 트리에 노드 추가
*	@details	알고리즘 설명 \n
*				1) root_node 상태 검사 \n
*				2) target_node와 parent_node 설정 \n
*				3) parent_node와 new_node의 조건에 따라 형제 노드 또는 자식 노드로 구분
*				 - 형제 노드(오른쪽 노드 추가)
*				Variables	| Node Name | Parent Name | Depth
*				------------|-----------|-------------|------
*				parent_node | MUL_ARCH	| EF_A		  | 2
*				new_node	| EF		| EF_A		  | 2
*
*				 - 자식 노드(왼쪽 노드 추가)
*				Variables	| Node Name | Parent Name | Depth
*				------------|-----------|-------------|------
*				parent_node | MUL_ARCH	| EF_A		  | 2
*				new_node	| MUL_C		| MUL_ARCH	  | 3
*
*	@author		남수만(sumannam@gmail.com)
*	@date		2016-12-19
*
*	@param		tree		target_node에 저장한 노드
*	@param		new_node	추가할 노드
*
*	@todo		□ 2016-12-20 오류 메시지 정의 (ERR_TR01, ERR_TR02)
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

		// parent_node와 new_node의 parent와 depth가 같으면 형제 노드(오른쪽에 추가)이고,
		// 두 조건이 다르면 자식 노드(왼쪽에 추가)가 된다.
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
*	@brief		이진 트리에서 부모 노드 포인터 찾기
*	@details	Insert()에서 호출되는 함수로서 재귀 함수를 사용하여 리턴 값 없이 ptr의 부모 노드의 포인터를 parent_node에 저장한다.
*
*	@author		남수만(sumannam@gmail.com)
*	@date		2016-12-19
*
*	@param	ptr 이진 트리의 root 포인터
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
*	@brief		이진 트리에서 부모 노드 포인터 찾기
*	@details	Transformation를 위해 재귀 함수를 사용하여 이진 트리에서 결합 모델의 해당 노드를 찾는다.
*
*	@author		남수만(sumannam@gmail.com)
*	@date		2016-12-19
*
*	@param		name	찾고자 하는 모델의 이름
*	@param		ptr		현재 노드 포인트(처음에는 root 입력 필요)
*
*	@code
*		// TRANSFORM::convertVectortoBinaryTree() 내에서 아래와 같이 사용
*		bt_node* coupled_model = Binary_Tree.FindNode( coupled_model_name, root );
*	@endcode
*
*	@todo		□ 2016-12-20 오류 메시지 정의 (ERR_TR03)
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


#endif  // __BINARY_TREE_H__