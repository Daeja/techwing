#include <iostream>
#include "Chapter(8-3 HDH_DLIB_Math).h"

using namespace std;

int main()
{
	int nA = 0;
	int nB = 0;
	int nResult = 0;

	cout << "(1)�� (2) ����" << endl;
	cout << "(1) : ";
	cin >> nA;
	cout << "(2) : ";
	cin >> nB;

	nResult = iPower(nA, nB);
	cout << nA << "�� " << nB << "������ " << nResult << "�Դϴ�." << endl;
	
	cout << "(1)�� (2)�� �ִ� ������� �ּ� �����" << endl;
	cout << "(1) : ";
	cin >> nA;
	cout << "(2) : ";
	cin >> nB;

	nResult = getGCD(nA, nB);
	cout << "�ִ� ����� : " << nResult << endl;
	nResult = getLCM(nA, nB);
	cout << "�ּ� ����� : " << nResult << endl;
	
	return 0;
}