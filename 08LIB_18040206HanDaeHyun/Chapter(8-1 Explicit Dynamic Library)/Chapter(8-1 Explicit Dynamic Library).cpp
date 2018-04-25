#include "CConversion.h"

int main()
{
	
	HINSTANCE hInst;
	hInst = LoadLibrary(_T("Chapter(8-1 HDH_DLIB_Changer).dll"));

	void (*IntegerToChar)(int &, char * &);
	void (*DoubleToChar)(double &, char * &);
	
	int nI = 123;
	double dJ = 123.4567;
	//CMyString str;
	char * pcString = new char [STRING_BUFFER];
	
	strcpy_s(pcString, STRING_BUFFER, "Techwing");
	
	IntegerToChar = (void(*)(int &, char * &))GetProcAddress(hInst, "IntegerToChar");
	IntegerToChar(nI, pcString);
	cout << pcString << endl;

	DoubleToChar = (void(*)(double &, char * &))GetProcAddress(hInst, "DoubleToChar");
	DoubleToChar(dJ, pcString);
	cout << pcString << endl;

	FreeLibrary(hInst);
	
	delete [] pcString;
	
	return 0;
}