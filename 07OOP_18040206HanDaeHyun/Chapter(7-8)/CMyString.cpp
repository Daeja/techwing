#include "CMyString.h"
#include <iostream>

#define STRING_BUFFER	( 1 )
#define TRUE			( true )
#define FALSE			( false )

using namespace std;

/********************************************************************************
AUTHOR		: �Ѵ���
NAME		: CMyString::CMyString( void )
RETURNS		: �������Լ��̸�, ��ȯ�� ����
COMMENTS	: ����Ʈ �������Լ��� ����
********************************************************************************/
CMyString::CMyString( void )
{
	m_pcString = new char[ STRING_BUFFER ];
	SetStringSize(1);
	m_pcString[0] = '\0';
}

/********************************************************************************
AUTHOR		: �Ѵ���
NAME		: CMyString::CMyString( char * pcString )
PARAMS		: [IN ] * pcString
RETURNS		: �������Լ��̸�, ��ȯ�� ����
COMMENTS	: pcString������ ���ڷ� �޾� �������(m_pcString)�� �����Ѵ�.
			  ��ȯ �������̸� ���� ���縦 �ϰ�, ��������� ���̱� ���� explicit��
			  ����Ѵ�. Override ���
********************************************************************************/
CMyString::CMyString( char * pcString )
{
	m_nStringSize = getSize( pcString );

	m_pcString = new char[ m_nStringSize + 1 ];
	m_pcString[m_nStringSize] = '\0';

	if(m_nStringSize != 0)
	{
		strcpy( m_pcString, pcString );
	}
}

/********************************************************************************
AUTHOR		: �Ѵ���
NAME		: CMyString ( ���� ���� ������ )
PARAMS		: [IN ] * pcString
RETURNS		: �������Լ��̸�, ��ȯ�� ����
COMMENTS	: �� ������� �� ���� ���縦 �����Ѵ�.
********************************************************************************/
CMyString::CMyString( CMyString & c1 )
{
	m_nStringSize = getSize( c1 );
	m_pcString = new char[ m_nStringSize + 1 ];		// ���ڸ� NULL �� �ݿ�
	strcpy( m_pcString, c1 );
}

/********************************************************************************
AUTHOR		: �Ѵ���
NAME		: ~CMyString
RETURNS		: �Ҹ����Լ��̸�, ��ȯ�� ����
COMMENTS	: �޸� ���� Ȯ�� �ʼ�!! (delete or free)
********************************************************************************/
CMyString::~CMyString()
{
	delete [] m_pcString;
}

/********************************************************************************
AUTHOR		: �Ѵ���
NAME		: getSize
PARAMS		: [IN ] none
			  [OUT] int
COMMENTS	: �ش� ��ü�� ���ڿ� ���� ��ȯ
********************************************************************************/
int CMyString::getSize()
{
	m_nStringSize = strlen( m_pcString );
	return m_nStringSize;
}

/********************************************************************************
AUTHOR		: �Ѵ���
NAME		: getSize
PARAMS		: [IN ] * pcString
			  [OUT] int
COMMENTS	: ���ڿ��� ����(int)�� ��ȯ�Ѵ�.
********************************************************************************/
int CMyString::getSize( char * pcString )
{
	if( pcString == NULL )
	{
		return 0;
	}
	return strlen( pcString ) ;
}

/********************************************************************************
AUTHOR		: �Ѵ���
NAME		: print
RETURNS		: ��ȯ�� ����
COMMENTS	: ��� ������ �ִ� ������ ����Ѵ�.
********************************************************************************/
void CMyString::print()
{
	cout << m_pcString << endl;
}

/********************************************************************************
AUTHOR		: �Ѵ���
NAME		: operator+
PARAMS		: [IN ] CMyString c1, CMyString c2
			  [OUT] CMyString
RETURNS		: ���� �� ������ ��ü ��ȯ
COMMENTS	: friend �Լ��� ������ �����̸� ���ڿ��� ��ġ�� ��ģ ������ ��ü ��ȯ
********************************************************************************/
CMyString operator+( CMyString & c1, CMyString & c2 )
{
	char * pcResult = new char[ c1.getSize() + c2.getSize() + 1 ];

	strcpy( pcResult, c1 );
	strcat( pcResult, c2 );

	CMyString resultString( pcResult );

	delete [] pcResult;

	c1.SetStringSize(c1.getSize());

	return resultString;
}

/********************************************************************************
AUTHOR		: �Ѵ���
NAME		: CMyString operator+=( CMyString & c1, CMyString & c2 )
PARAMS		: [IN ] CMyString c1, CMyString c2
			  [OUT] CMyString c1
RETURNS		: ���� �� ������ ��ü ��ȯ
COMMENTS	: friend �Լ��� ������ �����̸� ù��° ���� ��ü�� ������ ���� ��ġ��
			  �ش� ��ü(c1) ��ȯ
********************************************************************************/
CMyString operator+=( CMyString & c1, CMyString & c2 )
{
	char * pcResult = new char[ c1.getSize() + c2.getSize() + 1 ];

	strcpy( pcResult, c1 );
	strcat( pcResult, c2 );

	c1 = pcResult;

	delete [] pcResult;

	c1.SetStringSize(c1.getSize());

	return c1;
}

