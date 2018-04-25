#include "CMyString.h"	
/********************************************************************************
AUTHOR		: �Ѵ���
NAME		: CMyString
RETURNS		: �������Լ��̸�, ��ȯ�� ����
COMMENTS	: ����Ʈ �������Լ��� ����
********************************************************************************/
CMyString::CMyString()
{
	m_pcString = new char[STRING_BUFFER];
	m_pcString[0] = '\0';
}

/********************************************************************************
AUTHOR		: �Ѵ���
NAME		: CMyString
PARAMS		: [IN ] * pcString
RETURNS		: �������Լ��̸�, ��ȯ�� ����
COMMENTS	: pcString������ ���ڷ� �޾� �������(m_pcString)�� �����Ѵ�.
			  ��ȯ �������̸� ���� ���縦 �Ѵ�.
********************************************************************************/
CMyString::CMyString(char * pcString)
{
	m_nStringSize = getSize(pcString);
	m_pcString = new char[m_nStringSize];

	strcpy(m_pcString, pcString);
}

/********************************************************************************
AUTHOR		: �Ѵ���
NAME		: ~CMyString
RETURNS		: �Ҹ����Լ��̸�, ��ȯ�� ����
COMMENTS	: �޸� ���� Ȯ�� �ʼ�!! (delete or free)
********************************************************************************/
CMyString::~CMyString()
{
	delete [] m_pcString;
	cout << "�Ҹ��� ȣ��" << endl;
}

/********************************************************************************
AUTHOR		: �Ѵ���
NAME		: getSize
PARAMS		: [IN ] * pcString
RETURNS		: ���ڿ��� ����(int)�� ��ȯ�Ѵ�.
COMMENTS	: ���ڿ��� Ư�� �� �� �κп� '\n'�� ����
********************************************************************************/
int CMyString::getSize(char * pcString)
{
	return strlen(pcString) + 1;
}

/********************************************************************************
AUTHOR		: �Ѵ���
NAME		: SetString
PARAMS		: [IN ] * pcString
RETURNS		: ��ȯ�� ����
COMMENTS	: �����ϴ� ���ڿ��� ������ delete��Ű�� ���� �޸� �����Ҵ� �Ͽ�
			  ���ο� ���� ����
********************************************************************************/
void CMyString::SetString(char * pcString, bool bDelete)
{
	if( true == bDelete)
	{
		delete [] m_pcString;
	}

	m_nStringSize = getSize(pcString);
	m_pcString = new char[m_nStringSize];
	strcpy(m_pcString, pcString);
}

/********************************************************************************
AUTHOR		: �Ѵ���
NAME		: print
RETURNS		: ��ȯ�� ����
COMMENTS	: ��� ������ �ִ� ������ ����Ѵ�.
********************************************************************************/
void CMyString::print()
{
	cout << m_pcString << endl;
}