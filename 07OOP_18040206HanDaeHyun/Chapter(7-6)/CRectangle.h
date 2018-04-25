#pragma once
#include "CShape.h"

class CRectangle
{
private :
	double dArea;
public:
	CRectangle(void);
	~CRectangle(void);
	void setArea(double dW, double dH);
	double getArea();
};

