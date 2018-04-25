// ���� ifdef ����� DLL���� ���������ϴ� �۾��� ���� �� �ִ� ��ũ�θ� ����� 
// ǥ�� ����Դϴ�. �� DLL�� ��� �ִ� ������ ��� ����ٿ� ���ǵ� _EXPORTS ��ȣ��
// �����ϵǸ�, �ٸ� ������Ʈ������ �� ��ȣ�� ������ �� �����ϴ�.
// �̷��� �ϸ� �ҽ� ���Ͽ� �� ������ ��� �ִ� �ٸ� ��� ������Ʈ������ 
// CHAPTER91DLL_API �Լ��� DLL���� �������� ������ ����, �� DLL��
// �� DLL�� �ش� ��ũ�η� ���ǵ� ��ȣ�� ���������� ������ ���ϴ�.
#ifdef CHAPTER91DLL_EXPORTS
#define CHAPTER91DLL_API __declspec(dllexport)
#else
#define CHAPTER91DLL_API __declspec(dllimport)
#endif

#pragma once
#include "stdafx.h"
#include "CMyString.h"

// �� Ŭ������ Chapter(9-1 dll).dll���� ������ ���Դϴ�.
class CHAPTER91DLL_API CChapter91dll {
public:
	CChapter91dll(void);
	// TODO: ���⿡ �޼��带 �߰��մϴ�.
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