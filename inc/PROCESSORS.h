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
	 * @author	������
	 * @date		2017-02-06
	 * @enum		starLog
	 * @brief	Start Log���� ext-fn�� int-fn �����ϱ� ���� ���
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
	// �̸�: ������(sumannam@gmail.com) [2016-08-26]
	// �ݿ�����: Simulation Message txt�� ��¿� ����
	// [2016-09-01] flash_message�� ����(sim_msg_log)�� sim_msg_log�� ����(flash_msg_log)�� ����������,
	//				Windows10/VS2015���� ���� �߻����� �ϳ��� ����(msg_log)�� ���
	ofstream msg_log;
	ofstream start_log;
	// ***********************************************************

public:
	// ������, �Ҹ���
	PROCESSORS();
	~PROCESSORS();

	// ������
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
	void generateDiagramDisplayMessage( string modelname, int msgid, MESSAGES input_message ); // DEVS_DD PIPE �޽��� ���� �Լ�
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
