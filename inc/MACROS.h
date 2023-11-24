#ifndef __MACROS_H__
#define __MACROS_H__

#include "base_type.h"
#include "DEVS-ObjectC.h"

//System Header Files (A-Z)
#include <iostream>
#include <ctime>
#include <string>
#include <sstream>
#include <vector>
#include <direct.h>

#ifdef GCC
#include <cmath>
#include <float.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#elif VS2015
#endif

#include "DISPLAY.h"

#define ERR_NUM -9
#define INF			"1.#INF"

using namespace std;

//typedef vector<string> StrVector;

/**
 *	@author 남수만
 *	@date	2016-12-13
 *	@bug	Class or cpp가 없는 헤더 파일은 doxygen으로 변환이 안됨
 */

/**
 *
 *	@fn			int STR_TO_INT( string str )
 *	@brief		String에서 Integer로 전환
 *
 *	@author 	남수만
 *	@date		2016-12-13
 *
 *	@param		str 전환할 스트링
 *
 *	@return	정수
 *
 *	@code
 *		// 사용 예
 *		// int num = STR_TO_INT( "123" );
 *	@endcode
 *
 *	@remarks	DLL를 생성하기 위해 G++ 사용으로 전처리문 조건 추가[2017-03-13; 남수만] \n
 *
 */
DLL_EXPORT inline int STR_TO_INT( string str )
{
#ifdef GCC
	int rtv = atoi( str.c_str() );
	return rtv;
#elif VS2015
	return atoi( str.c_str() );
#endif
}

/**
 *
 *	@fn			inline double STR_TO_DBL( string str )
 *	@brief		String에서 Double로 전환
 *
 *	@author 	남수만
 *	@date		2016-12-13
 *
 *	@param		str 전환할 스트링
 *
 *	@return		double
 *
 *	@remarks	DLL를 생성하기 위해 G++ 사용으로 전처리문 조건 추가[2017-03-13; 남수만] \n
 *
 */
DLL_EXPORT inline double STR_TO_DBL( string str )
{
#ifdef GCC
	if ( str == "1.#INF" )
		return INFINITY;
	double rtv = atof( str.c_str() );
	return rtv;
#elif VS2015
	return stod( str.c_str() );
#endif
}

/**
 *
 *	@fn			inline string INT_TO_STR( int num )
 *	@brief		정수에서 스트링으로 전환
 *
 *	@author 	남수만
 *	@date		2016-12-13
 *
 *	@param		str 전환할 스트링
 *
 *	@return		double
 *
 *	@remarks	DLL를 생성하기 위해 G++ 사용으로 전처리문 조건 추가[2017-03-13; 남수만] \n
 *
 */
DLL_EXPORT inline string INT_TO_STR( int num )
{
#ifdef GCC
	stringstream out;
	out << num;

	string rtv = out.str();
	return rtv;
#elif VS2015
	return to_string( num );
#endif
}

DLL_EXPORT inline string TIME_TO_STR( timetype time )
{
	if ( time == DBL_MAX )
		return "∞";

	ostringstream time_stream;
	time_stream << time;
	return time_stream.str();
}

/**
 *
 *	@fn			inline timetype STR_TO_TIME( string time )
 *	@brief		스트링에서 시간으로 전환
 *
 *	@author 	남수만
 *	@date		2016-12-13
 *
 *	@param		str 전환할 스트링
 *
 *	@return		timetype
 *
 *	@remarks	DLL를 생성하기 위해 G++ 사용으로 전처리문 조건 추가[2017-03-13; 남수만] \n
 *
 */
DLL_EXPORT inline timetype STR_TO_TIME( string time )
{
#ifdef GCC
	if ( time == "" )
		return 0;

	return STR_TO_DBL( time );;
#elif VS2015
	if ( time == "" )
	return 0;

	char* ctime = new char[time.size() + 1];
	strcpy_s( ctime, time.size() + 1, time.c_str() );

	return atof( ctime );
#endif
}

