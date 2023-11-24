#ifndef __PROCESSORS_H__
#define __PROCESSORS_H__

//System Header Files (A-Z)
#include <fstream>

//Common Header Files (A-Z)
#include "DEVS-ObjectC.h"

//DEVS system Header Files (A-Z)
#include "base_type.h"
#include "MESSAGES.h"
#include "MODELS.h"

#include "IPC.h"
#include "LOG.h"

#define ROOT_NAME "R:"

class DLL_EXPORT MODELS;

class DLL_EXPORT PROCESSORS: public ENTITIES
{
private:

protected:
	static timetype runtime;
	static string flashMessageFileName;
	static string startLogFileName;
	static string modelStructure;

	static IPC pipeline;

	/**
	 * @author	남수만
	 * @date		2017-02-06
	 * @enum		starLog
	 * @brief	Start Log에서 ext-fn과 int-fn 구분하기 위해 사용
	 * @see		ATOMIC_MODELS::ExecuteModelTest()
	 */
	enum startLog
	{
		extFn = 1, intFn = 2
	};

	timetype init_sigma;

	PROCESSORS* parent;
	MODELS* devs_component;

	timetype tN; // time_of_next_event
	timetype tL; // time_of_last_event

	int modelDepth; // for DEVS-DD

	// ***********************************************************
	// 이름: 남수만(sumannam@gmail.com) [2016-08-26]
	// 반영이유: Simulation Message txt로 출력용 변수
	// [2016-09-01] flash_message용 변수(sim_msg_log)와 sim_msg_log용 변수(flash_msg_log)를 선언했지만,
	//				Windows10/VS2015에서 오류 발생으로 하나의 변수(msg_log)만 사용
	ofstream msg_log;
	ofstream start_log;
	// ***********************************************************

public:
	// 생성자, 소멸자
	PROCESSORS();
	~PROCESSORS();

	// 접근자
	void setParent( PROCESSORS* processor );
	PROCESSORS* getParent();
	void setDevsComponent( MODELS* model );
	MODELS* getDevsComponent();
	timetype getTimeOfNextEvent();
	timetype getTimeOfLastEvent();

	void setName( string name );
	void setFlashMessageFileName( string name );
	void setStartLogFileName( string name );

	// Flash Message
	void showFlashMessage( PROCESSORS* model, MESSAGES input_message );
	void showFlashMessage( MODELS* model, MESSAGES input_message );
	void writeFlashMessage( PROCESSORS* model, MESSAGES input_message );
	void writeFlashMessage( MODELS* model, MESSAGES input_message );
	void generateDiagramDisplayMessage( string modelname, int msgid, MESSAGES input_message ); // DEVS_DD PIPE 메시지 생성 함수
	// Start-Log
	void writeStartLog( timetype clock_base );
	void writeStartLog( MODELS* model, int type, CONTENT content );
	void writeStartLog( MODELS* model, startLog type, string state_var );

	virtual void initialize();
	virtual void restart();
	virtual void whenReceiveStar( MESSAGES input_message );
	virtual void whenReceiveX( MESSAGES input_message );
	virtual void whenReceiveY( MESSAGES input_message );
	virtual void whenReceiveDone( MESSAGES input_message );
	virtual void setTimeOfNextEvent();

	// DEVS-DD
	void addModelStructure( string modelStr );
	virtual void initializeModelStructure( int depth );
	virtual string generateModelStructure();
	//for makeini func
	void makeinifile(string content);
};
#endif
