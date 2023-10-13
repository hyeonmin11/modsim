#ifndef __TRANSFORM_H__
#define __TRANSFORM_H__

#include <algorithm>
#include <dirent.h>
#include <direct.h>
#include <iostream>
#include <string>

// DEVS ObjectC System Headers
#include "digraph_models.h"

// DEVS ObjectC System/Transform Headers
#include "binary_tree.h"
#include "ELEMENTS.h"
#include "node.h"
#include "tinymain.h"

#include "base_type.h"

using namespace std;

/**
 *	@brief		PES 구조와 원자 모델을 통합시키는 클래스
 *	@details
 *	@author		남수만(sumannam@gmail.com)
 *	@date		2016-12-16
 *	@version	1.1
 */

class DLL_EXPORT TRANSFORM
{
	static string projectPath;
	typedef vector<NODE> ModelStructureVector;
	typedef set<string> FileSet;

private:
	const string enbasePath = "./enbase/";
	const string mbasePath = "./mbase/";

	//const string BROADCAST_MODEL = "BROADCAST"; // TODO define과 충돌
	//const string CONTROLLED_MODEL = "CONTROLLED";

	const string ASPECT_TYPE = "aspect";
	const string MULTIPLE_TYPE = "multiple";
	const string ITEM_LIST_TYPE = "list";
	const string ITEM_LINE_TYPE = "line";
	const string ITEM_MULTIPLE_TYPE = "multiple";
	const string MULTIPLE_DECOMPOSITION = "mdec";

	// Kernel Model Type
	const string MODEL_BROADCAST = "BROADCAST";
	const string MODEL_CONTROLLED = "CONTROLLED";

	ModelStructureVector model_structure_vector;
	BINARY_TREE<NODE> Binary_Tree;

	///
	string Pnode_name;
	///
	int coupledModelCnt;

	string prunedFileName;
	string rootModelName;

public:
	TRANSFORM();
	TRANSFORM( string path, string name );
	~TRANSFORM();

	string getProjectPath();
	void executeTransformation( string name );
	void convertVectortoBinaryTree();
	FileSet getEnbaseFileList();
	void loadEntityStructure( FileSet fileList );
	bool checkEnbaseFileList( FileSet fileList, string fileName );
	string getEnbasePath( string fileName );
	int getKernelModelMembers( string parent_name, string temp2 );
	string getKernelModelMemberName( string parent_name, string temp2 );
	bool isKernelModel( string parent_name, NODE item );
	bool isMultipleDecomposition( string parent_name );
};

#endif
