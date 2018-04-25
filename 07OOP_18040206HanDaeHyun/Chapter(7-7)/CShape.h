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
	virtual void draw();
};

