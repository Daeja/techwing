#include <iostream>
#include <typeinfo>
#include "CMyString.h"
#include "CStack.h"

using namespace std;

/********************************************************************************
AUTHOR		: �Ѵ���
NAME		: swapValues
PARAMS		: [IN ] T T1, T T2
			  [OUT] void
COMMENTS	: ���ø� �ڷ����� Ȱ���� ���� �Լ�
********************************************************************************/
template < typename T >
void swapValues(T & T1, T & T2)
{
	T tempTemplate = T1;
	T1 = T2;
	T2 = tempTemplate;
}

/********************************************************************************
AUTHOR		: �Ѵ���
NAME		: swapValues
PARAMS		: [IN ] char * pc1, char * pc2
			  [OUT] void
COMMENTS	: ���ø� �ڷ����� Ȱ���� ���� �Լ�(Overloading)
********************************************************************************/
void swapValues(char * pc1, char * pc2)
{
	char * pcTemp = new char [ STRING_BUFFER ];

	if( NULL == pc1 )
	{
		pc1 = new char[ STRING_BUFFER ];
	}
	if( NULL == pc2 )
	{
		pc2 = new char[ STRING_BUFFER ];
	}
	
	strcpy_s(pcTemp, STRING_BUFFER, pc1);
	strcpy_s(pc1,	 STRING_BUFFER, pc2);
	strcpy_s(pc2,	 STRING_BUFFER, pcTemp);

	delete [] pcTemp;
}

/********************************************************************************
AUTHOR		: �Ѵ���
NAME		: printPushSuccess
PARAMS		: [IN ] bIsSuccess
			  [OUT] void
COMMENTS	: Overflow �߻� ���� Ȯ��
********************************************************************************/
void printPushSuccess(int nIsSuccess)
{
	if( nIsSuccess == PUSH_SUCCESS )
	{
		cout << "���� push() ����" << endl;
	}
	else
	{
		cout << "Overflow �߻�" << endl;
	}
}

/********************************************************************************
AUTHOR		: �Ѵ���
NAME		: printPopSuccess
PARAMS		: [IN ] bIsSuccess
			  [OUT] void
COMMENTS	: Underflow �߻� ���� Ȯ��
********************************************************************************/
void printPopSuccess(int nIsSuccess)
{
	if( nIsSuccess == PUSH_SUCCESS )
	{
		cout << "���� pop() ����" << endl;
	}
	else
	{
		cout << "Underflow �߻�" << endl;
	}
}

/********************************************************************************
AUTHOR		: �Ѵ���
NAME		: push
PARAMS		: [IN ] CStack<T> & stack, T Value
			  [OUT] void
COMMENTS	: ���ø��� �̿��� push�Լ�
********************************************************************************/
template <typename T>
void push(CStack<T> & stack, T Value)
{
	int nIsPushSuccess = 0;

	nIsPushSuccess = stack.push(Value);
	cout << "��� : ";
	printPushSuccess(nIsPushSuccess);
	cout << endl << "���� �� : " << Value << endl << endl;
}

/********************************************************************************
AUTHOR		: �Ѵ���
NAME		: pop
PARAMS		: [IN ] CStack<T> & stack
			  [OUT] void
COMMENTS	: ���ø��� �̿��� pop�Լ�
********************************************************************************/
template <typename T>
void pop(CStack<T> & stack)
{
	T result = 0;
	int nIsPopSuccess = 0;

	nIsPopSuccess = stack.pop(result);
	cout << "��� : ";
	printPopSuccess(nIsPopSuccess);
	cout << endl << "���� �� : " << result << endl << endl;
}

/********************************************************************************
AUTHOR		: �Ѵ���
NAME		: push
PARAMS		: [IN ] CStack<char *> & stack, char * Value
			  [OUT] void
COMMENTS	: ���ø� �Լ��� Ư��ȭ�� �̿��� push �Լ�
********************************************************************************/
template <>
void push(CStack<char *> & stack, char * Value)
{
	int nIsPushSuccess = 0;

	nIsPushSuccess = stack.push(Value);
	cout << "��� : ";
	printPushSuccess(nIsPushSuccess);
	cout << "���� �� : " << Value << endl << endl;
}

