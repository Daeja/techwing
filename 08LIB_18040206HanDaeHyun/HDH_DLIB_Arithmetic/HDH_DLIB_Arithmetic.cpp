// HDH_DLIB_Arithmetic.cpp : DLL 응용 프로그램을 위해 내보낸 함수를 정의합니다.
//

#include "stdafx.h"
#include "HDH_DLIB_Arithmetic.h"

/********************************************************************************
AUTHOR		: 한대현
NAME		: addtioin
PARAMS		: [IN ] int nA, int nB
			  [OUT] int
COMMENTS	: [DLL] 두개의 매개변수를 통해 값을 더 한 후 반환한다.
********************************************************************************/
extern "C" HDH_DLIB_ARITHMETIC_API int addition(int nA, int nB)
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
extern "C" HDH_DLIB_ARITHMETIC_API int subtraction(int nA, int nB)
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
extern "C" HDH_DLIB_ARITHMETIC_API int multiplication(int nA, int nB)
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
extern "C" HDH_DLIB_ARITHMETIC_API int division(int nA, int nB)
{
	return nA / nB;
}