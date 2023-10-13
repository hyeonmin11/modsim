#ifndef __IPC_H__
#define __IPC_H__
#define BUF_SIZE 1024

#include "windows.h"
#include "DEVS-ObjectC.h"

class IPC
{
private:
	static HANDLE hPipe;

	LPTSTR lpvMessage;
	BOOL fSuccess;
	TCHAR readDataBuf[BUF_SIZE + 1];
	DWORD pipeMode;
	DWORD cbToWrite;
	DWORD cbWritten;
	DWORD dwMode;
	LPTSTR lpszPipename;

public:
	// 持失切, 社瑚切
	IPC();
	~IPC();

	void sendDiagramDisplayMessage( string message );
};
#endif
