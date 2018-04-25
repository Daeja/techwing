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
	AUTHOR		: �Ѵ���
	NAME		: CStack
	RETURNS		: �������Լ��̸�, ��ȯ�� ����
	COMMENTS	: ����Ʈ �������Լ��� ����
				  �⺻ũ�� => 10
	********************************************************************************/
	CStack(void)
	{
		m_parameter = new CMyString [DEFAULT_SIZE];
		m_nPointer = -1;
	}

	/********************************************************************************
	AUTHOR		: �Ѵ���
	NAME		: CStack
	PARAMS		: [IN ] nSize
				  [OUT] void
	COMMENTS	: �������Լ��� Override
				  nSize�� NULL�̶�� �⺻ũ��(10)���� �Ҵ�
				  nSize�� NULL�� �ƴ϶�� �Է� ���� ũ��� ����
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
	AUTHOR		: �Ѵ���
	NAME		: ~CStack
	RETURNS		: �Ҹ����Լ��̸�, ��ȯ�� ����
	COMMENTS	: ����Ʈ �Ҹ����Լ��� ����
	********************************************************************************/
	~CStack(void)
	{
		delete [] m_parameter;
	}

	/********************************************************************************
	AUTHOR		: �Ѵ���
	NAME		: isEmpty
	COMMENTS	: ������ ����ִ��� Ȯ��
	********************************************************************************/
	bool isEmpty()
	{
		return ( m_nPointer == -1 ) ? false : true;
	}

	/********************************************************************************
	AUTHOR		: �Ѵ���
	NAME		: isFulled
	COMMENTS	: ������ �����ִ��� Ȯ��
	********************************************************************************/
	bool isFulled()
	{
		return ( m_nPointer == (m_nSize - 1) ) ? false : true;
	}

	/********************************************************************************
	AUTHOR		: �Ѵ���
	NAME		: push
	PARAMS		: [IN ] pcString
				  [OUT] int
	COMMENTS	: push ������ �Լ� overloading
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
	AUTHOR		: �Ѵ���
	NAME		: pop
	PARAMS		: [IN ] bIsSuccess
				  [OUT] int
	COMMENTS	: ������ ���� �ϳ��� pop �����Ѵ�.
				  ������ ����ִٸ� �������� �ʰ� 0�� ��ȯ�Ѵ�.
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
AUTHOR		: �Ѵ���
NAME		: CStack
RETURNS		: �������Լ��̸�, ��ȯ�� ����
COMMENTS	: ����Ʈ �������Լ��� ����
			  �⺻ũ�� => 10
********************************************************************************/
template <class T>
CStack<T>::CStack(void)
{
	m_parameter = new T [DEFAULT_SIZE];
	m_nPointer = -1;
}

/********************************************************************************
AUTHOR		: �Ѵ���
NAME		: CStack
PARAMS		: [IN ] nSize
			  [OUT] void
COMMENTS	: �������Լ��� Override
			  nSize�� NULL�̶�� �⺻ũ��(10)���� �Ҵ�
			  nSize�� NULL�� �ƴ϶�� �Է� ���� ũ��� ����
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
AUTHOR		: �Ѵ���
NAME		: ~CStack
RETURNS		: �Ҹ����Լ��̸�, ��ȯ�� ����
COMMENTS	: ����Ʈ �Ҹ����Լ��� ����
********************************************************************************/
template <class T>
CStack<T>::~CStack(void)
{
	delete [] m_parameter;
}

/********************************************************************************
AUTHOR		: �Ѵ���
NAME		: isEmpty
COMMENTS	: ������ ����ִ��� Ȯ��
********************************************************************************/
template <class T>
int CStack<T>::isEmpty()
{
	return ( m_nPointer == -1 ) ? false : true;
}

/********************************************************************************
AUTHOR		: �Ѵ���
NAME		: isFulled
COMMENTS	: ������ �����ִ��� Ȯ��
********************************************************************************/
template <class T>
int CStack<T>::isFulled()
{
	return ( m_nPointer == (m_nSize - 1) ) ? false : true;
}

/********************************************************************************
AUTHOR		: �Ѵ���
NAME		: push
PARAMS		: [IN ] param
			  [OUT] bool
COMMENTS	: ���ÿ� ���ڷ� ���޹��� ������ �����ϰ� ���� �������� ���� +1 �Ѵ�.
			  ������ ���� �ִٸ� �������� �ʴ´�.
			  ��ȯ �����ڸ� ���� explicit�� ������ �ʿ伺�� X
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
AUTHOR		: �Ѵ���
NAME		: pop
PARAMS		: [IN ] bIsSuccess
			  [OUT] T
COMMENTS	: ������ ���� �ϳ��� pop �����Ѵ�.
			  ������ ����ִٸ� �������� �ʰ� 0�� ��ȯ�Ѵ�.
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