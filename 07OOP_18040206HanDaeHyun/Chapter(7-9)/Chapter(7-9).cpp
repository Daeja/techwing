#include <iostream>
#include "CDividedBy0.h"

using namespace std;

/********************************************************************************
AUTHOR		: �Ѵ���
NAME		: getAverageScore
PARAMS		: [IN ] int nStudents, int nScore
			  [OUT] double(nScore / (double)nStudents)
COMMENTS	: nStudents�� 0�϶� ���� �Լ��� catch������ ��ü�� ������ ������ �ϸ�
			  nStudents�� 0�� �ƴ϶�� nScore / (double)nStudents�� �����Ѵ�.
********************************************************************************/
double getAverageScore(int nStudents, int nScore)
{
	if( 0 == nStudents )
	{
		throw CDividedBy0(nStudents, nScore);
	}
	
	return nScore / (double)nStudents;
}

/********************************************************************************
AUTHOR		: �Ѵ���
NAME		: printAverageScore
PARAMS		: [IN ] int nStudents, int nScore
			  [OUT] void
COMMENTS	: try���� �����ϴٰ� ������ �߻��ÿ� catch�� ���ܸ� �ް� �ٽ� ����
			  �Լ��� catch�� throw; ������ ���� �����Ѵ�.
********************************************************************************/
void printAverageScore(int nStudents, int nScore)
{
	try
	{
		cout << "����� " << getAverageScore(nStudents, nScore) << "���Դϴ�." << endl;
	}
	catch(CDividedBy0 xExepction)
	{
		cout << "EXCEPTION : " << xExepction.getDividend() << "(��)�� " << xExepction.getDivisor() << "(��)�� ���������ϴ�." << endl;
		throw;
	}
}

int main()
{
	int nStudents = 0;
	int nScore = 0;

	cout << "�л����� ���� �Է��ϼ��� : ";
	cin >> nStudents;

	cout << "������ ���� �Է��ϼ��� : ";
	cin >> nScore;

	try
	{
		printAverageScore(nStudents, nScore);
	}
	catch(CDividedBy0 xExepction)
	{
		cout << "��� ������ ������ ���߽��ϴ�." << endl;
	}

	return 0;
}