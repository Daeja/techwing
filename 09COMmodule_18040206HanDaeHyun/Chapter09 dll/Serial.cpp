#include "StdAfx.h"
#include "Serial.h"

/***************************************************************************************
NAME		: CSerial
PARAMS		: [IN ] none
			  [OUT] none
COMMENTS	: �������Լ�
WARNINGS	: none
***************************************************************************************/
CSerial::CSerial(void)
{
}

/***************************************************************************************
NAME		: ~CSerial
PARAMS		: [IN ] none
			  [OUT] none
COMMENTS	: �Ҹ����Լ�
WARNINGS	: none
***************************************************************************************/
CSerial::~CSerial(void)
{
}

/***************************************************************************************
NAME		: Open
PARAMS		: [IN ] char * pcPortName
			  [OUT] bool
COMMENTS	: �ش� �Լ��� ����Ͽ� �Ѱ� ���� ����(char * pcPortName)�� �Ǿ��ִ� port name��
			  �����Ͽ� port�� ����.
			  port�� ������ ���� ��� -1(INVALID_HANDLE_VALUE)�� ��ȯ�Ѵ�.
WARNINGS	: �޾ƿ� ����(char * pcPortName)�� ���� delete�ؼ� �ȵȴ�.
***************************************************************************************/
bool CSerial::Open(char * pcIP, int nPort)
{
	char * pcPort = new char [strlen(pcIP) + 4];
	strcpy_s(pcPort, strlen(pcIP) + 4, pcIP);
	strcat_s(pcPort, strlen(pcIP) + 4, "//./");

	m_hWnd = CreateFile((LPCWSTR)(LPSTR)pcPort, GENERIC_READ | GENERIC_WRITE, 0, 0, OPEN_EXISTING, 0, 0);

	if(INVALID_HANDLE_VALUE == m_hWnd)
	{
		delete [] pcPort;
		return false;
	}

	delete [] pcPort;
	return true;
}

/***************************************************************************************
NAME		: ClosePort
PARAMS		: [IN ] none
			  [OUT] none
COMMENTS	: Open�� port�� close ��Ų��.
WARNINGS	: none
***************************************************************************************/
void CSerial::Close()
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
bool CSerial::Send(char * pcIP, int nPort, char * pcContents, int nLength, int nFlag)
{
	DWORD dwBytesWritten = 0;
	int nError = 0;

	if(nError = WriteFile(m_hWnd, &pcContents, nLength, &dwBytesWritten, NULL))
	{
		return false;
	}

	return true;
}

/***************************************************************************************
NAME		: ReadByte
PARAMS		: [IN ] BYTE byByte
			  [OUT] none
COMMENTS	: Open�� port�� close ��Ų��.
WARNINGS	: none
***************************************************************************************/
char * CSerial::Receive(char * pcIP, int nPort, char * pcContents, int nLength)
{
	DWORD dwBytesTransferred=0;

	ReadFile(m_hWnd, pcContents, nLength, &dwBytesTransferred, 0);

	return pcContents;
}

/***************************************************************************************
NAME		: IsConnected
PARAMS		: [IN ] none
			  [OUT] bool
COMMENTS	: m_hWnd�� ������ �޾� ���� ������ ����(true, false)�� �Ǵ��Ѵ�.
WARNINGS	: none
***************************************************************************************/
bool CSerial::IsConnected()
{
	if(INVALID_HANDLE_VALUE == m_hWnd)
	{
		return false;
	}

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
bool CSerial::ConfigurePort(DWORD dwBaudRate, BYTE byDataBit, BYTE byParity, BYTE byStopBit)
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
bool CSerial::SetTimeOuts(DWORD ReadIntervalTimeout, DWORD ReadTotalTimeoutMultiplier, DWORD ReadTotalTimeoutConstant, DWORD WriteTotalTimeoutMultiplier, DWORD WriteTotalTimeoutConstant)
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
NAME		: CountRx
PARAMS		: [IN ] none
			  [OUT] none
COMMENTS	: �θ� Ŭ������ ���������Լ��� �����ϱ� ����(����)
WARNINGS	: ������ ��� X
***************************************************************************************/
int CSerial::CountRx()
{
	return 0;
}