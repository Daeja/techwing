// Chapter(8-3 HDH_DLIB_Math).cpp : DLL ���� ���α׷��� ���� ������ �Լ��� �����մϴ�.
//

#include "stdafx.h"
#include "Chapter(8-3 HDH_DLIB_Math).h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

/********************************************************************************
AUTHOR		: �Ѵ���
NAME		: iPower
PARAMS		: [IN ] int nA, int nB
			  [OUT] int
COMMENTS	: �ŵ� ���� ���
********************************************************************************/
extern "C" CHAPTER83HDH_DLIB_MATH_API int iPower(int nA, int nB)
{
	int nResult = 1;

	for(int nI = 0; nI < nB; nI++)
	{
		nResult *= nA;
	}

	return nResult;

}

/********************************************************************************
AUTHOR		: �Ѵ���
NAME		: getGCD
PARAMS		: [IN ] int nA, int nB
			  [OUT] int
COMMENTS	: �ִ� ����� ���
********************************************************************************/
extern "C" CHAPTER83HDH_DLIB_MATH_API int getGCD(int nA, int nB)
{
	if( nA < nB )
	{
		return getGCD(nB, nA);
	}

	if(nB == 0)
	{
		return nA;
	}

	return getGCD(nB, (nA % nB));
}

/********************************************************************************
AUTHOR		: �Ѵ���
NAME		: getLCM
PARAMS		: [IN ] int nA, int nB
			  [OUT] int
COMMENTS	: �ּ� ����� ���
********************************************************************************/
extern "C" CHAPTER83HDH_DLIB_MATH_API int getLCM(int nA, int nB)
{
	int nGCD = getGCD(nA, nB);

	int nLCM = (nA * nB) / nGCD;

	return nLCM;
}