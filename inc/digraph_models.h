#ifndef __DIGRAPH_MODELS_H__
#define __DIGRAPH_MODELS_H__

//Common Header Files (A-Z)
#include "DEVS-ObjectC.h"

//DEVS system Header Files (A-Z)
#include "ATOMIC_MODELS.h"
#include "COUPLED_MODELS.h"
// ***********************************************************
// 이름: 남수만(sumannam@gmail.com) [2016-07-21]
// TODO: DEVS-ObjC 1.0처럼 COUPLED_MODELS.h -> CO_ORDINATOR.h에서 RELATION.h 참조 필요
//       위 내용은 어디까지나 추측, 만약 복잡한 참조가 불필요하다면 현재 모델에서 RELATION.H 참조하고
//       CO_ORDINATOR에서 참조 가능
#include "RELATION.h"
// ***********************************************************

#include "base_type.h"

class DLL_EXPORT DIGRAPH_MODELS: public COUPLED_MODELS
{
private:
	
public:
	/**
	 * @author	남수만
	 * @date		2017-02-06
	 * @enum		mbaseSet
	 * @brief	Transformation를 위해 MBASE 클래스 연결
	 * @details	모델러가 구현한 MBASE의 getAtomicModel()를 연결
	 * @see		ELEMENTS::addChildModel()
	 */
	static DIGRAPH_MODELS* mbaseSet;

	RELATION external_output_coupling; // EOC
	RELATION internal_coupling; // IC
	RELATION external_input_coupling; // EIC
	
public:
	// 생성자, 소멸자
	DIGRAPH_MODELS();
	~DIGRAPH_MODELS();

	void addCoupling( MODELS* src_model, PORT* src_port, MODELS* dst_model, PORT* dst_port );
	void addStringCoupling( string src_model_name, string src_port_name, string dst_model_name, string dst_port_name );

	virtual ModelPortList translate( MODELS* src, PORT* port );
	virtual ModelPortList translate( int coupling_type, MODELS* src, PORT* port );
	virtual bool hasExternalOutputCopling( MODELS* src, PORT* port );

	// Transformation를 위한 함수들
	DIGRAPH_MODELS* getMbasease();
	void setMbase( DIGRAPH_MODELS* model );
	virtual ATOMIC_MODELS* getAtomicModel( string model_name );
};
#endif
