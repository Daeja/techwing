#pragma once
#include <time.h>
#include "stdafx.h"

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