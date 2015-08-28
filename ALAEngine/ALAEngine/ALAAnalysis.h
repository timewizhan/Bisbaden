#ifndef _ALA_ANALYSIS_
#define _ALA_ANALYSIS_

#include "Common.h"
#include "ALAParse.h"
#include "ALACombination.h"
#include "ALAArrangement.h"

class CALAAnalysis
{
	CALAParse		m_ALAParse;
	CALACombination	m_ALACombination;
	CALAArrangement	m_ALAArrangement;
	/*
		below 3 methods, important methods
	*/
	DWORD ParseLanguage(FILE *pFile, ST_WRITING &refstWriting);
	DWORD CombineLanguage();
	DWORD ArrangeLanguage();
public:
	CALAAnalysis();
	~CALAAnalysis();

	DWORD StartAnalysis(FILE *pFile, ST_WRITING &refstWriting);
};

#endif