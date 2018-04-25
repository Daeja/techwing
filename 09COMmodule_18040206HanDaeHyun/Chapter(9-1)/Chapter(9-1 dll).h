// 다음 ifdef 블록은 DLL에서 내보내기하는 작업을 쉽게 해 주는 매크로를 만드는 
// 표준 방식입니다. 이 DLL에 들어 있는 파일은 모두 명령줄에 정의된 _EXPORTS 기호로
// 컴파일되며, 다른 프로젝트에서는 이 기호를 정의할 수 없습니다.
// 이렇게 하면 소스 파일에 이 파일이 들어 있는 다른 모든 프로젝트에서는 
// CHAPTER91DLL_API 함수를 DLL에서 가져오는 것으로 보고, 이 DLL은
// 이 DLL은 해당 매크로로 정의된 기호가 내보내지는 것으로 봅니다.
#ifdef CHAPTER91DLL_EXPORTS
#define CHAPTER91DLL_API __declspec(dllexport)
#else
#define CHAPTER91DLL_API __declspec(dllimport)
#endif

#pragma once
#include "stdafx.h"
#include "CMyString.h"

// 이 클래스는 Chapter(9-1 dll).dll에서 내보낸 것입니다.
class CHAPTER91DLL_API CChapter91dll {
public:
	CChapter91dll(void);
	// TODO: 여기에 메서드를 추가합니다.
};

#define BUFF_SIZE	(512)
#define PORT_NAME	(5)
 
class CHAPTER91DLL_API CRsPort  
{
public:
    BOOL           m_Connect;
    HANDLE         m_idComDev;
public:
    int ReadCommPort( unsigned char * message, DWORD length);
    int WriteCommPort( unsigned char * message, DWORD dwLength);
	void CloseCommPort(void);
    bool IsCommPortOpen();
    CRsPort(CMyString m_portName);
    CRsPort(CMyString m_portName, DWORD BaudRate, BYTE ByteSize, BYTE Parity, BYTE StopBits );
    virtual ~CRsPort();
	int CountRx();
	bool m_bStopRequest;
 
protected:
    BOOL SetupConnection(void);
    void initComport( CMyString m_portName );
    OVERLAPPED     osWrite;
    OVERLAPPED     osRead;
    DCB            dcb_setup;
	void GetWC(char * pcTemp, wchar_t * pwc);
};