#include <iostream>
#include "CDividedBy0.h"

using namespace std;

/********************************************************************************
AUTHOR		: 한대현
NAME		: getAverageScore
PARAMS		: [IN ] int nStudents, int nScore
			  [OUT] double(nScore / (double)nStudents)
COMMENTS	: nStudents가 0일때 상위 함수의 catch문으로 객체를 던지는 역할을 하며
			  nStudents가 0이 아니라면 nScore / (double)nStudents를 실행한다.
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
AUTHOR		: 한대현
NAME		: printAverageScore
PARAMS		: [IN ] int nStudents, int nScore
			  [OUT] void
COMMENTS	: try문을 시행하다가 오류가 발생시에 catch로 예외를 받고 다시 상위
			  함수의 catch로 throw; 구문을 통해 전달한다.
********************************************************************************/
void printAverageScore(int nStudents, int nScore)
{
	try
	{
		cout << "평균은 " << getAverageScore(nStudents, nScore) << "점입니다." << endl;
	}
	catch(CDividedBy0 xExepction)
	{
		cout << "EXCEPTION : " << xExepction.getDividend() << "(을)를 " << xExepction.getDivisor() << "(으)로 나누었습니다." << endl;
		throw;
	}
}

int main()
{
	int nStudents = 0;
	int nScore = 0;

	cout << "학생들의 수를 입력하세요 : ";
	cin >> nStudents;

	cout << "점수의 합을 입력하세요 : ";
	cin >> nScore;

	try
	{
		printAverageScore(nStudents, nScore);
	}
	catch(CDividedBy0 xExepction)
	{
		cout << "평균 점수를 구하지 못했습니다." << endl;
	}

	return 0;
}