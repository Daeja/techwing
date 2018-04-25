#include "CTimer.h"
#include "stdafx.h"

/********************************************************************************
AUTHOR		: �Ѵ���
NAME		: CTime
PARAMS		: [IN ] dTime
RETURNS		: �������Լ��̸�, ��ȯ�� ����
COMMENTS	: �������Լ��� ���̸�, ��ü ������ ������ dTime�� ���� �������(m_dStart)��
			  �����Ѵ�.
********************************************************************************/
CTimer::CTimer( const double dTime )
{
	m_dCheckTime = dTime;
}

/********************************************************************************
AUTHOR		: �Ѵ���
NAME		: start
COMMENTS	: �����ڿ��� ������ �Ű����� ���� �ʴ����� ���� �ش� �ð���ŭ
			  ��ٸ��� �Լ�
********************************************************************************/
void CTimer::startTimer()
{
	m_lStartTime = clock();
}

/********************************************************************************
AUTHOR		: �Ѵ���
NAME		: checkOver
PARAMS		: [IN ] 
			  [OUT] int �� ����
RETURNS		: int �� ����
COMMENTS	: �ð� üũ�ϴ� �Լ�
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