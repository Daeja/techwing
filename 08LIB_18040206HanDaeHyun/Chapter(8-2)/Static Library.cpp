#include "Static Library.h"

/********************************************************************************
AUTHOR		: 한대현
NAME		: addtioin
PARAMS		: [IN ] int nA, int nB
			  [OUT] int
COMMENTS	: [DLL] 두개의 매개변수를 통해 값을 더 한 후 반환한다.
********************************************************************************/
void usingLib(int nA, int nB)
{
	CCalculation c1;
	std::cout << nA << " + " << nB << " = " << c1.addition(nA, nB) << std::endl;
	std::cout << nA << " - " << nB << " = " << c1.subtraction(nA, nB) << std::endl;
	std::cout << nA << " * " << nB << " = " << c1.multiplication(nA, nB) << std::endl;
	std::cout << nA << " / " << nB << " = " << c1.division(nA, nB) << std::endl;
}