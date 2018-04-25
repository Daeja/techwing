#include <iostream>
#include "CMyString.h"

#define DELETE_NO	(false)

using namespace std;

int main()
{
	cout << "7-5 문제입니다." << endl;

	CMyString str1 = (CMyString)"Good ";
	CMyString str2 = (CMyString)"Morning";
	CMyString str3 = str1 + str2;
	CMyString str5 = (CMyString)"kkk";
	CMyString str6 = (CMyString)NULL;
	CMyString str7 = str5;

	char* pCValue = NULL;
	CMyString str0 = (CMyString)pCValue;

	cout << str1 << endl;
	cout << str2 << endl;
	cout << str3 << endl;

	str1+=str2;
	str1+=str0;
	str2 = str0 + str0;
	str2 = NULL;
	//str3 = (CMyString)NULL;
	str6 = str5 + str1;
	str7 = NULL + str5;
	str7 = str3;

	cout << str7 << endl;

	str1 = "Hello World!";

	cout << str1 << endl;

	if(str1 == str3)
	{
		cout << "Equal!" << endl;
	}

	CMyString str4;

	cout << "문자열 입력 : ";
	cin >> str4;
	cout << "입력한 문자열 : " << str4 << endl;

	cout << str3 << endl;

	cout << str6 << endl;

	return 0;
}