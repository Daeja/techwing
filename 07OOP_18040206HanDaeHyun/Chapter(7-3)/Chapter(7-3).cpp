#include <iostream>
#include <Windows.h>
#include "CDeskLamp.h"
#include "CTimer.h"

#define TIME (3.0)
#define TRUE true
#define FALSE false

using namespace std;

int main()
{
	CDeskLamp DeskLamp;

	cout << "����<7-3>�� �����Դϴ�." << endl;

	DeskLamp.turnOn();
	DeskLamp.turnOff();

	cout << endl << endl;		// ���� ������ ����

	cout << "����<7-4>�� �����Դϴ�." << endl;

	CTimer Timer(TIME);

	Timer.startTimer();

	bool nResult = FALSE;

	SYSTEMTIME curTime;
	GetLocalTime(&curTime);
	cout << "���� �ð� : " << curTime.wHour << " : " << curTime.wMinute << " : " << curTime.wSecond << " --> " << TIME << "�� �� �ð� ���" << endl;

	while(1)
	{
		nResult = Timer.checkOverTime();

		if( TRUE == nResult )
		{
			break;
		}
	}

	GetLocalTime(&curTime);
	cout << "���� �ð� : " << curTime.wHour << " : " << curTime.wMinute << " : " << curTime.wSecond << endl;

	return 0;
}