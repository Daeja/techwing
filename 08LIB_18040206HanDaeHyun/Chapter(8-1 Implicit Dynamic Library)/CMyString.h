#pragma once

#include "stdafx.h"
#include <iostream>

using namespace std;

class AFX_EXT_CLASS CMyString
{
private :
	char * m_pcString;
	int m_nStringSize;

public :
	CMyString(void);
	CMyString( CMyString & c1 );
	explicit CMyString(char * pcString);
	~CMyString(void);
	int getSize();
	int getSize(char * pcString);
	void print();
	char * getString();
	friend CMyString operator+(CMyString & c1, CMyString & c2);
	friend CMyString operator+=(CMyString & c1, CMyString & c2);
	CMyString operator=(char * pcTempString);
	CMyString operator=(CMyString & c1);
	CMyString operator=(int nNUm);
	friend bool operator==(CMyString & c1, CMyString & c2);
	friend istream & operator>>(istream & is, CMyString & c1);
	operator char*() const;
	void SetStringSize();
};