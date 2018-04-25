#include "Explicit Dynamic Library.h"

/********************************************************************************
AUTHOR		: 한대현
NAME		: usingLib
PARAMS		: [IN ] int nA, int nB
			  [OUT] void
COMMENTS	: [DLL] 라이브러리 사용
********************************************************************************/
void usingLib(int nA, int nB)
{
	HINSTANCE hInst;
	int (*pFunc)(int ,int );

	if(NULL == (hInst = LoadLibrary(_T("HDH_DLIB_Arithmetic.dll"))))
	{
		return ;
	}
	
	if(NULL == (pFunc = (int(*)(int, int))GetProcAddress(hInst, "addition")))
	{
		return ;
	}
	std::cout << nA << " + " << nB << " = " << pFunc(nA, nB) << std::endl;

	if(NULL == (pFunc = (int(*)(int, int))GetProcAddress(hInst, "subtraction")))
	{
		return ;
	}
	std::cout << nA << " - " << nB << " = " << pFunc(nA, nB) << std::endl;

	if(NULL == (pFunc = (int(*)(int, int))GetProcAddress(hInst, "multiplication")))
	{
		return ;
	}
	std::cout << nA << " * " << nB << " = " << pFunc(nA, nB) << std::endl;

	if(NULL == (pFunc = (int(*)(int, int))GetProcAddress(hInst, "division")))
	{
		return ;
	}
	std::cout << nA << " / " << nB << " = " << pFunc(nA, nB) << std::endl;

	FreeLibrary(hInst);
}