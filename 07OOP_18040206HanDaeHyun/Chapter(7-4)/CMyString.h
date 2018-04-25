#include <iostream>

#define STRING_BUFFER 1

using namespace std;

class CMyString
{	
private :
	char * m_pcString;
	int m_nStringSize;

public :
	CMyString();
	CMyString(char * pcString);
	~CMyString();
	int getSize(char * pcString);
	void SetString(char * pcString, bool bDelete = true);
	void print();
};