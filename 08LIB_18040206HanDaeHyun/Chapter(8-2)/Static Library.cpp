#include "Static Library.h"

/********************************************************************************
AUTHOR		: �Ѵ���
NAME		: addtioin
PARAMS		: [IN ] int nA, int nB
			  [OUT] int
COMMENTS	: [DLL] �ΰ��� �Ű������� ���� ���� �� �� �� ��ȯ�Ѵ�.
********************************************************************************/
void usingLib(int nA, int nB)
{
	CCalculation c1;
	std::cout << nA << " + " << nB << " = " << c1.addition(nA, nB) << std::endl;
	std::cout << nA << " - " << nB << " = " << c1.subtraction(nA, nB) << std::endl;
	std::cout << nA << " * " << nB << " = " << c1.multiplication(nA, nB) << std::endl;
	std::cout << nA << " / " << nB << " = " << c1.division(nA, nB) << std::endl;
}