#include "CLogger.h"
#include "stdafx.h"

/********************************************************************************
AUTHOR		: 한대현
NAME		: CLogger(void)
RETURNS		: 생성자함수이며, 반환값 없음
COMMENTS	: 디폴트 생성자함수로 쓰임
********************************************************************************/
CLogger::CLogger()
{
}

/********************************************************************************
AUTHOR		: 한대현
NAME		: ~CLogger(void)
RETURNS		: 소멸자함수이며, 반환값 없음
COMMENTS	: 디폴트 소멸자함수로 쓰임
********************************************************************************/
CLogger::~CLogger()
{
}

/********************************************************************************
AUTHOR		: 한대현
NAME		: CLogger(char * pcFileNameExtension)
RETURNS		: 생성자함수이며, 반환값 없음
COMMENTS	: 디폴트 생성자를 Override하여 인자로 확장자(.*)를 입력 받게 정의함
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
AUTHOR		: 한대현
NAME		: write(char * pcContents)
RETURNS		: void
COMMENTS	: 인자로 받는 pcContents에 내용을 입력하여 전달하면 해당 내용을
			  파일에 출력하는 함수
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
		pcContents = "값이 없습니다.";
	}

	ofstream oStream;

	oStream.open(fileName, ios_base::app | ios_base::out);

	if ( !oStream )
	{
		cerr << "쓰기용 파일 오픈에 실패했습니다.!" << endl;
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