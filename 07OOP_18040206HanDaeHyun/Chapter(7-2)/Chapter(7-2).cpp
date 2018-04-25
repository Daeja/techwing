// 0404과제.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

int Swap(int&, int&);
int Cylinder(double dR, double dH = 1.0);

#define NUM_FIRST	(100)
#define NUM_SECOND	(200)

#define NUM_RADIUS	(4.0)
#define NUM_HEIGHT	(3.0)

#define PIE			(3.14)

int _tmain(int argc, _TCHAR* argv[])
{
	int nSwap1						= NUM_FIRST;
	int nSwap2						= NUM_SECOND;

	double dCircularCylinderRadius	= NUM_RADIUS;
	double dCircularCylinderHeight	= NUM_HEIGHT;

	// 1 문제
	cout << "swap() 호출전 : " << "nA = " << nSwap1 << ", " << "nB = " << nSwap2 << endl;
	Swap(nSwap1, nSwap2);
	cout << "swap() 호출전 : " << "nA = " << nSwap1 << ", " << "nB = " << nSwap2 << endl;

	cout << endl << endl;			// 문제 나뉘는 부분

	// 2 문제
	Cylinder(dCircularCylinderRadius, dCircularCylinderHeight);
	Cylinder(dCircularCylinderRadius);

	return 0;
}

/********************************************************************************
  AUTHOR	: 한대현
  NAME		: Swap
  PARAMS	: [IN ] nArgument1, nArgument2
			  [OUT] 
  RETURNS	: 문제에 제기된 함수 원형의 반환형이 int이므로 완전한
			  프로세스 종료를 위해 0을 대입
  COMMENTS	: 두개의 인자를 넘겨받고 각각의 내용을 스왑하는 함수
********************************************************************************/
int Swap( int& nArgument1, int& nArgument2 )
{
	int nTempNumber;

	nTempNumber	= 0;

	cout << "In swap() : " << "rx = " << nArgument1 << ", " << "ry = " << nArgument2 << endl;

	nTempNumber = nArgument1;
	nArgument1 = nArgument2;
	nArgument2 = nTempNumber;
	
	cout << "In swap() : " << "rx = " << nArgument1 << ", " << "ry = " << nArgument2 << endl;

	return 0;
}

/********************************************************************************
  AUTHOR	: 한대현
  NAME		: Cylinder
  PARAMS	: [IN ] dR, dH
			  [OUT] 
  RETURNS	: 문제에 제기된 함수 원형의 반환형이 int이므로 완전한
			  프로세스 종료를 위해 0을 대입
  COMMENTS	: 원기둥의 반지름과 높이를 입력받아 주어진 원기둥의 부피를 구하는 함수
********************************************************************************/
int Cylinder( double dR, double dH ) 
{
	double dVolume  = 0;

	dVolume = dR * dR * PIE * dH;		// 원지름의 부피 = 반지름 * 반지름 * 파이값(3.14) * 높이

	printf("dR = %.1f, dH = %.1f, dV = %.2f\n", dR, dH, dVolume);

	return 0;
}