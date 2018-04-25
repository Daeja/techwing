#include <iostream>

#include "CCircle.h"
#include "CMyString.h"

#define DELETE_NO	(false)

using namespace std;

int main() {

	cout << "7-4 첫번째 문제입니다\n" << endl;

	CPoint p(5, 3);

	CCircle c1;
	CCircle c2(3);
	CCircle c3(p, 4);
	CCircle c4(9, 7, 5);

	c1.print();
	c2.print();
	c3.print();
	c4.print();

	cout << endl << endl;

	cout << "7-4 두번째 문제입니다" << endl;

	CMyString str1;
	CMyString str2("Hello");
	CMyString str3 = "World!";		// 대입연산자 이기때문에 단순 디폴트 생성자로 생성됨
	CMyString str4(str3);

	str4.SetString("Welcome", DELETE_NO);

	str1.print();
	str2.print();
	str3.print();
	str4.print();

	return 0;
}