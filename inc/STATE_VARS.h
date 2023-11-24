#ifndef __STATE_VARS_H__
#define __STATE_VARS_H__

//System Header Files (A-Z)
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <typeinfo>
#include <sstream>
#include <queue>
#include <list>

#include "base_type.h"

using namespace std;

#ifdef GCC
#define INT_NAME "i"
#define UNI_NAME "unsigned int"
#define FLT_NAME "float"
#define DBL_NAME "d"
#define STR_NAME "PKc"
#elif VS2015
#define INT_NAME "int"
#define UNI_NAME "unsigned int"
#define FLT_NAME "float"
#define DBL_NAME "double"
#define STR_NAME "char const *"
#endif

#define NUMBER_TYPE( num ) ( ( ( type == INT_NAME ) || ( type == UNI_NAME ) || ( type == FLT_NAME ) || ( type == DBL_NAME ) ) ? ( true ) : ( false ) )
#define INTEGER_TYPE( num ) ( ( type == INT_NAME ) ? ( true ) : ( false ) )
#define DOUBLE_TYPE( num ) ( ( ( type == FLT_NAME ) || ( type == DBL_NAME ) ) ? ( true ) : ( false ) )

#define CHAR_CONST_TYPE( str ) ( ( type.find( STR_NAME ) != -1 ) ? ( true ) : ( false ) )
#define STD_STRING_TYPE( str ) ( ( type.find( "string") != -1 ) ? ( true ) : ( false ) )
#define STRING_TYPE( str ) ( CHAR_CONST_TYPE( type ) || STD_STRING_TYPE( type ) ? ( true ) : ( false ) )

class DLL_EXPORT STATE_VARS;

// ************************************************************
// 이름: 남수만
// 날짜: 2016-07-21
// 설명: 모든 상태 변수 저장
// 투두: multimap의 second에 STATE_VARS로 선언했는데 error가 발생하여 STATE_VARS*로 변경
DLL_EXPORT typedef multimap<string, STATE_VARS*> StateVarsMap;
// ************************************************************					
DLL_EXPORT typedef vector<STATE_VARS*> StateVarList;

class DLL_EXPORT STATE_VARS
{
	typedef vector<string> Value_List;

	// ************************************************************
	// 이름: 박동진(dongjin.park90@gmail.com) [2016-09-19]
	// 반영 이유: queue, vector, list를 사용하는 atomic model을 구현하기 위해 정의
	typedef queue<string> QUEUE;
	typedef vector<string> VECTOR;
	typedef list<string> LIST;
	// ************************************************************

private:
	int index;	// index의 역할은 STATE_VAR에서 표시를 할때 순서대로 보여주기 위함. 
				//multimap 클래스의 특성상 연관 컨테이너이므로 값이 갱신이 되면 순서가 바뀌기 때문에(처음엔 값이 입력이 되는대로 인덱스가 1 2 3 순서대로 정렬되어있으나 값이 갱신이 되면 인덱스 순서대로 정렬이 안됨) 
				//만약 인덱스 없이 출력을 할 경우 STATE_VAR의 출력값이 꼬일것이다.(ex: sigma, phase, inter-arrival-time --> inter-arrival-time,sigma,phase)
	string type;
	string var_name;
	string value;
	string model;
	static string model_name;
	static int seq;

	// ************************************************************
	// 이름: 박동진(dongjin.park90@gmail.com) [2016-08-19]
	// 반영 이유: queue를 사용하는 atomic model을 구현하기 위해 정의
	//			  string 변수는 queue에 들어있는 다음 job-id의 출력
	//			  포맷을 위해 정의
	QUEUE queue;
	string queue_temp;
	// ************************************************************

protected:
	static StateVarsMap state_var_map;

public:
	STATE_VARS();
	~STATE_VARS();

	void setVarName( string name );
	void setModelName( string name );
	void insertStateVarmptyQueue();

	// ************************************************************
	// 이름: 박동진(dongjin.park90@gmail.com) [2016-08-19]
	// 반영 이유: queue에 job-id를 삽입/추출 및 queue의 상태를 확인하기 위한 메소드 정의
	void addq( string x );
	string deleteq();
	int checkEmptyQueue();
	// ************************************************************

	string getVarName();
	string getValue();
	string getV();
	string getModel();

	StateVarList getStateVarList( string name );
	StateVarList getStateVarListall();
	string getStateVarstring(string name);

	void setVector( Value_List list );
	void operator()( string name );
	bool operator==( STATE_VARS* var );
	bool operator==( string str );
	void operator+=(int var);

public:
	// ************************************************************
	// 이름: 남수만
	// 날짜: 2016-07-25
	// 반영이유: 정확한 이유를 알 수 없지만 아래 소스 내용을 state_vars.cpp에 넣으면 링크 오류 발생
	template<typename T>
	void operator=( T data )
	{
		type = typeid( data ).name();

#ifdef GCC
		if ( ( type == INT_NAME ) || ( type == UNI_NAME ) || ( type == FLT_NAME ) || ( type == DBL_NAME ) )
		{
			stringstream ss;
			ss << data;
			value = ss.str();
		}
		else if ( type.find( "string" ) != -1 )
			value = data;
		else if ( type == STR_NAME )
			value = data;
		else
			cout << type << ": 매칭되는 데이터 타입이 없습니다." << endl;
#elif VS2015
		if ( NUMBER_TYPE( type ) )
		{
			stringstream ss;
			ss << data;
			value = ss.str();
		}
		else if ( STRING_TYPE( type ) )
		value = data;
		else
		{
			DEBUG_COUT( "매칭되는 데이터 타입이 없습니다." );
		}
#endif

		insertStateVarmptyQueue();
	}
	// ************************************************************
};

#endif
