#pragma once
#include "CShape.h"

class CTriangle : public CShape
{
private :
	double dArea;
public:
	CTriangle(void);
	~CTriangle(void);
	void setArea(double dW, double dH);
	double getArea();
};

