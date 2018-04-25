#include <iostream>
#include "Chapter(8-3 HDH_DLIB_Math).h"

using namespace std;

int main()
{
	int nA = 0;
	int nB = 0;
	int nResult = 0;

	cout << "(1)의 (2) 제곱" << endl;
	cout << "(1) : ";
	cin >> nA;
	cout << "(2) : ";
	cin >> nB;

	nResult = iPower(nA, nB);
	cout << nA << "의 " << nB << "제곱은 " << nResult << "입니다." << endl;
	
	cout << "(1)과 (2)의 최대 공약수와 최소 공배수" << endl;
	cout << "(1) : ";
	cin >> nA;
	cout << "(2) : ";
	cin >> nB;

	nResult = getGCD(nA, nB);
	cout << "최대 공약수 : " << nResult << endl;
	nResult = getLCM(nA, nB);
	cout << "최소 공배수 : " << nResult << endl;
	
	return 0;
}