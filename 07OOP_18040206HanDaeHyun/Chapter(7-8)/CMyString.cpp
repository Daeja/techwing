#include "CMyString.h"
#include <iostream>

#define STRING_BUFFER	( 1 )
#define TRUE			( true )
#define FALSE			( false )

using namespace std;

/********************************************************************************
AUTHOR		: 한대현
NAME		: CMyString::CMyString( void )
RETURNS		: 생성자함수이며, 반환값 없음
COMMENTS	: 디폴트 생성자함수로 쓰임
********************************************************************************/
CMyString::CMyString( void )
{
	m_pcString = new char[ STRING_BUFFER ];
	SetStringSize(1);
	m_pcString[0] = '\0';
}

/********************************************************************************
AUTHOR		: 한대현
NAME		: CMyString::CMyString( char * pcString )
PARAMS		: [IN ] * pcString
RETURNS		: 생성자함수이며, 반환값 없음
COMMENTS	: pcString변수를 인자로 받아 멤버변수(m_pcString)에 대입한다.
			  변환 생성자이며 깊은 복사를 하고, 명시적으로 보이기 위해 explicit를
			  사용한다. Override 사용
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
AUTHOR		: 한대현
NAME		: CMyString ( 깊은 복사 생성자 )
PARAMS		: [IN ] * pcString
RETURNS		: 생성자함수이며, 반환값 없음
COMMENTS	: 각 멤버변수 간 깊은 복사를 시행한다.
********************************************************************************/
CMyString::CMyString( CMyString & c1 )
{
	m_nStringSize = getSize( c1 );
	m_pcString = new char[ m_nStringSize + 1 ];		// 끝자리 NULL 값 반영
	strcpy( m_pcString, c1 );
}

/********************************************************************************
AUTHOR		: 한대현
NAME		: ~CMyString
RETURNS		: 소멸자함수이며, 반환값 없음
COMMENTS	: 메모리 누수 확인 필수!! (delete or free)
********************************************************************************/
CMyString::~CMyString()
{
	delete [] m_pcString;
}

/********************************************************************************
AUTHOR		: 한대현
NAME		: getSize
PARAMS		: [IN ] none
			  [OUT] int
COMMENTS	: 해당 객체의 문자열 길이 반환
********************************************************************************/
int CMyString::getSize()
{
	m_nStringSize = strlen( m_pcString );
	return m_nStringSize;
}

/********************************************************************************
AUTHOR		: 한대현
NAME		: getSize
PARAMS		: [IN ] * pcString
			  [OUT] int
COMMENTS	: 문자열의 길이(int)를 반환한다.
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
AUTHOR		: 한대현
NAME		: print
RETURNS		: 반환값 없음
COMMENTS	: 멤버 변수에 있는 내용을 출력한다.
********************************************************************************/
void CMyString::print()
{
	cout << m_pcString << endl;
}

/********************************************************************************
AUTHOR		: 한대현
NAME		: operator+
PARAMS		: [IN ] CMyString c1, CMyString c2
			  [OUT] CMyString
RETURNS		: 연산 후 선언한 객체 반환
COMMENTS	: friend 함수로 정의한 내용이며 문자열을 합치고 합친 내용의 객체 반환
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
AUTHOR		: 한대현
NAME		: CMyString operator+=( CMyString & c1, CMyString & c2 )
PARAMS		: [IN ] CMyString c1, CMyString c2
			  [OUT] CMyString c1
RETURNS		: 연산 후 선언한 객체 반환
COMMENTS	: friend 함수로 정의한 내용이며 첫번째 인자 객체의 내용을 전부 합치고
			  해당 객체(c1) 반환
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
AUTHOR		: 한대현
NAME		: CMyString CMyString::operator=( CMyString & c1 )
PARAMS		: [IN ] CMyString & c1
			  [OUT] CMyString
COMMENTS	: operator 연산자를 이용하여 객체를 인자로 받게되면 해당 인자의
			  내용을 복사한다.
********************************************************************************/
CMyString CMyString::operator=( CMyString & c1 )
{
	delete [] m_pcString;
	strcpy( m_pcString, c1 );

	c1.SetStringSize(c1.getSize());

	return * this;
}

/********************************************************************************
AUTHOR		: 한대현
NAME		: CMyString CMyString::operator=( char * pcTempString )
PARAMS		: [IN ] char * pcTempString
			  [OUT] CMyString
COMMENTS	: operator 연산자를 이용하여 객체를 인자로 받게되면 해당 인자의
			  내용을 복사한다.
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
AUTHOR		: 한대현
NAME		: CMyString CMyString::operator=( int nNum )
PARAMS		: [IN ] char * pcTempString
			  [OUT] CMyString
COMMENTS	: operator 연산자를 이용하여 객체를 인자로 받게되면 해당 인자의
			  내용을 복사한다.
********************************************************************************/
CMyString CMyString::operator=( int nNum )
{
	delete [] m_pcString;
	m_pcString = new char [ nNum + 1 ];

	if( NULL == nNum )
	{
		strcpy( m_pcString, "\0" );			// NULL값 방어 코드
	}
	else
	{
		itoa(nNum, m_pcString, 10);
	}

	this->SetStringSize(this->getSize());
	
	return * this;
}

/********************************************************************************
AUTHOR		: 한대현
NAME		: bool operator==( CMyString & c1, CMyString & c2 )
PARAMS		: [IN ] CMyString c1, CMyString c2
			  [OUT] CMyString c1
RETURNS		: 연산 후 선언한 객체 반환
COMMENTS	: friend 함수로 정의한 내용이며 첫번째 인자 객체의 내용을 전부 합치고
			  해당 객체 반환
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
AUTHOR		: 한대현
NAME		: operator char*() const
PARAMS		: [IN ] none
			  [OUT] none 
RETURNS		: 연산 후 선언한 객체 반환
COMMENTS	: 변환 연산자함수로서 사용됨 클래스 자료형 -> char * 변환
********************************************************************************/
CMyString::operator char*() const
{
	return m_pcString;
}

/********************************************************************************
AUTHOR		: 한대현
NAME		: istream & operator>>(istream & is, CMyString & c1)
RETURNS		: 연산 후 선언한 객체 반환
COMMENTS	: 변환 연산자함수로서 input stream은 풀에 반환하는 형식으로
			  parameter를 받아오며 객체(c1)의 멤버변수(m_pcString)에 
			  입력하는 형식으로 사용된다.
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

	c1 = pcTempString;			//strcpy( c1, pcTempString ) 이건 되지 않는다.

	delete [] pcTempString;

	c1.SetStringSize(c1.getSize());

	return is;
}

/********************************************************************************
AUTHOR		: 한대현
NAME		: SetStringSize
PARAMS		: [IN ] none
			  [OUT] none 
RETURNS		: 반환값 X
COMMENTS	: int 타입의 char 배열 크기를 지정하는 함수
********************************************************************************/
void CMyString::SetStringSize(int nNum)
{
	m_nStringSize = nNum;
}