/********************************************************************************
AUTHOR		: �Ѵ���
NAME		: CMyString CMyString::operator=( CMyString & c1 )
PARAMS		: [IN ] CMyString & c1
			  [OUT] CMyString
COMMENTS	: operator �����ڸ� �̿��Ͽ� ��ü�� ���ڷ� �ްԵǸ� �ش� ������
			  ������ �����Ѵ�.
********************************************************************************/
CMyString CMyString::operator=( CMyString & c1 )
{
	delete [] m_pcString;
	strcpy( m_pcString, c1 );

	c1.SetStringSize(c1.getSize());

	return * this;
}

/********************************************************************************
AUTHOR		: �Ѵ���
NAME		: CMyString CMyString::operator=( char * pcTempString )
PARAMS		: [IN ] char * pcTempString
			  [OUT] CMyString
COMMENTS	: operator �����ڸ� �̿��Ͽ� ��ü�� ���ڷ� �ްԵǸ� �ش� ������
			  ������ �����Ѵ�.
********************************************************************************/
CMyString CMyString::operator=( char * pcTempString )
{
	delete [] m_pcString;
	m_pcString = new char [ getSize( pcTempString ) + 1 ];
	strcpy( m_pcString, pcTempString );

	this->SetStringSize(this->getSize());

	return * this;
}

/********************************************************************************
AUTHOR		: �Ѵ���
NAME		: CMyString CMyString::operator=( int nNum )
PARAMS		: [IN ] char * pcTempString
			  [OUT] CMyString
COMMENTS	: operator �����ڸ� �̿��Ͽ� ��ü�� ���ڷ� �ްԵǸ� �ش� ������
			  ������ �����Ѵ�.
********************************************************************************/
CMyString CMyString::operator=( int nNum )
{
	delete [] m_pcString;
	m_pcString = new char [ nNum + 1 ];

	if( NULL == nNum )
	{
		strcpy( m_pcString, "\0" );			// NULL�� ��� �ڵ�
	}
	else
	{
		itoa(nNum, m_pcString, 10);
	}

	this->SetStringSize(this->getSize());
	
	return * this;
}

/********************************************************************************
AUTHOR		: �Ѵ���
NAME		: bool operator==( CMyString & c1, CMyString & c2 )
PARAMS		: [IN ] CMyString c1, CMyString c2
			  [OUT] CMyString c1
RETURNS		: ���� �� ������ ��ü ��ȯ
COMMENTS	: friend �Լ��� ������ �����̸� ù��° ���� ��ü�� ������ ���� ��ġ��
			  �ش� ��ü ��ȯ
********************************************************************************/
bool operator==( CMyString & c1, CMyString & c2 )
{
	int nC1Size = c1.getSize();
	int nC2Size = c2.getSize();
	char * pcTempC1 = new char[ c1.getSize() ];
	char * pcTempC2 = new char[ c2.getSize() ];

	strcpy( pcTempC1, c1 );
	strcpy( pcTempC2, c2 );

	if( nC1Size == nC2Size )
	{
		for( int nI = 0; nI < nC1Size; nI++ )
		{
			if( pcTempC1[nI] != pcTempC2[nI] )
			{
				return FALSE;
			}
		}
	}
	else {
		return FALSE;
	}

	return TRUE;
}

/********************************************************************************
AUTHOR		: �Ѵ���
NAME		: operator char*() const
PARAMS		: [IN ] none
			  [OUT] none 
RETURNS		: ���� �� ������ ��ü ��ȯ
COMMENTS	: ��ȯ �������Լ��μ� ���� Ŭ���� �ڷ��� -> char * ��ȯ
********************************************************************************/
CMyString::operator char*() const
{
	return m_pcString;
}

/********************************************************************************
AUTHOR		: �Ѵ���
NAME		: istream & operator>>(istream & is, CMyString & c1)
RETURNS		: ���� �� ������ ��ü ��ȯ
COMMENTS	: ��ȯ �������Լ��μ� input stream�� Ǯ�� ��ȯ�ϴ� ��������
			  parameter�� �޾ƿ��� ��ü(c1)�� �������(m_pcString)�� 
			  �Է��ϴ� �������� ���ȴ�.
********************************************************************************/
istream & operator>>( istream & is, CMyString & c1 )
{
	char * pcTempString = NULL;

	char value;
	int size = 0;
	int maxSize = 1;

	pcTempString = new char[maxSize + 1];
	while ((value = getchar()) != EOF)
	{
		if (isspace(value))
			break;

		if (size == maxSize) 
		{
			char* temp = new char[2 * maxSize + 1];
			pcTempString[size] = '\0';
			strcpy(temp, pcTempString);
			delete[] pcTempString;
			pcTempString = temp;
			maxSize = 2 * maxSize;
		}
		pcTempString[size++] = value;
	}
	pcTempString[size] = '\0';

	c1 = pcTempString;			//strcpy( c1, pcTempString ) �̰� ���� �ʴ´�.

	delete [] pcTempString;

	c1.SetStringSize(c1.getSize());

	return is;
}

/********************************************************************************
AUTHOR		: �Ѵ���
NAME		: SetStringSize
PARAMS		: [IN ] none
			  [OUT] none 
RETURNS		: ��ȯ�� X
COMMENTS	: int Ÿ���� char �迭 ũ�⸦ �����ϴ� �Լ�
********************************************************************************/
void CMyString::SetStringSize(int nNum)
{
	m_nStringSize = nNum;
}