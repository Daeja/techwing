#include "CDividedBy0.h"

/********************************************************************************
AUTHOR		: 한대현
NAME		: CMyString( void )
RETURNS		: 생성자함수이며, 반환값 없음
COMMENTS	: 멤버 이니셜라이저 문법을 사용한 생성자
********************************************************************************/
CDividedBy0::CDividedBy0(int nP, int nQ) : m_nDiviend(nP), m_nDivisor(nQ)
{

}

/********************************************************************************
AUTHOR		: 한대현
NAME		: getDiviend()
RETURNS		: int 자료형
COMMENTS	: 멤버 변수(nDiviend)의 값을 반환하는 함수
********************************************************************************/
int CDividedBy0::getDividend()
{
	return m_nDiviend;
}

/********************************************************************************
AUTHOR		: 한대현
NAME		: getDivisor()
RETURNS		: int 자료형
COMMENTS	: 멤버 변수(nDivisor)의 값을 반환하는 함수
********************************************************************************/
int CDividedBy0::getDivisor()
{
	return m_nDivisor;
}