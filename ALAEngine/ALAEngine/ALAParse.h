#ifndef _ALA_PARSE_
#define _ALA_PARSE_

#include "Common.h"

class CALAParse
{
	/*
		Important Method
	*/
	DWORD ParseByWriting();
	DWORD ParseByLine(FILE *pFile, ST_WRITING &refstWriting);
	DWORD ParseByWord(ST_WRITING &refstWriting);

	/*
		Assistant Method
	*/
	DWORD ParseByString(ST_SENTENCE &refstSentence, std::string strLineString);

public:
	CALAParse();
	~CALAParse();

	DWORD StartParse(FILE *pFile, ST_WRITING &refstWriting);
};


#endif