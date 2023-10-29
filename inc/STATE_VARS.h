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
//#include <stack>
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
// �̸�: ������
// ��¥: 2016-07-21
// ����: ��� ���� ���� ����
// ����: multimap�� second�� STATE_VARS�� �����ߴµ� error�� �߻��Ͽ� STATE_VARS*�� ����
DLL_EXPORT typedef multimap<string, STATE_VARS*> StateVarsMap;
// ************************************************************					
DLL_EXPORT typedef vector<STATE_VARS*> StateVarList;

class DLL_EXPORT STATE_VARS
{
	typedef vector<string> Value_List;

	// ************************************************************
	// �̸�: �ڵ���(dongjin.park90@gmail.com) [2016-09-19]
	// �ݿ� ����: queue, vector, list�� ����ϴ� atomic model�� �����ϱ� ���� ����
	typedef queue<string> QUEUE;
	//typedef stack<string> STACK;
	typedef vector<string> VECTOR;
	typedef list<string> LIST;
	// ************************************************************

private:
	int index;	// index�� ������ STATE_VAR���� ǥ�ø� �Ҷ� ������� �����ֱ� ����. 
				//multimap Ŭ������ Ư���� ���� �����̳��̹Ƿ� ���� ������ �Ǹ� ������ �ٲ�� ������(ó���� ���� �Է��� �Ǵ´�� �ε����� 1 2 3 ������� ���ĵǾ������� ���� ������ �Ǹ� �ε��� ������� ������ �ȵ�) 
				//���� �ε��� ���� ����� �� ��� STATE_VAR�� ��°��� ���ϰ��̴�.(ex: sigma, phase, inter-arrival-time --> inter-arrival-time,sigma,phase)
	string type;
	string var_name;
	string value;
	string model;
	static string model_name;
	static int seq;

	// ************************************************************
	// �̸�: �ڵ���(dongjin.park90@gmail.com) [2016-08-19]
	// �ݿ� ����: queue�� ����ϴ� atomic model�� �����ϱ� ���� ����
	//			  string ������ queue�� ����ִ� ���� job-id�� ���
	//			  ������ ���� ����
	QUEUE queue;
	string queue_temp;

	//STACK stack;
	//string stack_temp;
	// ************************************************************

protected:
	static StateVarsMap state_var_map;

public:
	STATE_VARS();
	~STATE_VARS();

	void setVarName( string name );
	void setModelName( string name );
	void insertStateVarmptyQueue();
	//void insertStateVarmptyStack();
	// ************************************************************
	// �̸�: �ڵ���(dongjin.park90@gmail.com) [2016-08-19]
	// �ݿ� ����: queue�� job-id�� ����/���� �� queue�� ���¸� Ȯ���ϱ� ���� �޼ҵ� ����
	void addq( string x );
	string deleteq();
	int checkEmptyQueue();

	//void adds( string x );
	//string deletes();
	//int checkEmptyStack();
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
	// �̸�: ������
	// ��¥: 2016-07-25
	// �ݿ�����: ��Ȯ�� ������ �� �� ������ �Ʒ� �ҽ� ������ state_vars.cpp�� ������ ��ũ ���� �߻�
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
			cout << type << ": ��Ī�Ǵ� ������ Ÿ���� �����ϴ�." << endl;
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
			DEBUG_COUT( "��Ī�Ǵ� ������ Ÿ���� �����ϴ�." );
		}
#endif

		insertStateVarmptyQueue();
		//insertStateVarmptyStack();
	}
	// ************************************************************
};

#endif
