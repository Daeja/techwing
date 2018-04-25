// CSerialCommunicationDoc.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "09COMmodule_18040206HanDaeHyun.h"
#include "CSerialCommunicationDoc.h"

// CSerialCommunicationDoc

IMPLEMENT_DYNCREATE(CSerialCommunicationDoc, CDocument)

CSerialCommunicationDoc::CSerialCommunicationDoc()
: m_pcPortName(NULL)
{
}

BOOL CSerialCommunicationDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
	return TRUE;
}

/***************************************************************************************
NAME		: ~CSerialCommunicaton
PARAMS		: [IN ] nont
			  [OUT] none
COMMENTS	: �Ҹ����Լ�
WARNINGS	: none
***************************************************************************************/
CSerialCommunicationDoc::~CSerialCommunicationDoc()
{
	delete [] m_pcPortName;
}


BEGIN_MESSAGE_MAP(CSerialCommunicationDoc, CDocument)
END_MESSAGE_MAP()


// CSerialCommunicationDoc �����Դϴ�.

#ifdef _DEBUG
void CSerialCommunicationDoc::AssertValid() const
{
	CDocument::AssertValid();
}

#ifndef _WIN32_WCE
void CSerialCommunicationDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif
#endif //_DEBUG

#ifndef _WIN32_WCE
// CSerialCommunicationDoc serialization�Դϴ�.

void CSerialCommunicationDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	}
	else
	{
		// TODO: ���⿡ �ε� �ڵ带 �߰��մϴ�.
	}
}
#endif


// CSerialCommunicationDoc ����Դϴ�.
/*
typedef struct _DCB��		// dcb
  DWORD DCBlength;			// DCB ������
  DWORD BaudRate;			// ���� ������Ʈ
  DWORD fBinary:1;			// ���̳ʸ� ���, EOF üũ����
  DWORD fParity:1;			// �и�Ƽ üũ
  DWORD fOutxCtsFlow:1;		// CTS ��� �÷�����
  DWORD fOutxDsrFlow:1;		// DSR ��� �÷�����
  DWORD fDtrControl:2;		// DTR �÷� ���� Ÿ��
  DWORD fDsrSensitivity:1;	// DSR ����
  DWORD fTXContinueOnXoff:1;// XOFF��� ��� ����
  DWORD fOutX:1;			// XON/XOFF �ܺ� �÷� ����
  DWORD fInX:1;				// XON/XOFF ���� �÷� ���� 
  DWORD fErrorChar:1;		// ���� ����(���� ġȯ ����)
  DWORD fNull:1;			// ���� �������� NULL ���ֱ�
  DWORD fRtsControl:2;		// RTS �÷� ����
  DWORD fAbortOnError:1;	// ���� �߻��� ����� ���
  DWORD fDummy2:17;			// ����
  WORD wReserved;			// ���� �̻��
  WORD XonLim;				// �۽� XON ����ġ
  WORD XoffLim;				// �۽� XOFF ����ġ
  BYTE ByteSize;			// 1����Ʈ�� ��Ʈ ��, 4-8
  BYTE Parity;				// 0~4, �и�Ƽ ����, Ȧ��, ¦��, ��ũ, �����̽�
  BYTE StopBits;			// 0~2 = 1, 1.5, 2
  char XonChar;				// �ۼ��� XON ����
  char XoffChar;			// �ۼ��� XOFF ����
  char ErrorChar;			// ���� ġȯ ����
  char EofChar;				// �Է� ���� ����
  char EvtChar;				// ���� �̺�Ʈ ����
  WORD wReserved1;			// ����, ���Ұ�
��DCB;
*/

