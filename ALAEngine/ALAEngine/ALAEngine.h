#ifndef _ALA_ENGINE_
#define _ALA_ENGINE_

#include "Common.h"
#include "ALAAnalysis.h"

/*
	ALAEngine is abbreviation of "Auto Language Analysis Engine"
	so ...
*/

class CALAEngine
{
	CALAAnalysis m_ALAAnalysis;
	ST_WRITING	m_stWriting;

	DWORD CheckVersion();
	DWORD BasicLoad();
	DWORD SetEnvironment();
	DWORD ErrorCheck();
	DWORD AccessFile(FILE **pFile, const char *pFileName);
	/*
		DB class will make 
		DWORD DBLoad();
	*/

	DWORD ShowResult();
public:
	CALAEngine();
	~CALAEngine();

	DWORD LoadEngine();
	DWORD StartEngine(const char *pFileName);
	DWORD UnLoadEngine();
};

#endif