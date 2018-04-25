#include "Chapter(8-3 HDH_DLIB_Math).h"
#include <iostream>
#include <Windows.h>
#include <tchar.h>		// _T("")를 사용하기 위함 -> 원형은 TEXT("")이다.

using namespace std;

int main()
{
	HINSTANCE hInst;
	int (*pFunc)(int ,int );
	int nA;
	int nB;
	int nResult;

	hInst = LoadLibrary(_T("Chapter(8-3 HDH_DLIB_Math).dll"));

	cout << "(1)의 (2) 제곱" << endl;
	cout << "(1) : ";
	cin >> nA;
	cout << "(2) : ";
	cin >> nB;
	pFunc = (int(*)(int, int))GetProcAddress(hInst, "iPower");
	nResult = pFunc(nA, nB);
	cout << nA << "의 " << nB << "제곱은 " << nResult << "입니다." << endl;

	cout << "(1)과 (2)의 최대 공약수와 최소 공배수" << endl;
	cout << "(1) : ";
	cin >> nA;
	cout << "(2) : ";
	cin >> nB;
	pFunc = (int(*)(int, int))GetProcAddress(hInst, "getGCD");
	nResult = pFunc(nA, nB);
	cout << "최대 공약수 : " << nResult << endl;

	pFunc = (int(*)(int, int))GetProcAddress(hInst, "getLCM");
	nResult = pFunc(nA, nB);
	cout << "최소 공배수 : " << nResult << endl;

	FreeLibrary(hInst);

	return 0;
}