#ifndef __ATOMIC_MODELS_H__
#define __ATOMIC_MODELS_H__

//System Header Files (A-Z)
#include <algorithm>
#include <set>
#include <random>

//Common Header Files (A-Z)
#include "DEVS-ObjectC.h"
#include "base_type.h"

//DEVS system Header Files (A-Z)
#include "CONTENT.h"
#include "MODELS.h"
#include "SIMULATORS.h"
#include "STATE_VARS.h"

//Utility Header Files (A-Z)
#include "DISPLAY.h"

// ************************************************************
// 이름: 남수만 [2016-10-12]
// 설명: 모델 테스트용
#define LOAD_MODEL( model, model_name ) \
	model* atomic_model = new model( model_name ); \
	atomic_model->executeModelTest();
// ************************************************************

/**
 * @author	남수만
 * @date	2016-11-24
 * @enum	model_window
 */
DLL_EXPORT enum model_window
{
	Ext, /*!< Enum value 외부상태천이 함수 */
	Int, /*!< Enum value 내부상태천이 함수. */
	Output /*!< Enum value 출력 함수. */
};

/**
 * @author	남수만
 * @date	2016-11-24
 * @file	ATOMIC_MODELS.h
 * @brief	ATOMIC_MODELS class
 */

class DLL_EXPORT ATOMIC_MODELS: public MODELS, public IPC
{
	typedef vector<string> StrVector;
	typedef set<MODELS*> ModelSet;

private:
	string model_name;
	StateVarsMap state_var_list;

	timetype ta;
	timetype e;
	int job_count = -1;

	/**
	 * @author	남수만
	 * @date	2016-11-24
	 * @enum	command
	 * @brief	Atomic Model 테스트 시 command_vector의 위치에 따른 값 분류
	 * @see		ATOMIC_MODELS::executeModelTest()
	 */
	enum command
	{
		port = 3, /*!< Enum value port. */
		value = 4, /*!< Enum value value. */
		elapsed_time = 5 /*!< Enum value elapsed_time. */
	};

protected:
	STATE_VARS sigma;
	STATE_VARS phase;
	int addseed = 0;
	ofstream out_text;
	bool transcript = false;
	int rndseed = -1;

public:
	ModelSet children;

	/**
	 *
	 * @enum	window
	 * @brief	displayStateVars()에서 시뮬레이션과 모델 윈도우 출력을 구분하기 위해 정의
	 *
	 * @author	남수만
	 * @date	2017-01-26
	 *
	 * @see		void ATOMIC_MODELS::displayStateVars()
	 *
	 */
	enum window
	{
		simulation = 1, /*!< Enum value simulation window. */
		modelTest = 2 /*!< Enum value model window. */
	};

public:
	ATOMIC_MODELS(); /*!< Constructor */
	~ATOMIC_MODELS();

	timetype getSigma();
	string getPhase();

	void linkSimulator( string name );
	void holdIn( string phase, timetype sigma );
	void Continue( timetype e );
	void passivate();

	virtual void externalTransitionFunc( timetype e, CONTENT x );
	virtual void internalTransitionFunc();
	virtual CONTENT outputFunc();
	virtual timetype timeAdvancedFunc();

	void executeModelTest();
	void showInitialDisplay();
	void sendInject( string port_name, StrVector value, string time );
	void sendOutput();
	void sendInternalTransition();
	void displayStateVars( window type );
	string getStateVars();
	void displayContent( CONTENT content );
	void showModelWindow( int type, CONTENT content );
	int unifrm(int min, int max, int seed);
	//DEVS-PIPE
	void generateDiagramDisplayMessage( int type, CONTENT content );
	//for makeini func
	void makeinifile(string content);

	string gensym();
	string gensym(string);
};
#endif
