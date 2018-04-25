#include "StdAfx.h"
#include "Serial.h"

/***************************************************************************************
NAME		: CSerial
PARAMS		: [IN ] none
			  [OUT] none
COMMENTS	: 생성자함수
WARNINGS	: none
***************************************************************************************/
CSerial::CSerial(void)
{
}

/***************************************************************************************
NAME		: ~CSerial
PARAMS		: [IN ] none
			  [OUT] none
COMMENTS	: 소멸자함수
WARNINGS	: none
***************************************************************************************/
CSerial::~CSerial(void)
{
}

/***************************************************************************************
NAME		: Open
PARAMS		: [IN ] char * pcPortName
			  [OUT] bool
COMMENTS	: 해당 함수를 사용하여 넘겨 받은 인자(char * pcPortName)로 되어있는 port name에
			  접근하여 port를 연다.
			  port를 얻어오지 못할 경우 -1(INVALID_HANDLE_VALUE)을 반환한다.
WARNINGS	: 받아온 인자(char * pcPortName)를 절대 delete해선 안된다.
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
COMMENTS	: Open된 port를 close 시킨다.
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
COMMENTS	: Open된 port를 close 시킨다.
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
COMMENTS	: Open된 port를 close 시킨다.
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
COMMENTS	: m_hWnd의 내용을 받아 연결 상태의 유무(true, false)를 판단한다.
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
COMMENTS	: 포트를 open 후 멤버변수(m_dcb)가 특정 값에 따라 설정되는 구간이다.
			  인자로 넘겨주는 dwBaudRate는 보어레이트(110 ~ 256k), byDataBit는 데이터 길이,
			  byParity는 패리티비트의 유무, byStopBit는 정지비트를 나타낸다.
WARNINGS	: 일반 Parity와 fParity 변수간의 차이
			  => fParity의 경우 flow control이 설정되어있으면 해당 변수가 사용된다.
			  [20180417] 현재 연습 삼아 fParity의 값을 0(사용 안함)으로 설정
***************************************************************************************/
bool CSerial::ConfigurePort(DWORD dwBaudRate, BYTE byDataBit, BYTE byParity, BYTE byStopBit)
{
	if(false == GetCommState(m_hWnd, &m_dcb))
	{
		CloseHandle(m_hWnd);
		return false;
	}// GetCommState의 반환형은 bool이며 해당 m_dcb의 객체 상태를 불러오지 못하면 false를 반환한다.

	//포트의 대한 기본값을 설정
	m_dcb.BaudRate          = dwBaudRate;
	m_dcb.ByteSize          = byDataBit;
	m_dcb.Parity            = byParity ;
	m_dcb.StopBits          = byStopBit;
	m_dcb.fBinary           = true;
	m_dcb.fDsrSensitivity   = false;
	m_dcb.fParity           = 0;		// 연습삼아 No Parity로 지정
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
	} // SetCommState의 반환형은 bool이며 해당 m_dcb의 객체 설정이 완료 되면 true를 반환한다.

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
COMMENTS	: TimeOuts 구조체의 내용 설정 함수
WARNINGS	: ReadIntervalTimeout
			  -> 데이터를 수신할 때 한문자를 수신한 후 다음 문자를 수신할 때까지의 대기
				 시간으로 밀리초 단위로 설장한다. 이 대기 시간 만큼 기다린 후 입력이 없을 경우
				 수신한 데이터를 반환한다.
			  ReadTotalTimeoutMultiplier
			  -> 읽기 작업을 위한 토탈 타임아웃 시간을 계산하기 위한 밀리초 단위의 곱하기
				 계수를 지정한다.
			  ReadTotalTimeoutConstant
			  -> 읽기 작업을 위한 토탈 타임아웃 시간을 계산하기 위한 밀리 초 단위로
				 지정하는 정수로 사용된다.
			  WriteTotalTimeoutMultiplier
			  -> 쓰기 작업을 위한 토탈 타임아웃 시간을 계산하기 위한 밀리초 단위의 곱하기
				 계수를 지정한다.
			  WriteTotalTimeoutConstant
			  -> 쓰기 작업을 위한 토탈 타임아웃 시간을 계산하기 위한 밀리 초 단위로 지정하는
				 정수로 사용된다.
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
COMMENTS	: 부모 클래스의 순수가상함수를 구현하기 위함(예방)
WARNINGS	: 실질적 사용 X
***************************************************************************************/
int CSerial::CountRx()
{
	return 0;
}