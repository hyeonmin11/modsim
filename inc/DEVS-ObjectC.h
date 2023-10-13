//System Header Files (A-Z)
#include <assert.h>
#include <iostream>
#include <string>

#ifdef GCC
#include <limits>
#include <math.h>
#elif VS2015
#endif

#include "base_type.h"

// ***********************************************************
// 이름: 남수만(sumannam@gmail.com) [2016-09-21]
// 반영 이유: 시뮬레이션 시간은 정수의 최대 값을 가지기 때문에 INT 최대 값으로 설정
//			 CO_ORDINATORS::GetMintNChildren() 내에서 min_time 설정과 ROOT_CO_ORDINATORS::restart() 내에서 시뮬레이션 종료 때 사용
#ifdef GCC
#define TIME_MAX std::numeric_limits<double>::infinity()
#elif VS2015
#define TIME_MAX 2147483647
#endif
// ***********************************************************
#define INIT_INT -9999

DLL_EXPORT typedef double timetype;

using namespace std;

// ************************************************************
//
// doxygen attribute 입력 순서
// @brief
// @details
// @author
// @date
// @version
// @remarks
//
// @param 
// @return
//
// @code
// @endcode
//
// @todo
//
// ************************************************************

// ************************************************************
// 이름: 남수만 [2016-07-29]
// 표시: 주석 설명
// TODO: 아직 하지 않은 일
// FIXME: 오동작을 일으킨다고 알려진 코드
// HACK: 아름답지 않은 해결책
// XXX: 위험! 여기 큰 문제 존재
// ************************************************************

/// ************************************************************
/// <programmer>남수만 [2016-11-09]</programmer>
/// <summary>
/// 함수 기능 설명
/// </summary>
/// <param1 name="arg1">사용 이유 설명</param> // 없으면 작성하지 않음
/// <returns>설명</returns> // 없으면 적상하지 않음
/// <examples>
/// 입력: 설명 or 없음
/// 출력: 설명 or 없음
/// </examples>
/// <history>
/// 남수만 [2016-11-09] 내용
/// </history>
/// ************************************************************

//System Header Files (A-Z)
//Common Header Files (A-Z)
//DEVS system Header Files (A-Z)
//Utility Header Files (A-Z)

//Model Header Files

//#define
//using namespace std;
//
//
//enum
//
//typedef
//
//
//class
//{
//};
