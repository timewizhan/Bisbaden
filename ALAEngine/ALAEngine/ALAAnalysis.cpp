#include "ALAAnalysis.h"
#include "Log.h"

////////////////////////////////////////////////////////////////////////////////////////
CALAAnalysis::CALAAnalysis()
{
}

////////////////////////////////////////////////////////////////////////////////////////
CALAAnalysis::~CALAAnalysis()
{
}

////////////////////////////////////////////////////////////////////////////////////////
DWORD CALAAnalysis::ParseLanguage(FILE *pFile, ST_WRITING &refstWriting)
{
	DWORD dwRet = E_RET_SUCCESS;
	dwRet = m_ALAParse.StartParse(pFile, refstWriting);
	if (dwRet != E_RET_SUCCESS) {
		dwRet = E_RET_FAIL;
	}
	return dwRet;
}

////////////////////////////////////////////////////////////////////////////////////////
DWORD CALAAnalysis::CombineLanguage()
{
	DWORD dwRet = E_RET_SUCCESS;
	dwRet = m_ALACombination.StartCombination();
	if (dwRet != E_RET_SUCCESS) {
		dwRet = E_RET_FAIL;
	}
	return dwRet;
}

////////////////////////////////////////////////////////////////////////////////////////
DWORD CALAAnalysis::ArrangeLanguage()
{
	DWORD dwRet = E_RET_SUCCESS;
	dwRet = m_ALAArrangement.StartArrangement();
	if (dwRet != E_RET_SUCCESS) {
		dwRet = E_RET_FAIL;
	}
	return dwRet;
}

////////////////////////////////////////////////////////////////////////////////////////
DWORD CALAAnalysis::StartAnalysis(FILE *pFile, ST_WRITING &refstWriting)
{
	DebugLog("Start Analysis");
	DWORD dwRet = E_RET_SUCCESS;
	try
	{
		DebugLog("Start to parse language");
		dwRet = ParseLanguage(pFile, refstWriting);
		if (dwRet != E_RET_SUCCESS) {
			throw std::exception("Fail to parse language");
		}

		DebugLog("Start to combine language");
		dwRet = CombineLanguage();
		if (dwRet != E_RET_SUCCESS) {
			throw std::exception("Fail to combine language");
		}

		DebugLog("Start to arrange language");
		dwRet = ArrangeLanguage();
		if (dwRet != E_RET_SUCCESS) {
			throw std::exception("Fail to arrange lanuage");
		}
	}
	catch (std::exception &e)
	{
		ErrorLog(e.what());
		dwRet = E_RET_FAIL;
	}
	
	/*
		Finish Analysis
	*/
	DebugLog("Finish Analysis");
	return dwRet;
}