// HDH_DLIB_Arithmetic.cpp : DLL ���� ���α׷��� ���� ������ �Լ��� �����մϴ�.
//

#include "stdafx.h"
#include "HDH_DLIB_Arithmetic.h"

/********************************************************************************
AUTHOR		: �Ѵ���
NAME		: addtioin
PARAMS		: [IN ] int nA, int nB
			  [OUT] int
COMMENTS	: [DLL] �ΰ��� �Ű������� ���� ���� �� �� �� ��ȯ�Ѵ�.
********************************************************************************/
extern "C" HDH_DLIB_ARITHMETIC_API int addition(int nA, int nB)
{
	return nA + nB;
}

/********************************************************************************
AUTHOR		: �Ѵ���
NAME		: subtraction
PARAMS		: [IN ] int nA, int nB
			  [OUT] int
COMMENTS	: [DLL] �ΰ��� �Ű������� ���� ���� �� �� ��ȯ�Ѵ�.
********************************************************************************/
extern "C" HDH_DLIB_ARITHMETIC_API int subtraction(int nA, int nB)
{
	return nA - nB;
}

/********************************************************************************
AUTHOR		: �Ѵ���
NAME		: multiplication
PARAMS		: [IN ] int nA, int nB
			  [OUT] int
COMMENTS	: [DLL] �ΰ��� �Ű������� ���� ���� ���� �� ��ȯ�Ѵ�.
********************************************************************************/
extern "C" HDH_DLIB_ARITHMETIC_API int multiplication(int nA, int nB)
{
	return nA * nB;
}

/********************************************************************************
AUTHOR		: �Ѵ���
NAME		: division
PARAMS		: [IN ] int nA, int nB
			  [OUT] int
COMMENTS	: [DLL] �ΰ��� �Ű������� ���� ���� ���� �� ��ȯ�Ѵ�.
********************************************************************************/
extern "C" HDH_DLIB_ARITHMETIC_API int division(int nA, int nB)
{
	return nA / nB;
}