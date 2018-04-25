#include <iostream>
#include"CConversion.h"

#define TIME (3.0)

int main()
{
	int nI = 123;
	double dJ = 123.4567;
	CMyString str;
	char * pcString = new char [STRING_BUFFER];

	CTimer timer(TIME);
	CLogger logger();

	strcpy_s(pcString, STRING_BUFFER, "Techwing");

	CharToCMyString(pcString, str);
	cout << "str : " << str << endl << "pcString : " << pcString << endl;
	CMyStringToChar(str, pcString);
	cout << "str : " << str << endl << "pcString : " << pcString << endl;
	cout << "ÁÖ¼Ò°ª 2 : " << &pcString << endl;
	IntegerToChar(nI, pcString);
	cout << "nI : " << nI << endl << "pcString : " << pcString << endl;
	IntegerToCMyString(nI, str);
	cout << "nI : " << nI << endl << "str : " << str << endl;
	DoubleToChar(dJ, pcString);
	cout << "dJ : " << dJ << endl << "pcString : " << pcString << endl;
	DoubleToCMyString(dJ, str);
	cout << "dJ : " << dJ << endl << "str : " << str << endl;

	delete [] pcString;

	return 0;
}