#include "Implicit Dynamic Library.h"

/********************************************************************************
AUTHOR		: 한대현
NAME		: addtioin
PARAMS		: [IN ] int nA, int nB
			  [OUT] int
COMMENTS	: [DLL] 두개의 매개변수를 통해 값을 더 한 후 반환한다.
********************************************************************************/
void usingLib(int nA, int nB)
{
	std::cout << nA << " + " << nB << " = " << addition(nA, nB) << std::endl;
	std::cout << nA << " - " << nB << " = " << subtraction(nA, nB) << std::endl;
	std::cout << nA << " * " << nB << " = " << multiplication(nA, nB) << std::endl;
	std::cout << nA << " / " << nB << " = " << division(nA, nB) << std::endl;
}