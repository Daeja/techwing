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

	cout << "과제<7-3>의 과제입니다." << endl;

	DeskLamp.turnOn();
	DeskLamp.turnOff();

	cout << endl << endl;		// 문제 나뉘는 구간

	cout << "과제<7-4>의 과제입니다." << endl;

	CTimer Timer(TIME);

	Timer.startTimer();

	bool nResult = FALSE;

	SYSTEMTIME curTime;
	GetLocalTime(&curTime);
	cout << "시작 시간 : " << curTime.wHour << " : " << curTime.wMinute << " : " << curTime.wSecond << " --> " << TIME << "초 후 시간 출력" << endl;

	while(1)
	{
		nResult = Timer.checkOverTime();

		if( TRUE == nResult )
		{
			break;
		}
	}

	GetLocalTime(&curTime);
	cout << "종료 시간 : " << curTime.wHour << " : " << curTime.wMinute << " : " << curTime.wSecond << endl;

	return 0;
}