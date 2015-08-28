#ifndef _WRITING_
#define _WRITING_

#include "WordType.h"

struct ST_WORD
{
	E_WORD_TYPE	e_WordType;
	std::string	strWord;
	DWORD		dwLengthOfWord;
	DWORD		dwNumberOfWord;

	ST_WORD(DWORD dwNumberOfWord = 0) : e_WordType(E_UNKNOWN), dwNumberOfWord(0) {}
};


struct ST_SENTENCE
{
	std::vector<ST_WORD>	vecWords;
	std::string				strSentence;
	DWORD					dwLengthOfSentence;
	DWORD					dwCurrentLocation;
	DWORD					dwNumberOfSentence;

	ST_SENTENCE(DWORD dwNumberOfSentence = 0) : dwLengthOfSentence(0), dwCurrentLocation(0), dwNumberOfSentence(dwNumberOfSentence) {}
};


struct ST_WRITING
{
	std::vector<ST_SENTENCE>	vecSentences;
};

#endif