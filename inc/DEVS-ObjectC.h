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
// �̸�: ������(sumannam@gmail.com) [2016-09-21]
// �ݿ� ����: �ùķ��̼� �ð��� ������ �ִ� ���� ������ ������ INT �ִ� ������ ����
//			 CO_ORDINATORS::GetMintNChildren() ������ min_time ������ ROOT_CO_ORDINATORS::restart() ������ �ùķ��̼� ���� �� ���
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
// doxygen attribute �Է� ����
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
// �̸�: ������ [2016-07-29]
// ǥ��: �ּ� ����
// TODO: ���� ���� ���� ��
// FIXME: �������� ����Ų�ٰ� �˷��� �ڵ�
// HACK: �Ƹ����� ���� �ذ�å
// XXX: ����! ���� ū ���� ����
// ************************************************************

/// ************************************************************
/// <programmer>������ [2016-11-09]</programmer>
/// <summary>
/// �Լ� ��� ����
/// </summary>
/// <param1 name="arg1">��� ���� ����</param> // ������ �ۼ����� ����
/// <returns>����</returns> // ������ �������� ����
/// <examples>
/// �Է�: ���� or ����
/// ���: ���� or ����
/// </examples>
/// <history>
/// ������ [2016-11-09] ����
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
