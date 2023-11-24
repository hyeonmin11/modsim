#ifndef __COUPLED_MODELS_H__
#define __COUPLED_MODELS_H__

//System Header Files (A-Z)
#include <algorithm>
#include <set>
#include <stdarg.h> // 가변 인자 함수를 만들기 위해 필요

//Common Header Files (A-Z)
#include "DEVS-ObjectC.h"

//DEVS system Header Files (A-Z)
#include "CO_ORDINATORS.h"
#include "MODELS.h"

#include "base_type.h"

// ***********************************************************
// 이름: 남수만(sumannam@gmail.com) [2016-11-09]
// 반영이유: priority_list를 설정하기 위해 선언이 필요
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
	// 생성자, 소멸자
	COUPLED_MODELS();
	~COUPLED_MODELS();

	// 접근자
	void setName( string name );
	void addModel( MODELS* child );

	/**
	 *
	 *	@brief		우선 순위 모델들 설정
	 *	@details	Coupled Model의 자식 모델들 중 왼쪽부터 높은 우선 순위 부여
	 *	@author		남수만(sumannam@gmail.com)
	 *	@date		2016-12-23
	 *
	 *	@param		model	자식 모델들 중 한 모델
	 *
	 *	@code
	 *		setPriorityList( 2, EF, P );
	 *	@endcode
	 *
	 */
	void setPriorityList( int count, ... );

	/**
	 *
	 *	@brief		우선 순위 모델 설정
	 *	@details	Coupled Model의 자식 모델들 중 먼저 입력되는 순서대로 높은 우선 순위 부여
	 *	@author		남수만(sumannam@gmail.com)
	 *	@date		2016-12-23
	 *
	 *	@param		model	자식 모델들 중 한 모델
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
