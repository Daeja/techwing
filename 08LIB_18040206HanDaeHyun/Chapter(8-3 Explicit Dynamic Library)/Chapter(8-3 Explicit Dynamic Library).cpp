#include "Chapter(8-3 HDH_DLIB_Math).h"
#include <iostream>
#include <Windows.h>
#include <tchar.h>		// _T("")�� ����ϱ� ���� -> ������ TEXT("")�̴�.

using namespace std;

int main()
{
	HINSTANCE hInst;
	int (*pFunc)(int ,int );
	int nA;
	int nB;
	int nResult;

	hInst = LoadLibrary(_T("Chapter(8-3 HDH_DLIB_Math).dll"));

	cout << "(1)�� (2) ����" << endl;
	cout << "(1) : ";
	cin >> nA;
	cout << "(2) : ";
	cin >> nB;
	pFunc = (int(*)(int, int))GetProcAddress(hInst, "iPower");
	nResult = pFunc(nA, nB);
	cout << nA << "�� " << nB << "������ " << nResult << "�Դϴ�." << endl;

	cout << "(1)�� (2)�� �ִ� ������� �ּ� �����" << endl;
	cout << "(1) : ";
	cin >> nA;
	cout << "(2) : ";
	cin >> nB;
	pFunc = (int(*)(int, int))GetProcAddress(hInst, "getGCD");
	nResult = pFunc(nA, nB);
	cout << "�ִ� ����� : " << nResult << endl;

	pFunc = (int(*)(int, int))GetProcAddress(hInst, "getLCM");
	nResult = pFunc(nA, nB);
	cout << "�ּ� ����� : " << nResult << endl;

	FreeLibrary(hInst);

	return 0;
}