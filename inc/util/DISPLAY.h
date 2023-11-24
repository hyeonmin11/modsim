#ifndef __DISPLAY_H__
#define __DISPLAY_H__

#include <conio.h>
#include <iostream>
#include <string>

using namespace std;

// COUT
const string BLANK = " ";
const string DASH = "-";

// Common
#define COUT_PARTITION cout << "-----------------------------------------------" << endl
#define COUT( value ) cout << (value) << endl
#define COUT_ENTER cout << endl

#define COUT_ERROR1( msg ) cout << (msg) << endl
#define COUT_ERROR2( value, msg ) cout << "[ " << value << " ]" << (msg) << endl

// DEBUG
#define DEBUG_INFO cout << __LINE__ << " " << __FUNCTION__ << endl
#define DEBUG_COUT( value ) cout << "DEBUG_COUT\t" << #value << ": "<< (value) << endl
#define DEBUG_DISPLAY( str, value ) cout << ( str ) << ": " << (value) << endl

// 메뉴
const string MENU_00 = "DEVS-ObjectC 2.0";
const string MENU_01 = "Model Teat: 'm' or 'M'";
const string MENU_02 = "Simualtion: 's' or 'S'";
const string MENU_03 = "Transformation: 't' or 'T'";
const string MENU_04 = "Quit: 'q' or 'Q'";
const string MENU_05 = "Input Command: ";

// Error Message
const string INPUT_AGAIN = "Input Again!!!";

const string ERR_TRANSFORM_01 = "Element already in the tree";
const string ERR_TRANSFORM_02 = "brother bt_node is empty!";
const string ERR_TRANSFORM_03 = "Tree is empty";
const string ERR_TRANSFORM_04 = "MBASE 내에 해당 모델 정보 없음";

// TRANSFORM
const string TRANSF_DISPLAY_001 = "Input load-entstr: ";
const string TRANSF_DISPLAY_002 = "entstr list as follows: ";
const string TRANSF_DISPLAY_003 = "The file doesn't exist!!!";

void AUTO_DISPLAY();
void showCommandKey();

#endif
