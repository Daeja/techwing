#include "CConversion.h"

/********************************************************************************
AUTHOR		: �Ѵ���
NAME		: CMyStringToChar
PARAMS		: [IN ] CMyString input
			  [OUT] char * pcOutput
COMMENTS	: [DLL] CMyString -> Char *�� ��ȯ
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
AUTHOR		: �Ѵ���
NAME		: CharToCMyString
PARAMS		: [IN ] char * pcInput
			  [OUT] CMyString output
COMMENTS	: [DLL] Char * -> CMyString�� ��ȯ
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
AUTHOR		: �Ѵ���
NAME		: IntegerToCMyString
PARAMS		: [IN ] int nInput
			  [OUT] CMyString output
COMMENTS	: [DLL] int -> CMyString�� ��ȯ
********************************************************************************/
void CConversion::IntegerToCMyString(int & nInput, CMyString & output)
{
	itoa(nInput, output, 10);
}

/********************************************************************************
AUTHOR		: �Ѵ���
NAME		: IntegerToChar
PARAMS		: [IN ] int nInput
			  [OUT] char * pcOutput
COMMENTS	: [DLL] int -> char *�� ��ȯ
********************************************************************************/
void CConversion::IntegerToChar(int & nInput, char * & pcOutput)
{
	itoa(nInput, pcOutput, 10);
}

/********************************************************************************
AUTHOR		: �Ѵ���
NAME		: DoubleToCMyString
PARAMS		: [IN ] double dInput
			  [OUT] CMyString output
COMMENTS	: [DLL] double -> CMyString�� ��ȯ
********************************************************************************/
void CConversion::DoubleToCMyString(double & dInput, CMyString & output)
{
	char * pcTempString = new char [STRING_BUFFER];

	sprintf(pcTempString, "%0.5f", dInput);

	output = pcTempString;

	delete [] pcTempString;
} 

/********************************************************************************
AUTHOR		: �Ѵ���
NAME		: DoubleToChar
PARAMS		: [IN ] double dInput
			  [OUT] char * pcOutput
COMMENTS	: [DLL] double -> char *�� ��ȯ
********************************************************************************/
void CConversion::DoubleToChar(double & dInput, char * & pcOutput)
{
	delete [] pcOutput;

	pcOutput = new char[STRING_BUFFER];
	sprintf(pcOutput, "%0.5f", dInput);
}