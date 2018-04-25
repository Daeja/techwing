#include "CMyString.h"	
/********************************************************************************
AUTHOR		: 한대현
NAME		: CMyString
RETURNS		: 생성자함수이며, 반환값 없음
COMMENTS	: 디폴트 생성자함수로 쓰임
********************************************************************************/
CMyString::CMyString()
{
	m_pcString = new char[STRING_BUFFER];
	m_pcString[0] = '\0';
}

/********************************************************************************
AUTHOR		: 한대현
NAME		: CMyString
PARAMS		: [IN ] * pcString
RETURNS		: 생성자함수이며, 반환값 없음
COMMENTS	: pcString변수를 인자로 받아 멤버변수(m_pcString)에 대입한다.
			  변환 생성자이며 깊은 복사를 한다.
********************************************************************************/
CMyString::CMyString(char * pcString)
{
	m_nStringSize = getSize(pcString);
	m_pcString = new char[m_nStringSize];

	strcpy(m_pcString, pcString);
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
	cout << "소멸자 호출" << endl;
}

/********************************************************************************
AUTHOR		: 한대현
NAME		: getSize
PARAMS		: [IN ] * pcString
RETURNS		: 문자열의 길이(int)를 반환한다.
COMMENTS	: 문자열의 특성 상 끝 부분에 '\n'값 주의
********************************************************************************/
int CMyString::getSize(char * pcString)
{
	return strlen(pcString) + 1;
}

/********************************************************************************
AUTHOR		: 한대현
NAME		: SetString
PARAMS		: [IN ] * pcString
RETURNS		: 반환값 없음
COMMENTS	: 존재하던 문자열의 내용을 delete시키고 새로 메모리 동적할당 하여
			  새로운 내용 기재
********************************************************************************/
void CMyString::SetString(char * pcString, bool bDelete)
{
	if( true == bDelete)
	{
		delete [] m_pcString;
	}

	m_nStringSize = getSize(pcString);
	m_pcString = new char[m_nStringSize];
	strcpy(m_pcString, pcString);
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