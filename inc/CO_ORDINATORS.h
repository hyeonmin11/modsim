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
	// �̸�: ������(sumannam@gmail.com) [2016-08-04]
	// �ݿ�����: �ڵ�����Ϳ��� ���� �𵨵� ����
	typedef list<PROCESSORS*> ProcessorsList;
	typedef set<PROCESSORS*> ProcessorsSet;
	// ***********************************************************

	// ***********************************************************
	// �̸�: ������(sumannam@gmail.com) [2016-08-04]
	// �ݿ�����: �ڵ�����Ϳ��� ���� �𵨵��� time_of_next_event ����
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
	// �̸�: ������(sumannam@gmail.com) [2016-08-08]
	// HACK: ���� *-message�� �����ϴ� ���� DEVS-Scheme�� �ٸ��ٸ� set�� �ƴ� map�� ���� ������� ó�� �ʿ�
	ProcessorsList star_child;
	ProcessorsSet wait_list;
	// ***********************************************************

public:
	// ������, �Ҹ���
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
