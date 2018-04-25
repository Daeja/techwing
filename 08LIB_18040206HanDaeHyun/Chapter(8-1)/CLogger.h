#pragma once
#include <iostream>
#include <fstream>
#include <Windows.h>
#include <iostream>

#include "CMyString.h"

#define NAME_BUFFER		(13)

#define HEADER_BUFFER	(11)

using namespace std;

class CLogger
{
private :
	CMyString m_FileNameExtension;
	int m_nContentsLength;
public:
	CLogger(void);
	~CLogger(void);
	CLogger(char * pcFileNameExtension);
	void write(char * pcContents);
	void change(char * pcString);
};

