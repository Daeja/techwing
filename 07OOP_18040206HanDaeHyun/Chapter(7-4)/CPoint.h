#include <iostream>
#include <string>

using namespace std;

class CPoint
{
private :
	int m_nX;
	int m_nY;

public :
	CPoint();
	CPoint(int nA, int nB);
	void print();
};