/***************************************************************************************
NAME		: Open
PARAMS		: [IN ] char * pcPortName
			  [OUT] bool
COMMENTS	: �ش� �Լ��� ����Ͽ� �Ѱ� ���� ����(char * pcPortName)�� �Ǿ��ִ� port name��
			  �����Ͽ� port�� ����.
			  port�� ������ ���� ��� -1(INVALID_HANDLE_VALUE)�� ��ȯ�Ѵ�.
WARNINGS	: �޾ƿ� ����(char * pcPortName)�� ���� delete�ؼ� �ȵȴ�.
***************************************************************************************/
bool CSerialCommunicationDoc::OpenPort(char * pcPortName)
{
	char * pcTemp = new char [strlen(pcPortName) + 4];
	strcpy_s(pcTemp, strlen(pcPortName) + 4, pcPortName);
	strcat_s(pcTemp, strlen(pcPortName) + 4, "//./");

	m_hWnd = CreateFile(pcTemp, GENERIC_READ | GENERIC_WRITE, 0, 0, OPEN_EXISTING, 0, 0);

	if(INVALID_HANDLE_VALUE == m_hWnd)
	{
		delete [] pcTemp;
		return false;
	}

	delete [] pcTemp;
	return true;
}

/***************************************************************************************
NAME		: ConfigurePort
PARAMS		: [IN ] DWORD dwBaudRate
					BYTE byDataBit
					BYTE byParity
					BYTE byStopBit
			  [OUT] bool
COMMENTS	: ��Ʈ�� open �� �������(m_dcb)�� Ư�� ���� ���� �����Ǵ� �����̴�.
			  ���ڷ� �Ѱ��ִ� dwBaudRate�� �����Ʈ(110 ~ 256k), byDataBit�� ������ ����,
			  byParity�� �и�Ƽ��Ʈ�� ����, byStopBit�� ������Ʈ�� ��Ÿ����.
WARNINGS	: �Ϲ� Parity�� fParity �������� ����
			  => fParity�� ��� flow control�� �����Ǿ������� �ش� ������ ���ȴ�.
			  [20180417] ���� ���� ��� fParity�� ���� 0(��� ����)���� ����
***************************************************************************************/
bool CSerialCommunicationDoc::ConfigurePort(DWORD dwBaudRate, BYTE byDataBit, BYTE byParity, BYTE byStopBit)
{
	if(false == GetCommState(m_hWnd, &m_dcb))
	{
		CloseHandle(m_hWnd);
		return false;
	}// GetCommState�� ��ȯ���� bool�̸� �ش� m_dcb�� ��ü ���¸� �ҷ����� ���ϸ� false�� ��ȯ�Ѵ�.

	//��Ʈ�� ���� �⺻���� ����
	m_dcb.BaudRate          = dwBaudRate;
	m_dcb.ByteSize          = byDataBit;
	m_dcb.Parity            = byParity ;
	m_dcb.StopBits          = byStopBit;
	m_dcb.fBinary           = true;
	m_dcb.fDsrSensitivity   = false;
	m_dcb.fParity           = 0;		// ������� No Parity�� ����
	m_dcb.fOutX             = false;
	m_dcb.fInX              = false;
	m_dcb.fNull             = false;
	m_dcb.fAbortOnError     = true;
	m_dcb.fOutxCtsFlow      = false;
	m_dcb.fOutxDsrFlow      = false;
	m_dcb.fDtrControl       = DTR_CONTROL_DISABLE;
	m_dcb.fDsrSensitivity   = false;
	m_dcb.fRtsControl       = RTS_CONTROL_DISABLE;
	m_dcb.fOutxCtsFlow      = false;
	m_dcb.fOutxCtsFlow      = false;
	
	if(false == SetCommState(m_hWnd, &m_dcb))
	{
		CloseHandle(m_hWnd);
		return false;
	} // SetCommState�� ��ȯ���� bool�̸� �ش� m_dcb�� ��ü ������ �Ϸ� �Ǹ� true�� ��ȯ�Ѵ�.

	return true;
}