/********************************************************************************
AUTHOR		: �Ѵ���
NAME		: pop
PARAMS		: [IN ] CStack<char *> & stack
			  [OUT] void
COMMENTS	: ���ø� �Լ��� Ư��ȭ�� �̿��� pop �Լ�
********************************************************************************/
template <>
void pop(CStack<char *> & stack)
{
	char result [STRING_BUFFER];
	int nIsPopSuccess = 0;

	memset(result, 0, STRING_BUFFER);
	nIsPopSuccess = stack.pop(result);
	cout << "��� : ";
	printPopSuccess(nIsPopSuccess);
	cout << "���� �� : " << result << endl << endl;

	//delete [] result;
}

int main()
{
	cout << "7-10-1�� �����Դϴ�." << endl;
	int nInt1			= 100;
	int nInt2			= 200;
	float fFloat1		= (float)1.1;
	float fFloat2		= (float)2.2;

	char * pcChar1		= new char [ STRING_BUFFER ];
	char * pcChar2		= new char [ STRING_BUFFER ];
	char szChar1[STRING_BUFFER] =  "Techwing";
	char szChar2[STRING_BUFFER] =  "Bye!";
	
	CMyString string1	= (CMyString)"SW-3 HAN DAE HYUN";
	CMyString string2	= (CMyString)"Hello World!";
	
	strcpy_s(pcChar1, STRING_BUFFER, "Hi! World");
	strcpy_s(pcChar2, STRING_BUFFER, "Bye Bye!");
	
	cout << nInt1 << ", " << nInt2 << endl;
	swapValues(nInt1, nInt2);
	cout << nInt1 << ", " << nInt2 << endl;
	
	cout << fFloat1 << ", " << fFloat2 << endl;
	swapValues(fFloat1, fFloat2);
	cout << fFloat1 << ", " << fFloat2 << endl;
	
	cout << pcChar1 << ", " << pcChar2 << endl;
	swapValues(pcChar1, pcChar2);
	cout << pcChar1 << ", " << pcChar2 << endl;
	
	cout << szChar1 << ", " << szChar2 << endl;
	swapValues(szChar1, szChar2);
	cout << szChar1 << ", " << szChar2 << endl;
	
	cout << string1 << ", " << string2 << endl;
	swapValues(string1, string2);
	cout << string1 << ", " << string2 << endl;
	
	cout << endl << endl << "7-10-2�� �����Դϴ�." << endl;
	cout << endl << endl << "int ����" << endl << endl;
	// int
	CStack<int> stackInt(5);
	push(stackInt, 10);
	pop(stackInt);
	pop(stackInt);
	pop(stackInt);
	pop(stackInt);
	push(stackInt, 10);
	push(stackInt, 20);
	push(stackInt, 30);
	push(stackInt, 40);
	push(stackInt, 50);
	push(stackInt, 60);
	pop(stackInt);

	cout << endl << endl << "float ����" << endl << endl;
	// float
	CStack<float> stackFloat;
	push(stackFloat, (float)10.123);
	push(stackFloat, (float)10.1234);
	push(stackFloat, (float)14.4);
	push(stackFloat, (float)1818.1);
	pop(stackFloat);
	
	cout << endl << endl << "char * ����" << endl << endl;
	// char *
	CStack<char *> stackpChar(5);
	push(stackpChar, (char *)"Hi!!");
	push(stackpChar, (char *)"My name is");
	push(stackpChar, (char *)"Han dae-hyun");
	push(stackpChar, (char *)"Nice to meet you.");
	push(stackpChar, (char *)"Techwing SW3 Team");
	push(stackpChar, (char *)"eurghulrhgluhrlgiuhdliugrhliusrhglirg");
	push(stackpChar, (char *)"");
	pop(stackpChar);
	pop(stackpChar);
	pop(stackpChar);
	push(stackpChar, (char *)"Han dae-hyun");
	push(stackpChar, (char *)"Nice to meet you.");
	push(stackpChar, (char *)"Techwing SW3 Team");

	cout << endl << endl << "CMyString ��ü ����" << endl << endl;
	// CMyString
	CStack<CMyString> stackString(5);
	push(stackpChar, (char *)"Hi!!");
	push(stackpChar, (char *)"My name is");
	push(stackpChar, (char *)"Han dae-hyun");
	push(stackpChar, (char *)"Nice to meet you.");
	push(stackpChar, (char *)"Techwing SW3 Team");
	pop(stackpChar);
	pop(stackpChar);
	pop(stackpChar);
	push(stackpChar, (char *)"Han dae-hyun");
	push(stackpChar, (char *)"Nice to meet you.");
	push(stackpChar, (char *)"Techwing SW3 Team");

	// �߰�
	CMyString string;
	cin >> string;
	cout << string << endl;

	cout << typeid(string).name() << endl;

	return 0;
}