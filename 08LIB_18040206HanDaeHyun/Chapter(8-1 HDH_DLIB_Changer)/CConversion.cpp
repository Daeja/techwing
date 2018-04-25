#include "stdafx.h"
#include "CConversion.h"

/********************************************************************************
AUTHOR		: 한대현
NAME		: CMyStringToChar
PARAMS		: [IN ] CMyString input
			  [OUT] char * pcOutput
COMMENTS	: [DLL] CMyString -> Char *로 변환
			  바인딩 된 메모리의 누수 위험있음 -> 정적으로 할당 후 사용하도록 변경
********************************************************************************/
void CMyStringToChar(CMyString & input, char * & pcOutput)
{
	if( NULL == pcOutput )
	{
		pcOutput = new char[input.getSize() + 1];
		strcpy(pcOutput, input);

		cout << "주소값 1 : " << pcOutput << endl;

		return ;
	}
	
	delete [] pcOutput;

	pcOutput = new char[input.getSize() + 1];
	strcpy(pcOutput, input);

	cout << "주소값 1 : " << pcOutput << endl;
}

/********************************************************************************
AUTHOR		: 한대현
NAME		: CharToCMyString
PARAMS		: [IN ] char * pcInput
			  [OUT] CMyString output
COMMENTS	: [DLL] Char * -> CMyString로 변환
********************************************************************************/
void CharToCMyString(char * & pcInput, CMyString & output)
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
void IntegerToCMyString(int & nInput, CMyString & output)
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
void IntegerToChar(int & nInput, char * & pcOutput)
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
void DoubleToCMyString(double & dInput, CMyString & output)
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
void DoubleToChar(double & dInput, char * & pcOutput)
{
	delete [] pcOutput;

	pcOutput = new char[STRING_BUFFER];
	sprintf(pcOutput, "%0.5f", dInput);
}