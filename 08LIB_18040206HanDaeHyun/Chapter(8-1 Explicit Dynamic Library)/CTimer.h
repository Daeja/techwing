#pragma once
#include <time.h>
#include "stdafx.h"
#define TRUE true
#define FALSE false

class AFX_EXT_CLASS CTimer
{
private :
	long m_lStartTime;
	double m_dCheckTime;

public :
	CTimer( const double dTime );
	void startTimer();
	bool checkOverTime();
};