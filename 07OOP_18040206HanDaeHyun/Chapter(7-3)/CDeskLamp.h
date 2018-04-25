#include <iostream>

#define ON	(true)
#define OFF (false)

using namespace std;

class CDeskLamp
{
private :
	bool m_bIsOn;

public :
	CDeskLamp();
	~CDeskLamp();
	void turnOn();
	void turnOff();
	void print();
};