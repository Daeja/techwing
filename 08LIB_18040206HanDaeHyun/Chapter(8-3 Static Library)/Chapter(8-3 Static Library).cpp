#include <iostream>
#include "area.h"
#pragma comment(lib, "Chapter(8-3 HDH_SLIB_Area).lib")

using namespace std;

int main()
{
	CArea area;
	int nA = 0;
	int nB = 0;
	int nResult = 0;
	double dResult = 0;
	
	cout << "������ �Է� : ";
	cin >> nA;

	dResult = area.circle(nA);
	cout << "�������� " << nA << "cm �� ���� ���̴� " << dResult << "m^2 �Դϴ�." << endl;

	cout << "���� ũ�� �Է� : ";
	cin >> nA;
	cout << "���� ũ�� �Է� : ";
	cin >> nB;
	nResult = area.rectangle(nA, nB);
	cout << "���ΰ� " << nA << "cm, ���ΰ�" << nB << "cm �� �簢���� ���̴� "<< nResult << "m^2 �Դϴ�." << endl;

	return 0;
}