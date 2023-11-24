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
	ModelList controllee_list; //클래스에 존재하는 멤버노드들 리스트 (BP1, BP2 ...)
	ModelList influencce_list; //출력값이 어느 모델로 전송될 지 저장하는 리스트.  (지정된 Model ex) BP2 )

public:
	// 생성자, 소멸자
	CONTROLLER();
	~CONTROLLER();

	void setControlleeList( ModelList controllees );
};
#endif
