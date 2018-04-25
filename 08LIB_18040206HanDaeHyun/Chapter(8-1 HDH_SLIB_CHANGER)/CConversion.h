#pragma once
#include <iostream>

#include "CMyString.h"
#include "CLogger.h"
#include "CTimer.h"

#define INITIALIZE		( 1 )
#define STRING_BUFFER	( 100 )

class CConversion
{
public:
	void CMyStringToChar(CMyString & input, char * & pcOutput);
	void CharToCMyString(char * & pcInput, CMyString & output);
	void IntegerToCMyString(int & nInput, CMyString & output);
	void IntegerToChar(int & nInput, char * & pcOutput);
	void DoubleToCMyString(double & dInput, CMyString & output);
	void DoubleToChar(double & dInput, char * & pcOutput);
};

