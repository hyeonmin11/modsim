#ifndef __COUPLED_MODELS_H__
#define __COUPLED_MODELS_H__

//System Header Files (A-Z)
#include <algorithm>
#include <set>
#include <stdarg.h> // ���� ���� �Լ��� ����� ���� �ʿ�

//Common Header Files (A-Z)
#include "DEVS-ObjectC.h"

//DEVS system Header Files (A-Z)
#include "CO_ORDINATORS.h"
#include "MODELS.h"

#include "base_type.h"

// ***********************************************************
// �̸�: ������(sumannam@gmail.com) [2016-11-09]
// �ݿ�����: priority_list�� �����ϱ� ���� ������ �ʿ�
DLL_EXPORT typedef list<MODELS*> ModelList;
// ***********************************************************

class DLL_EXPORT COUPLED_MODELS: public MODELS
{
	typedef set<MODELS*> ModelSet;

private:
	ModelSet children;

public:
	ModelList priority_list;

public:
	// ������, �Ҹ���
	COUPLED_MODELS();
	~COUPLED_MODELS();

	// ������
	void setName( string name );
	void addModel( MODELS* child );

	/**
	 *
	 *	@brief		�켱 ���� �𵨵� ����
	 *	@details	Coupled Model�� �ڽ� �𵨵� �� ���ʺ��� ���� �켱 ���� �ο�
	 *	@author		������(sumannam@gmail.com)
	 *	@date		2016-12-23
	 *
	 *	@param		model	�ڽ� �𵨵� �� �� ��
	 *
	 *	@code
	 *		setPriorityList( 2, EF, P );
	 *	@endcode
	 *
	 */
	void setPriorityList( int count, ... );

	/**
	 *
	 *	@brief		�켱 ���� �� ����
	 *	@details	Coupled Model�� �ڽ� �𵨵� �� ���� �ԷµǴ� ������� ���� �켱 ���� �ο�
	 *	@author		������(sumannam@gmail.com)
	 *	@date		2016-12-23
	 *
	 *	@param		model	�ڽ� �𵨵� �� �� ��
	 *
	 *	@code
	 *		setPriority( EF );
	 *		setPriority( P );
	 *	@endcode
	 *
	 */
	void setPriority( MODELS* model );

	bool isChild( MODELS* model );
	MODELS* findModel( string model_name );

	void initialize();
	void restart();
	void restart( int iter );
	void exitSimulation();
};
#endif