/**
 *	@fn 		inline string CURRENT_DATE_TIME()
 *	@brief	파일 이름을 생성하기 위해 현재 날짜와 시간 추출
 *
 *	@author 남수만
 *	@date		2016-12-13
 *
 *	@return	string
 *
 *	@remarks	DLL를 생성하기 위해 G++ 사용으로 전처리문 조건 추가[2017-03-13; 남수만] \n
 *						'localtime_s( &timeinfo, &rawtime );'에서 소스에서 빌드 시 C4996 오류 발생으로 프로젝트 속성 전처리기에서 _CRT_SECURE_NO_WARNINGS 추가[2016-07-29; 남수만]
 *
 */
DLL_EXPORT inline string CURRENT_DATE_TIME()
{
	time_t rawtime;
	string buffer = "";
	
#ifdef GCC
	struct tm* timeinfo;
	rawtime = time( NULL );
	timeinfo = localtime( &rawtime );

	buffer += INT_TO_STR( timeinfo->tm_year + 1900 ) + "-";
	buffer += INT_TO_STR( timeinfo->tm_mon + 1 ) + "-";
	buffer += INT_TO_STR( timeinfo->tm_mday ) + "-";
	buffer += INT_TO_STR( timeinfo->tm_hour ) + "-";
	buffer += INT_TO_STR( timeinfo->tm_min ) + "-";
	buffer += INT_TO_STR( timeinfo->tm_sec );
#elif VS2015
	struct tm timeinfo;
	rawtime = time( NULL );
	localtime_s( &timeinfo, &rawtime );

	buffer += INT_TO_STR( timeinfo.tm_year + 1900 ) + "-";
	buffer += INT_TO_STR( timeinfo.tm_mon + 1 ) + "-";
	buffer += INT_TO_STR( timeinfo.tm_mday ) + "-";
	buffer += INT_TO_STR( timeinfo.tm_hour ) + "-";
	buffer += INT_TO_STR( timeinfo.tm_min ) + "-";
	buffer += INT_TO_STR( timeinfo.tm_sec );
#endif

	return buffer;
}

/**
 *
 *	@fn			inline vector<string> STR_TO_VECTOR( string message, string token )
 *	@brief	스트링에서 vector로 전환
 *
 *	@author 남수만
 *	@date		2016-12-13
 *
 *	@param	str 전환할 스트링
 *
 *	@return	timetype
 *
 *	@remarks	DLL를 생성하기 위해 G++ 사용으로 전처리문 조건 추가[2017-03-13; 남수만] \n
 *
 *	@todo		GCC에서 strcpy를 다른 명령문으로 변경[2017-03-13; 남수만]
 *
 */
DLL_EXPORT inline vector<string> STR_TO_VECTOR( string message, string token )
{
	char* ptr;
	char* msg = new char[message.size() + 1];
	char* tok = new char[token.size() + 1];
	char* next_token = NULL;

	vector<string> vector;

#ifdef GCC
	strcpy( msg, message.c_str() );
	strcpy( tok, token.c_str() );

	ptr = strtok( msg, tok );
	while ( ptr != NULL )
	{
		vector.push_back( ptr );
		ptr = strtok( NULL, tok );
	}
#elif VS2015
	strcpy_s( msg, message.size() + 1, message.c_str() );
	strcpy_s( tok, token.size() + 1, token.c_str() );

	ptr = strtok_s( msg, tok, &next_token );
	while ( ptr != NULL )
	{
		vector.push_back( ptr );
		ptr = strtok_s( NULL, tok, &next_token );
	}
#endif
	
	delete[] msg;
	delete[] tok;

	return vector;
}

DLL_EXPORT inline string GetCurrentPath()
{
	char buff[1024];
	string projectPath = _getcwd( buff, 1024 );

	return projectPath;
}
#endif
