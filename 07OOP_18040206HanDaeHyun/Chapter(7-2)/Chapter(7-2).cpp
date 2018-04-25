// 0404����.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
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

	// 1 ����
	cout << "swap() ȣ���� : " << "nA = " << nSwap1 << ", " << "nB = " << nSwap2 << endl;
	Swap(nSwap1, nSwap2);
	cout << "swap() ȣ���� : " << "nA = " << nSwap1 << ", " << "nB = " << nSwap2 << endl;

	cout << endl << endl;			// ���� ������ �κ�

	// 2 ����
	Cylinder(dCircularCylinderRadius, dCircularCylinderHeight);
	Cylinder(dCircularCylinderRadius);

	return 0;
}

/********************************************************************************
  AUTHOR	: �Ѵ���
  NAME		: Swap
  PARAMS	: [IN ] nArgument1, nArgument2
			  [OUT] 
  RETURNS	: ������ ����� �Լ� ������ ��ȯ���� int�̹Ƿ� ������
			  ���μ��� ���Ḧ ���� 0�� ����
  COMMENTS	: �ΰ��� ���ڸ� �Ѱܹް� ������ ������ �����ϴ� �Լ�
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
  AUTHOR	: �Ѵ���
  NAME		: Cylinder
  PARAMS	: [IN ] dR, dH
			  [OUT] 
  RETURNS	: ������ ����� �Լ� ������ ��ȯ���� int�̹Ƿ� ������
			  ���μ��� ���Ḧ ���� 0�� ����
  COMMENTS	: ������� �������� ���̸� �Է¹޾� �־��� ������� ���Ǹ� ���ϴ� �Լ�
********************************************************************************/
int Cylinder( double dR, double dH ) 
{
	double dVolume  = 0;

	dVolume = dR * dR * PIE * dH;		// �������� ���� = ������ * ������ * ���̰�(3.14) * ����

	printf("dR = %.1f, dH = %.1f, dV = %.2f\n", dR, dH, dVolume);

	return 0;
}