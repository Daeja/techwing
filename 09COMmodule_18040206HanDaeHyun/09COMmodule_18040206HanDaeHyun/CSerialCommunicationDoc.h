#pragma once

// CSerialCommunicationDoc 문서입니다.

enum _eBaudRate
{
	eBAUD110	=	(110),
	eBAUD300	=	(300),
	eBAUD600	=	(600),
	eBAUD1200	=	(1200),
	eBAUD2400	=	(2400),
	eBAUD4800	=	(4800),
	eBAUD9600	=	(9600),
	eBAUD14400	=	(14400),
	eBAUD19200	=	(19200),
	eBAUD38400	=	(19200),
	eBAUD57600	=	(19200),
	eBAUD115200	=	(115200),
	eBAUD128000	=	(128000),
	eBAUD256000	=	(256000)
};

enum _eParity
{
	ePARITY0	=	0,
	ePARITY1	=	1,
	ePARITY2	=	2,
	ePARITY3	=	3,
	ePARITY4	=	4
};

#define STRING_BUFFER (100)

class CSerialCommunicationDoc : public CDocument
{
	DECLARE_DYNCREATE(CSerialCommunicationDoc)

public:
	CSerialCommunicationDoc();
	virtual ~CSerialCommunicationDoc();
#ifndef _WIN32_WCE
	virtual void Serialize(CArchive& ar);   // 문서 입/출력을 위해 재정의되었습니다.
#endif
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual BOOL OnNewDocument();

	DECLARE_MESSAGE_MAP()
public:
private:
	HANDLE m_hWnd;
	char *m_pcPortName;
	int m_nDataBit;
	DCB m_dcb;
	COMMTIMEOUTS m_commTimeouts;
public:
	bool OpenPort(char * pcPortName);
	bool ConfigurePort(DWORD dwBaudRate, BYTE byDataBit, BYTE byParity, BYTE byStopBit);
	bool SetTimeOuts(DWORD ReadIntervalTimeout, DWORD ReadTotalTimeoutMultiplier, DWORD ReadTotalTimeoutConstant, DWORD WriteTotalTimeoutMultiplier, DWORD WriteTotalTimeoutConstant);
	void ClosePort(void);
	void Write(BYTE bybyte);
	void Read(BYTE & byResult);
	bool IsConnected(void);
};