/***************************************************************************************
NAME		: SetTimeout
PARAMS		: [IN ] DWORD ReadIntervalTimeout
					DWORD ReadTotalTimeoutMultiplier
					DWORD ReadTotalTimeoutConstant
					DWORD WriteTotalTimeoutMultiplier
					DWORD WriteTotalTimeoutConstant
			  [OUT] bool
COMMENTS	: TimeOuts ����ü�� ���� ���� �Լ�
WARNINGS	: ReadIntervalTimeout
			  -> �����͸� ������ �� �ѹ��ڸ� ������ �� ���� ���ڸ� ������ �������� ���
				 �ð����� �и��� ������ �����Ѵ�. �� ��� �ð� ��ŭ ��ٸ� �� �Է��� ���� ���
				 ������ �����͸� ��ȯ�Ѵ�.
			  ReadTotalTimeoutMultiplier
			  -> �б� �۾��� ���� ��Ż Ÿ�Ӿƿ� �ð��� ����ϱ� ���� �и��� ������ ���ϱ�
				 ����� �����Ѵ�.
			  ReadTotalTimeoutConstant
			  -> �б� �۾��� ���� ��Ż Ÿ�Ӿƿ� �ð��� ����ϱ� ���� �и� �� ������
				 �����ϴ� ������ ���ȴ�.
			  WriteTotalTimeoutMultiplier
			  -> ���� �۾��� ���� ��Ż Ÿ�Ӿƿ� �ð��� ����ϱ� ���� �и��� ������ ���ϱ�
				 ����� �����Ѵ�.
			  WriteTotalTimeoutConstant
			  -> ���� �۾��� ���� ��Ż Ÿ�Ӿƿ� �ð��� ����ϱ� ���� �и� �� ������ �����ϴ�
				 ������ ���ȴ�.
***************************************************************************************/
bool CSerialCommunicationDoc::SetTimeOuts(DWORD ReadIntervalTimeout, DWORD ReadTotalTimeoutMultiplier, DWORD ReadTotalTimeoutConstant, DWORD WriteTotalTimeoutMultiplier, DWORD WriteTotalTimeoutConstant)
{
	if(false == GetCommTimeouts(m_hWnd, &m_commTimeouts))
	{
		return false;
	}

	m_commTimeouts.ReadIntervalTimeout          = ReadIntervalTimeout;
	m_commTimeouts.ReadTotalTimeoutConstant     = ReadTotalTimeoutConstant;
	m_commTimeouts.ReadTotalTimeoutMultiplier   = ReadTotalTimeoutMultiplier;
	m_commTimeouts.WriteTotalTimeoutConstant    = WriteTotalTimeoutConstant;
	m_commTimeouts.WriteTotalTimeoutMultiplier  = WriteTotalTimeoutMultiplier;

	if(false == SetCommTimeouts(m_hWnd, &m_commTimeouts))
	{
		return false;
	}

	return true;
}

/***************************************************************************************
NAME		: ClosePort
PARAMS		: [IN ] none
			  [OUT] none
COMMENTS	: Open�� port�� close ��Ų��.
WARNINGS	: none
***************************************************************************************/
void CSerialCommunicationDoc::ClosePort(void)
{
	CloseHandle(m_hWnd);
}

/***************************************************************************************
NAME		: WriteByte
PARAMS		: [IN ] BYTE byByte
			  [OUT] none
COMMENTS	: Open�� port�� close ��Ų��.
WARNINGS	: none
***************************************************************************************/
void CSerialCommunicationDoc::Write(BYTE byByte)
{
	DWORD dwBytesWritten = 0;

	WriteFile(m_hWnd, &byByte, 1, &dwBytesWritten, NULL);
}

/***************************************************************************************
NAME		: ReadByte
PARAMS		: [IN ] BYTE byByte
			  [OUT] none
COMMENTS	: Open�� port�� close ��Ų��.
WARNINGS	: none
***************************************************************************************/
void CSerialCommunicationDoc::Read(BYTE & byResult) 
{
	BYTE rx;
	byResult=0;

	DWORD dwBytesTransferred=0;

	if(ReadFile(m_hWnd, &rx, 1, &dwBytesTransferred, 0))
	{
		if(dwBytesTransferred == 1)
		{
			byResult=rx;
		}
	}
}

/***************************************************************************************
NAME		: IsConnected
PARAMS		: [IN ] none
			  [OUT] bool
COMMENTS	: m_hWnd�� ������ �޾� ���� ������ ����(true, false)�� �Ǵ��Ѵ�.
WARNINGS	: none
***************************************************************************************/
bool CSerialCommunicationDoc::IsConnected(void)
{
	if(INVALID_HANDLE_VALUE == m_hWnd)
	{
		return false;
	}

	return true;
}
