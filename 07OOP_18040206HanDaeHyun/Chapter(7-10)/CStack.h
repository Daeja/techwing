#pragma once
#include <iostream>
#include "CMyString.h"
using namespace std;

#define INITIALIZE		(1)
#define DEFAULT_SIZE	(10)
#define STRING_BUFFER	(100)

#define ZERO			(0)

#define PUSH_SUCCESS	(1)
#define PUSH_ERROR		(0)
#define POP_SUCCESS		(1)
#define POP_ERROR		(0)

template <class T>
class CStack
{
private :
	T * m_parameter;
	int m_nPointer;
	int m_nSize;
public:
	CStack(void);
	CStack(int nSize);
	~CStack(void);
	int isEmpty();
	int isFulled();
	int push(T param);
	int pop(T & returnTemplate);
};

template <>
class CStack<char *>
{
private :
	CMyString * m_parameter;
	int m_nPointer;
	int m_nSize;
public:
	/********************************************************************************
	AUTHOR		: 한대현
	NAME		: CStack
	RETURNS		: 생성자함수이며, 반환값 없음
	COMMENTS	: 디폴트 생성자함수로 쓰임
				  기본크기 => 10
	********************************************************************************/
	CStack(void)
	{
		m_parameter = new CMyString [DEFAULT_SIZE];
		m_nPointer = -1;
	}

	/********************************************************************************
	AUTHOR		: 한대현
	NAME		: CStack
	PARAMS		: [IN ] nSize
				  [OUT] void
	COMMENTS	: 생성자함수의 Override
				  nSize가 NULL이라면 기본크기(10)으로 할당
				  nSize가 NULL이 아니라면 입력 받은 크기로 지정
	********************************************************************************/
	CStack(int nSize)
	{
		if( ZERO >= nSize )
		{
			m_parameter = new CMyString [DEFAULT_SIZE];
			m_nSize = DEFAULT_SIZE;
		}
		else
		{
			m_parameter = new CMyString [nSize];
			m_nSize = nSize;
		}

		m_nPointer = -1;
	}

	/********************************************************************************
	AUTHOR		: 한대현
	NAME		: ~CStack
	RETURNS		: 소멸자함수이며, 반환값 없음
	COMMENTS	: 디폴트 소멸자함수로 쓰임
	********************************************************************************/
	~CStack(void)
	{
		delete [] m_parameter;
	}

	/********************************************************************************
	AUTHOR		: 한대현
	NAME		: isEmpty
	COMMENTS	: 스택이 비어있는지 확인
	********************************************************************************/
	bool isEmpty()
	{
		return ( m_nPointer == -1 ) ? false : true;
	}

	/********************************************************************************
	AUTHOR		: 한대현
	NAME		: isFulled
	COMMENTS	: 스택이 꽉차있는지 확인
	********************************************************************************/
	bool isFulled()
	{
		return ( m_nPointer == (m_nSize - 1) ) ? false : true;
	}

	/********************************************************************************
	AUTHOR		: 한대현
	NAME		: push
	PARAMS		: [IN ] pcString
				  [OUT] int
	COMMENTS	: push 원형의 함수 overloading
	********************************************************************************/
	int push(char * pcString)
	{
		bool bPossible = isFulled();
		if( NULL != pcString )
		{
			if( bPossible )
			{
				m_nPointer++;
				m_parameter[ m_nPointer ] = pcString;

				return PUSH_SUCCESS;
			}
		}

		return PUSH_ERROR;
	}

	/********************************************************************************
	AUTHOR		: 한대현
	NAME		: pop
	PARAMS		: [IN ] bIsSuccess
				  [OUT] int
	COMMENTS	: 스택의 인자 하나는 pop 연산한다.
				  스택이 비어있다면 수행하지 않고 0을 반환한다.
	********************************************************************************/
	int pop(char * c1)
	{
		bool bPossible = isEmpty();

		if( bPossible )
		{
			strcpy(c1, m_parameter[m_nPointer]);

			m_nPointer--;

			return POP_SUCCESS;
		}

		c1 = "";

		return POP_ERROR;
	}
};

/********************************************************************************
AUTHOR		: 한대현
NAME		: CStack
RETURNS		: 생성자함수이며, 반환값 없음
COMMENTS	: 디폴트 생성자함수로 쓰임
			  기본크기 => 10
********************************************************************************/
template <class T>
CStack<T>::CStack(void)
{
	m_parameter = new T [DEFAULT_SIZE];
	m_nPointer = -1;
}

/********************************************************************************
AUTHOR		: 한대현
NAME		: CStack
PARAMS		: [IN ] nSize
			  [OUT] void
COMMENTS	: 생성자함수의 Override
			  nSize가 NULL이라면 기본크기(10)으로 할당
			  nSize가 NULL이 아니라면 입력 받은 크기로 지정
********************************************************************************/
template <class T>
CStack<T>::CStack(int nSize)
{
	if( ZERO >= nSize )
	{
		m_parameter = new T [DEFAULT_SIZE];
		m_nSize = DEFAULT_SIZE;
	}
	else
	{
		m_parameter = new T [nSize];
		m_nSize = nSize;
	}

	m_nPointer = -1;
}

/********************************************************************************
AUTHOR		: 한대현
NAME		: ~CStack
RETURNS		: 소멸자함수이며, 반환값 없음
COMMENTS	: 디폴트 소멸자함수로 쓰임
********************************************************************************/
template <class T>
CStack<T>::~CStack(void)
{
	delete [] m_parameter;
}

/********************************************************************************
AUTHOR		: 한대현
NAME		: isEmpty
COMMENTS	: 스택이 비어있는지 확인
********************************************************************************/
template <class T>
int CStack<T>::isEmpty()
{
	return ( m_nPointer == -1 ) ? false : true;
}

/********************************************************************************
AUTHOR		: 한대현
NAME		: isFulled
COMMENTS	: 스택이 꽉차있는지 확인
********************************************************************************/
template <class T>
int CStack<T>::isFulled()
{
	return ( m_nPointer == (m_nSize - 1) ) ? false : true;
}

/********************************************************************************
AUTHOR		: 한대현
NAME		: push
PARAMS		: [IN ] param
			  [OUT] bool
COMMENTS	: 스택에 인자로 전달받은 변수를 대입하고 스택 포인터의 값을 +1 한다.
			  스택이 꽉차 있다면 시행하지 않는다.
			  변환 생성자를 위한 explicit을 선언할 필요성이 X
********************************************************************************/
template <class T>
int CStack<T>::push(T param)
{
	int nPossible = isFulled();

	if( nPossible )
	{
		m_nPointer++;
		m_parameter[ m_nPointer ] = param;

		return PUSH_SUCCESS;
	}

	return PUSH_ERROR;
}

/********************************************************************************
AUTHOR		: 한대현
NAME		: pop
PARAMS		: [IN ] bIsSuccess
			  [OUT] T
COMMENTS	: 스택의 인자 하나는 pop 연산한다.
			  스택이 비어있다면 수행하지 않고 0을 반환한다.
********************************************************************************/
template <class T>
int CStack<T>::pop(T & returnTemplate)
{
	int nPossible = isEmpty();

	if( nPossible )
	{
		returnTemplate = m_parameter[ m_nPointer ];
		m_nPointer--;

		return PUSH_SUCCESS;
	}

	return PUSH_ERROR;
}