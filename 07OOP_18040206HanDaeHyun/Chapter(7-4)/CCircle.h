#include <iostream>
#include <string>

#include "CPoint.h"

using namespace std;

class CCircle
{
private :
	int m_nRadius;
	CPoint m_center;		// Point ��ü�� ��� ������ ����Ǿ� �ִ�.

public :
	CCircle();
	CCircle(int nR);
	CCircle(CPoint p, int nR);
	CCircle(int nX, int nY, int nR);
	void print();
};