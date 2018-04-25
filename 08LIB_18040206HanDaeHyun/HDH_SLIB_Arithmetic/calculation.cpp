#include "calculation.h"

/********************************************************************************
AUTHOR		: 한대현
NAME		: addtioin
PARAMS		: [IN ] int nA, int nB
			  [OUT] int
COMMENTS	: [DLL] 두개의 매개변수를 통해 값을 더 한 후 반환한다.
********************************************************************************/
int CCalculation::addition(int nA, int nB)
{
	return nA + nB;
}

/********************************************************************************
AUTHOR		: 한대현
NAME		: subtraction
PARAMS		: [IN ] int nA, int nB
			  [OUT] int
COMMENTS	: [DLL] 두개의 매개변수를 통해 값을 뺀 후 반환한다.
********************************************************************************/
int CCalculation::subtraction(int nA, int nB)
{
	return nA - nB;
}

/********************************************************************************
AUTHOR		: 한대현
NAME		: multiplication
PARAMS		: [IN ] int nA, int nB
			  [OUT] int
COMMENTS	: [DLL] 두개의 매개변수를 통해 값을 곱한 후 반환한다.
********************************************************************************/
int CCalculation::multiplication(int nA, int nB)
{
	return nA * nB;
}

/********************************************************************************
AUTHOR		: 한대현
NAME		: division
PARAMS		: [IN ] int nA, int nB
			  [OUT] int
COMMENTS	: [DLL] 두개의 매개변수를 통해 값을 나눈 후 반환한다.
********************************************************************************/
int CCalculation::division(int nA, int nB)
{
	return nA / nB;
}