#ifndef __CO_ORDINATORS_H__
#define __CO_ORDINATORS_H__
#define _AHN_DEBUG_
//System Header Files (A-Z)
#include <list>
#include <map>
#include <set>

//Common Header Files (A-Z)
#include "DEVS-ObjectC.h"

//DEVS system Header Files (A-Z)
#include "COUPLED_MODELS.h"
#include "PROCESSORS.h"
#include "ROOT_Co_ORDINATORS.h"

//Utility Header Files (A-Z)
#include "LOG.h"
#include "DISPLAY.h"

#include "base_type.h"

class DLL_EXPORT CO_ORDINATORS: public PROCESSORS
{
	// ***********************************************************
	// 이름: 남수만(sumannam@gmail.com) [2016-08-04]
	// 반영이유: 코디네이터에서 하위 모델들 저장
	typedef list<PROCESSORS*> ProcessorsList;
	typedef set<PROCESSORS*> ProcessorsSet;
	// ***********************************************************

	// ***********************************************************
	// 이름: 남수만(sumannam@gmail.com) [2016-08-04]
	// 반영이유: 코디네이터에서 하위 모델들의 time_of_next_event 관리
	typedef map<PROCESSORS*, timetype> ProcessorsMap;
	// ***********************************************************

	typedef map<MODELS*, timetype> ModelsMap;

private:
	int event_type;

	ProcessorsSet destinations;
	ProcessorsSet processors_set;
	ProcessorsMap processors_time;
	ModelsMap tN_children;

	// ***********************************************************
	// 이름: 남수만(sumannam@gmail.com) [2016-08-08]
	// HACK: 만약 *-message가 전달하는 것이 DEVS-Scheme가 다르다면 set이 아닌 map를 통해 순서대로 처리 필요
	ProcessorsList star_child;
	ProcessorsSet wait_list;
	// ***********************************************************

public:
	// 생성자, 소멸자
	CO_ORDINATORS();
	~CO_ORDINATORS();

	void addChild( PROCESSORS* processor );
	void setTimeOfNextEvent();

	void initialize();
	void whenReceiveStar( MESSAGES input_message );
	void whenReceiveX( MESSAGES input_message );
	void whenReceiveY( MESSAGES input_message );
	void whenReceiveDone( MESSAGES input_message );

	void setStarChild();
	int countSameTimeInChildren( timetype time );
	MESSAGES reconstructMessage( int coupling_type, MESSAGES message, MODELS* coupled_model, MODELS* destination );
	void eraseWaitList( MODELS* model );
	void eraseStarChild( MODELS* model );
	timetype getMintNChildren();

	string getProcessor( ProcessorsSet list );
	string getProcessor( ProcessorsList list );

	void setFlashMessage( MESSAGES input_message );

	// DEVS-DD
	void initializeModelStructure( int parentDepth );
	string generateModelStructure();
};
#endif
