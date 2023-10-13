#ifndef __DIGRAPH_MODELS_H__
#define __DIGRAPH_MODELS_H__

//Common Header Files (A-Z)
#include "DEVS-ObjectC.h"

//DEVS system Header Files (A-Z)
#include "ATOMIC_MODELS.h"
#include "COUPLED_MODELS.h"
// ***********************************************************
// �̸�: ������(sumannam@gmail.com) [2016-07-21]
// TODO: DEVS-ObjC 1.0ó�� COUPLED_MODELS.h -> CO_ORDINATOR.h���� RELATION.h ���� �ʿ�
//       �� ������ �������� ����, ���� ������ ������ ���ʿ��ϴٸ� ���� �𵨿��� RELATION.H �����ϰ�
//       CO_ORDINATOR���� ���� ����
#include "RELATION.h"
// ***********************************************************

#include "base_type.h"

class DLL_EXPORT DIGRAPH_MODELS: public COUPLED_MODELS
{
private:
	
public:
	/**
	 * @author	������
	 * @date		2017-02-06
	 * @enum		mbaseSet
	 * @brief	Transformation�� ���� MBASE Ŭ���� ����
	 * @details	�𵨷��� ������ MBASE�� getAtomicModel()�� ����
	 * @see		ELEMENTS::addChildModel()
	 */
	static DIGRAPH_MODELS* mbaseSet;

	RELATION external_output_coupling; // EOC
	RELATION internal_coupling; // IC
	RELATION external_input_coupling; // EIC
	
public:
	// ������, �Ҹ���
	DIGRAPH_MODELS();
	~DIGRAPH_MODELS();

	void addCoupling( MODELS* src_model, PORT* src_port, MODELS* dst_model, PORT* dst_port );
	void addStringCoupling( string src_model_name, string src_port_name, string dst_model_name, string dst_port_name );

	virtual ModelPortList translate( MODELS* src, PORT* port );
	virtual ModelPortList translate( int coupling_type, MODELS* src, PORT* port );
	virtual bool hasExternalOutputCopling( MODELS* src, PORT* port );

	// Transformation�� ���� �Լ���
	DIGRAPH_MODELS* getMbasease();
	void setMbase( DIGRAPH_MODELS* model );
	virtual ATOMIC_MODELS* getAtomicModel( string model_name );
};
#endif
