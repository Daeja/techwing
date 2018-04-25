#include <iostream>
#include <string>

#include "CPoint.h"

using namespace std;

class CCircle
{
private :
	int m_nRadius;
	CPoint m_center;		// Point 객체가 멤버 변수로 선언되어 있다.

public :
	CCircle();
	CCircle(int nR);
	CCircle(CPoint p, int nR);
	CCircle(int nX, int nY, int nR);
	void print();
};