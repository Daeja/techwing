#include "CLogger.h"
#include "stdafx.h"

/********************************************************************************
AUTHOR		: �Ѵ���
NAME		: CLogger(void)
RETURNS		: �������Լ��̸�, ��ȯ�� ����
COMMENTS	: ����Ʈ �������Լ��� ����
********************************************************************************/
CLogger::CLogger()
{
}

/********************************************************************************
AUTHOR		: �Ѵ���
NAME		: ~CLogger(void)
RETURNS		: �Ҹ����Լ��̸�, ��ȯ�� ����
COMMENTS	: ����Ʈ �Ҹ����Լ��� ����
********************************************************************************/
CLogger::~CLogger()
{
}

/********************************************************************************
AUTHOR		: �Ѵ���
NAME		: CLogger(char * pcFileNameExtension)
RETURNS		: �������Լ��̸�, ��ȯ�� ����
COMMENTS	: ����Ʈ �����ڸ� Override�Ͽ� ���ڷ� Ȯ����(.*)�� �Է� �ް� ������
********************************************************************************/
CLogger::CLogger( char * pcFileNameExtension )
{
	if( NULL == pcFileNameExtension )
	{
		m_FileNameExtension = "txt";
	}
	else
	{
		m_FileNameExtension = pcFileNameExtension;
	}
}

/********************************************************************************
AUTHOR		: �Ѵ���
NAME		: write(char * pcContents)
RETURNS		: void
COMMENTS	: ���ڷ� �޴� pcContents�� ������ �Է��Ͽ� �����ϸ� �ش� ������
			  ���Ͽ� ����ϴ� �Լ�
********************************************************************************/
void CLogger::write(char * pcContents)
{
	CMyString fileName	= (CMyString)NULL;
	char * pcFileName	= new char [ NAME_BUFFER ];

	SYSTEMTIME curTime;
	GetLocalTime( &curTime );

	sprintf(pcFileName, "%4d%02d%02d.%s", curTime.wYear, curTime.wMonth, curTime.wDay, m_FileNameExtension);

	fileName = pcFileName;

	if( NULL == pcContents )
	{
		pcContents = "���� �����ϴ�.";
	}

	ofstream oStream;

	oStream.open(fileName, ios_base::app | ios_base::out);

	if ( !oStream )
	{
		cerr << "����� ���� ���¿� �����߽��ϴ�.!" << endl;
	}

	char * pcHeader = new char [ HEADER_BUFFER ];

	sprintf(pcHeader, "%02d:%02d:%02d->", curTime.wHour, curTime.wMinute, curTime.wSecond);

	if ( oStream )
	{
		oStream << pcHeader << pcContents << endl;

		oStream.close();
	}

	delete [] pcFileName;
	delete [] pcHeader;
}