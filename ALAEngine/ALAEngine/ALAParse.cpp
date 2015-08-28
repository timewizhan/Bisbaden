#include "ALAParse.h"
#include "Log.h"

#define MAX_LINE_BUFFER 256

////////////////////////////////////////////////////////////////////////////////////////
CALAParse::CALAParse()
{

}

////////////////////////////////////////////////////////////////////////////////////////
CALAParse::~CALAParse()
{

}


DWORD CALAParse::ParseByString(ST_SENTENCE &refstSentence, std::string strLineString)
{
	/*
		Parse by word spacing
	*/
	DWORD dwFirstCharOfString = 0, dwLastCharOfString = 0;
	DWORD dwLengthOfString = strLineString.length();
	DWORD dwNumberOfWord = 1;
	while (1)
	{
		if (dwLastCharOfString >= dwLengthOfString) {
			break;
		}

		dwLastCharOfString = strLineString.find_first_of(" ", dwFirstCharOfString);
		if (dwLastCharOfString == std::string::npos) {
			/*
				if there is not space, this sentence is one word
			*/
			dwLastCharOfString = dwLengthOfString;
		}

		std::string strWord;
		strWord = strLineString.substr(dwFirstCharOfString, dwLastCharOfString - dwFirstCharOfString);
		/*
			Word Data Setting
		*/
		ST_WORD stWord;
		stWord.strWord = strWord;
		stWord.dwNumberOfWord = dwNumberOfWord;
		stWord.dwLengthOfWord = stWord.strWord.length();

		refstSentence.vecWords.push_back(stWord);
		dwFirstCharOfString = dwLastCharOfString + 1;
		
	}

	return E_RET_SUCCESS;
}

////////////////////////////////////////////////////////////////////////////////////////
DWORD CALAParse::ParseByWriting()
{
	return E_RET_SUCCESS;
}

////////////////////////////////////////////////////////////////////////////////////////
DWORD CALAParse::ParseByLine(FILE *pFile, ST_WRITING &refstWriting)
{
	DWORD dwRet = E_RET_SUCCESS;
	char szBuf[MAX_LINE_BUFFER] = { 0 };
	DWORD dwNumberOfSentence = 1;
	while (::fgets(szBuf, MAX_LINE_BUFFER, pFile))
	{
		/*
			Sentence Data Setting
		*/
		ST_SENTENCE stSentence(dwNumberOfSentence);
		stSentence.strSentence			= szBuf;
		stSentence.dwLengthOfSentence	= stSentence.strSentence.length();
		refstWriting.vecSentences.push_back(stSentence);
		::memset(szBuf, 0x00, MAX_LINE_BUFFER);
		dwNumberOfSentence++;
	}

	return dwRet;
}

////////////////////////////////////////////////////////////////////////////////////////
DWORD CALAParse::ParseByWord(ST_WRITING &refstWriting)
{
	DWORD dwRet = E_RET_SUCCESS;

	std::vector<ST_SENTENCE>::iterator vecIter;
	for (vecIter = refstWriting.vecSentences.begin(); vecIter != refstWriting.vecSentences.end(); vecIter++)
	{
		std::string strTemp = vecIter->strSentence;
		dwRet = ParseByString((*vecIter), strTemp);
		if (dwRet != E_RET_SUCCESS) {
			ErrorLog("Fail to parse by string [%s]", strTemp.c_str());
			break;
		}
	}

	return dwRet;
}

////////////////////////////////////////////////////////////////////////////////////////
DWORD CALAParse::StartParse(FILE *pFile, ST_WRITING &refstWriting)
{
	DWORD dwRet = E_RET_SUCCESS;
	try
	{
		DebugLog("Start to parse by writing");
		dwRet = ParseByWriting();
		if (dwRet != E_RET_SUCCESS) {
			throw std::exception("Fail to parse by writing");
		}

		DebugLog("Start to parse by line");
		dwRet = ParseByLine(pFile, refstWriting);
		if (dwRet != E_RET_SUCCESS) {
			throw std::exception("Fail to parse by line");
		}

		DebugLog("Start to parse by word");
		dwRet = ParseByWord(refstWriting);
		if (dwRet != E_RET_SUCCESS) {
			throw std::exception("Fail to parse by word");
		}
	}
	catch (std::exception &e)
	{
		ErrorLog(e.what());
		dwRet = E_RET_FAIL;
	}
	/*
		Finish Parse
	*/
	DebugLog("Finish Parse");
	return dwRet;
}
