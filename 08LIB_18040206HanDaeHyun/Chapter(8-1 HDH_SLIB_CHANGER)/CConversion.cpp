#include "CConversion.h"

/********************************************************************************
AUTHOR		: 한대현
NAME		: CMyStringToChar
PARAMS		: [IN ] CMyString input
			  [OUT] char * pcOutput
COMMENTS	: [DLL] CMyString -> Char *로 변환
********************************************************************************/
void CConversion::CMyStringToChar(CMyString & input, char * & pcOutput)
{
	if( NULL == pcOutput )
	{
		pcOutput = new char[input.getSize() + 1];
		strcpy(pcOutput, input);

		return ;
	}
	
	delete [] pcOutput;

	pcOutput = new char[input.getSize() + 1];
	strcpy(pcOutput, input);
}

/********************************************************************************
AUTHOR		: 한대현
NAME		: CharToCMyString
PARAMS		: [IN ] char * pcInput
			  [OUT] CMyString output
COMMENTS	: [DLL] Char * -> CMyString로 변환
********************************************************************************/
void CConversion::CharToCMyString(char * & pcInput, CMyString & output)
{
	if( NULL == pcInput )
	{
		pcInput = new char[ INITIALIZE ];
		pcInput[INITIALIZE - 1] = '0';

		return ;
	}

	output = pcInput;
}

/********************************************************************************
AUTHOR		: 한대현
NAME		: IntegerToCMyString
PARAMS		: [IN ] int nInput
			  [OUT] CMyString output
COMMENTS	: [DLL] int -> CMyString로 변환
********************************************************************************/
void CConversion::IntegerToCMyString(int & nInput, CMyString & output)
{
	itoa(nInput, output, 10);
}

/********************************************************************************
AUTHOR		: 한대현
NAME		: IntegerToChar
PARAMS		: [IN ] int nInput
			  [OUT] char * pcOutput
COMMENTS	: [DLL] int -> char *로 변환
********************************************************************************/
void CConversion::IntegerToChar(int & nInput, char * & pcOutput)
{
	itoa(nInput, pcOutput, 10);
}

/********************************************************************************
AUTHOR		: 한대현
NAME		: DoubleToCMyString
PARAMS		: [IN ] double dInput
			  [OUT] CMyString output
COMMENTS	: [DLL] double -> CMyString로 변환
********************************************************************************/
void CConversion::DoubleToCMyString(double & dInput, CMyString & output)
{
	char * pcTempString = new char [STRING_BUFFER];

	sprintf(pcTempString, "%0.5f", dInput);

	output = pcTempString;

	delete [] pcTempString;
} 

/********************************************************************************
AUTHOR		: 한대현
NAME		: DoubleToChar
PARAMS		: [IN ] double dInput
			  [OUT] char * pcOutput
COMMENTS	: [DLL] double -> char *로 변환
********************************************************************************/
void CConversion::DoubleToChar(double & dInput, char * & pcOutput)
{
	delete [] pcOutput;

	pcOutput = new char[STRING_BUFFER];
	sprintf(pcOutput, "%0.5f", dInput);
}