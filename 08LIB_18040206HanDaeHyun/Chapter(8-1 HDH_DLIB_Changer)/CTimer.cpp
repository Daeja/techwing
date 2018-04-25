#include "CTimer.h"
#include "stdafx.h"

/********************************************************************************
AUTHOR		: 한대현
NAME		: CTime
PARAMS		: [IN ] dTime
RETURNS		: 생성자함수이며, 반환값 없음
COMMENTS	: 생성자함수로 쓰이며, 객체 생성시 인자인 dTime의 값을 멤버변수(m_dStart)에
			  대입한다.
********************************************************************************/
CTimer::CTimer( const double dTime )
{
	m_dCheckTime = dTime;
}

/********************************************************************************
AUTHOR		: 한대현
NAME		: start
COMMENTS	: 생성자에서 대입한 매개변수 값을 초단위로 보고 해당 시간만큼
			  기다리는 함수
********************************************************************************/
void CTimer::startTimer()
{
	m_lStartTime = clock();
}

/********************************************************************************
AUTHOR		: 한대현
NAME		: checkOver
PARAMS		: [IN ] 
			  [OUT] int 형 변수
RETURNS		: int 형 변수
COMMENTS	: 시간 체크하는 함수
********************************************************************************/
bool CTimer::checkOverTime()
{
	long endTime = clock();

	double nResult = ( (double)endTime - (double)m_lStartTime ) / CLOCKS_PER_SEC;

	if( m_dCheckTime <= nResult )
	{
		return TRUE;
	}

	return FALSE;
}