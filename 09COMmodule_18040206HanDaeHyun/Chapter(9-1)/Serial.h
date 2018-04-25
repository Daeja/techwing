#pragma once
#include "Chapter09 dll.h"

#define STRING_BUFFER	(512)

class CHAPTER09DLL_API CSerial : public CCommunication
{
public:
	CSerial(void);
	~CSerial(void);
	virtual bool Open(char * pcIP, int nPort);
	virtual void Close();
	virtual bool Send(char * pcIP, int nPort, char * pcContents, int nLength, int nFlag);
	virtual char * Receive(char * pcIP, int nPort, char * pcContents, int nLength);
	virtual int CountRx();
	virtual bool IsConnected();

	bool ConfigurePort(DWORD dwBaudRate, BYTE byDataBit, BYTE byParity, BYTE byStopBit);
	bool SetTimeOuts(DWORD ReadIntervalTimeout, DWORD ReadTotalTimeoutMultiplier, DWORD ReadTotalTimeoutConstant, DWORD WriteTotalTimeoutMultiplier, DWORD WriteTotalTimeoutConstant);

private :
	HANDLE m_hWnd;
	int m_nDataBit;
	DCB m_dcb;
	COMMTIMEOUTS m_commTimeouts;
};