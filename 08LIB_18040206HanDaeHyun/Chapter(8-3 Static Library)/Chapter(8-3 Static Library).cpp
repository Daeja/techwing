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
	
	cout << "반지름 입력 : ";
	cin >> nA;

	dResult = area.circle(nA);
	cout << "반지름이 " << nA << "cm 인 원의 넓이는 " << dResult << "m^2 입니다." << endl;

	cout << "가로 크기 입력 : ";
	cin >> nA;
	cout << "세로 크기 입력 : ";
	cin >> nB;
	nResult = area.rectangle(nA, nB);
	cout << "가로가 " << nA << "cm, 세로가" << nB << "cm 인 사각형의 넓이는 "<< nResult << "m^2 입니다." << endl;

	return 0;
}