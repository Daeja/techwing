#include "area.h"

/********************************************************************************
AUTHOR		: 한대현
NAME		: circle
PARAMS		: [IN ] int nNum
			  [OUT] double
COMMENTS	: 원의 넓이를 구한다.
********************************************************************************/
double CArea::circle(int nNum)
{
	double dResult = (double)nNum * (double)nNum * PI;
	return dResult;
}

/********************************************************************************
AUTHOR		: 한대현
NAME		: addtioin
PARAMS		: [IN ] int nWidth, int nHeight
			  [OUT] int
COMMENTS	: 사각형의 넓이를 구한다
********************************************************************************/
int CArea::rectangle(int nWidth, int nHeight)
{
	int nResult = nWidth * nHeight;
	return nResult;
}