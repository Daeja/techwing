#include "Implicit Dynamic Library.h"

/********************************************************************************
AUTHOR		: �Ѵ���
NAME		: addtioin
PARAMS		: [IN ] int nA, int nB
			  [OUT] int
COMMENTS	: [DLL] �ΰ��� �Ű������� ���� ���� �� �� �� ��ȯ�Ѵ�.
********************************************************************************/
void usingLib(int nA, int nB)
{
	std::cout << nA << " + " << nB << " = " << addition(nA, nB) << std::endl;
	std::cout << nA << " - " << nB << " = " << subtraction(nA, nB) << std::endl;
	std::cout << nA << " * " << nB << " = " << multiplication(nA, nB) << std::endl;
	std::cout << nA << " / " << nB << " = " << division(nA, nB) << std::endl;
}