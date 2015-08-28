#include "Common.h"
#include "ALAEngine.h"
#include "Log.h"


int main(int argc, char *argv[])
{
	if (argc < 2) {
		DebugLog("Usage : [FileName]");
		return 0;
	}

	DebugLog("*****************************************");
	DebugLog("*********** ALA Engine Start ************");
	DebugLog("*****************************************");

	std::string strFileName;
	strFileName = argv[1];

	CALAEngine ALAEngine;
	DWORD dwRet;
	try
	{
		dwRet = ALAEngine.LoadEngine();
		if (dwRet != E_RET_SUCCESS) {
			throw std::exception("Fail to Load Engine");
		}

		dwRet = ALAEngine.StartEngine(strFileName.c_str());
		if (dwRet != E_RET_SUCCESS) {
			throw std::exception("Fail to Start Engine");
		}
		
		dwRet = ALAEngine.UnLoadEngine();
		if (dwRet != E_RET_SUCCESS) {
			throw std::exception("Fail to Unload Engine");
		}
	}
	catch (std::exception &e)
	{
		ErrorLog(e.what());
		/*
			Abnormally finished
		*/
	}
	
	/*
		Normally finished
	*/
	DebugLog("*****************************************");
	DebugLog("********* Normally finished *************");
	DebugLog("*****************************************");
	return 0;
}