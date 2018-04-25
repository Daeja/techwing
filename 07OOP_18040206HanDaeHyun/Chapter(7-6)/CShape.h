#pragma once
#include <iostream>

using namespace std;

class CShape
{
private :
	double dArea;
public:
	CShape(void);
	~CShape(void);
	void setArea(double dW, double dH);
	double getArea();
};

