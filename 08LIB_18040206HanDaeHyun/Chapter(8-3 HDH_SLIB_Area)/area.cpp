#include "area.h"

/********************************************************************************
AUTHOR		: �Ѵ���
NAME		: circle
PARAMS		: [IN ] int nNum
			  [OUT] double
COMMENTS	: ���� ���̸� ���Ѵ�.
********************************************************************************/
double CArea::circle(int nNum)
{
	double dResult = (double)nNum * (double)nNum * PI;
	return dResult;
}

/********************************************************************************
AUTHOR		: �Ѵ���
NAME		: addtioin
PARAMS		: [IN ] int nWidth, int nHeight
			  [OUT] int
COMMENTS	: �簢���� ���̸� ���Ѵ�
********************************************************************************/
int CArea::rectangle(int nWidth, int nHeight)
{
	int nResult = nWidth * nHeight;
	return nResult;
}