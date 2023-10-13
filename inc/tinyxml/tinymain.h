#ifndef __TINYMAIN_H__
#define __TINYMAIN_H__

// System Headers
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <utility>
#include <algorithm>
#include <direct.h>

// DEVS ObjectC System Headers
//#include "base_type.h"
//#include "macros.h"

// DEVS ObjectC System/Tinyxml Headers
#include "tinyxml.h"

// DEVS ObjectC System/Transform Headers
#include "node.h"
#include "TRANSFORM.h"
class NODE;

#include "binary_tree.h"

using namespace std;

DLL_EXPORT typedef list<string> Model_Info;
DLL_EXPORT typedef list<Model_Info> Model_List;

DLL_EXPORT typedef vector<string> Coupling_Info;
DLL_EXPORT typedef list<Coupling_Info> Coupling_List;
DLL_EXPORT typedef vector<NODE> MODEL_STRUCT_VECTOR;

//#ifdef NEW //2017-01-13
const string ENBASE_PATH = "\\enbase\\";
//#else
//const string ENBASE_PATH = ".\\enbase\\";
//#endif

const int ROOT = 0;
const int ENTITY_NUM = 1;
const int LIST_NUM = 2;
const int LINE_NUM = 3;
const int MULTIPLE_NUM = 4;
const int MODEL_STRUCT = 5;

const int SOURCE = 0;
const int OUTPORT = 1;
const int DESTIN = 2;
const int INPORT = 3;

const string COUPLED_MODEL = "CM";

const string DASH_DEC = "-dec";
const string UNDER_DEC = "_dec";
const string DASH_MDEC = "-mdec";
const string UNDER_MDEC = "_mdec";

DLL_EXPORT const char* getIndent( unsigned int numIndents );
DLL_EXPORT const char* getIndentAlt( unsigned int numIndents );

DLL_EXPORT int dump_attribs_to_stdout( TiXmlElement* pElement, unsigned int indent );
DLL_EXPORT void dump_to_stdout( TiXmlNode* pParent, unsigned int indent = 0 );
DLL_EXPORT void dump_to_stdout( const char* pFilename );

DLL_EXPORT void OpenFile( const string filename );
DLL_EXPORT void CloseFile();

DLL_EXPORT void WriteCoordinator( const string name, const string message, const string from, const int time );
DLL_EXPORT void WriteCoordinator( const string name, const string message, const string from, const int time, const string port, const string saying );

DLL_EXPORT void WriteSIMULATORS( const string name, const string message, const string from, const int time, const string port, const string saying );
DLL_EXPORT void WriteSIMULATORS( const string name, const int sigma, const string phase, const string job );

DLL_EXPORT void WriteAtomicIn( const string name, const int sigma, const string phase, const string port, const string job );
DLL_EXPORT void WriteAtomicOut( const string name, const int sigma, const string phase, const string port, const string job );

DLL_EXPORT void PrintAttrib( TiXmlAttribute* pAttrib );
DLL_EXPORT void FindElement( TiXmlNode* pParent, unsigned int indent = 0 );
DLL_EXPORT bool LoadXmlFile( string pFilename );

DLL_EXPORT string getEnbasePath( string file_name );
DLL_EXPORT string GetRootModelName( string file_name );

// Tranformation를 위한 함수
DLL_EXPORT MODEL_STRUCT_VECTOR getModelStructList( string file_name );
DLL_EXPORT Model_List getModelInfoList( string file_name );
DLL_EXPORT Coupling_List GetCoupldingInfoList( string file_name );
//DLL_EXPORT void MakeBinaryTree();
//DLL_EXPORT void SetProperty( string aspect_name );

// Normal Functions
DLL_EXPORT string EraseAspectName( string value );

#endif
