// Chapter(8-3 HDH_DLIB_Math).cpp : DLL 응용 프로그램을 위해 내보낸 함수를 정의합니다.
//

#include "stdafx.h"
#include "Chapter(8-3 HDH_DLIB_Math).h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

/********************************************************************************
AUTHOR		: 한대현
NAME		: iPower
PARAMS		: [IN ] int nA, int nB
			  [OUT] int
COMMENTS	: 거듭 제곱 계산
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
AUTHOR		: 한대현
NAME		: getGCD
PARAMS		: [IN ] int nA, int nB
			  [OUT] int
COMMENTS	: 최대 공약수 계산
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
AUTHOR		: 한대현
NAME		: getLCM
PARAMS		: [IN ] int nA, int nB
			  [OUT] int
COMMENTS	: 최소 공배수 계산
********************************************************************************/
extern "C" CHAPTER83HDH_DLIB_MATH_API int getLCM(int nA, int nB)
{
	int nGCD = getGCD(nA, nB);

	int nLCM = (nA * nB) / nGCD;

	return nLCM;
}