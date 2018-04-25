#include <time.h>

#define TRUE true
#define FALSE false

class CTimer
{
private :
	long m_lStartTime;
	double m_dCheckTime;

public :
	CTimer( const double dTime );
	void startTimer();
	bool checkOverTime();
};