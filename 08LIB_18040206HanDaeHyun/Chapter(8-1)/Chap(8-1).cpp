#include "Chap(8-1).h"

int main()
{
	
	int nI = 123;
	double dJ = 123.4567;
	CMyString str;
	char * pcString = new char [STRING_BUFFER];
	CConversion conversion;

	strcpy_s(pcString, STRING_BUFFER, "Techwing");

	conversion.CharToCMyString(pcString, str);
	cout << "str : " << str << endl << "pcString : " << pcString << endl;
	conversion.CMyStringToChar(str, pcString);
	cout << "str : " << str << endl << "pcString : " << pcString << endl;
	conversion.IntegerToChar(nI, pcString);
	cout << "nI : " << nI << endl << "pcString : " << pcString << endl;
	conversion.IntegerToCMyString(nI, str);
	cout << "nI : " << nI << endl << "str : " << str << endl;
	conversion.DoubleToChar(dJ, pcString);
	cout << "dJ : " << dJ << endl << "pcString : " << pcString << endl;
	conversion.DoubleToCMyString(dJ, str);
	cout << "dJ : " << dJ << endl << "str : " << str << endl;

	delete [] pcString;

	return 0;
}