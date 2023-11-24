#ifndef __COMMAND_H__
#define __COMMAND_H__

//System Header Files (A-Z)
#include <conio.h>
#include <io.h>
#include <list>
#include <string>


//Common Header Files (A-Z)
#include "DEVS-ObjectC.h"

#include "base_type.h"

//Utility Header Files (A-Z)
#include "DISPLAY.h"

#define MBASE_PATH "..\\mbase\*.cpp"

DLL_EXPORT enum menu
{
	model_test, simulation, tranformation, quit
};

DLL_EXPORT typedef list<string> File_List;

class DLL_EXPORT COMMAND
{
private:
	static int menu;

public:
	COMMAND();
	~COMMAND();

	int getMenu();
	void selectMenu();
	void getMbaseFileList();
	void displayMenu();
};
#endif
