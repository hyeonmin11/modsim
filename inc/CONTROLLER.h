#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__

//Common Header Files (A-Z)
#include "DEVS-ObjectC.h"

//DEVS system Header Files (A-Z)
#include "ATOMIC_MODELS.h"
#include "KERNEL_MODELS.h"

#include "base_type.h"

class DLL_EXPORT CONTROLLER: public ATOMIC_MODELS
{
private:

public:
	ModelList controllee_list; //Ŭ������ �����ϴ� ������� ����Ʈ (BP1, BP2 ...)
	ModelList influencce_list; //��°��� ��� �𵨷� ���۵� �� �����ϴ� ����Ʈ.  (������ Model ex) BP2 )

public:
	// ������, �Ҹ���
	CONTROLLER();
	~CONTROLLER();

	void setControlleeList( ModelList controllees );
};
#endif
