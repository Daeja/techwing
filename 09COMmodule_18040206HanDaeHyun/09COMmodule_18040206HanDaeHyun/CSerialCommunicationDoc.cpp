// CSerialCommunicationDoc.cpp : 구현 파일입니다.
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
COMMENTS	: 소멸자함수
WARNINGS	: none
***************************************************************************************/
CSerialCommunicationDoc::~CSerialCommunicationDoc()
{
	delete [] m_pcPortName;
}


BEGIN_MESSAGE_MAP(CSerialCommunicationDoc, CDocument)
END_MESSAGE_MAP()


// CSerialCommunicationDoc 진단입니다.

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
// CSerialCommunicationDoc serialization입니다.

void CSerialCommunicationDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 여기에 저장 코드를 추가합니다.
	}
	else
	{
		// TODO: 여기에 로딩 코드를 추가합니다.
	}
}
#endif


// CSerialCommunicationDoc 명령입니다.
/*
typedef struct _DCB｛		// dcb
  DWORD DCBlength;			// DCB 사이즈
  DWORD BaudRate;			// 현재 보레이트
  DWORD fBinary:1;			// 바이너리 모드, EOF 체크안함
  DWORD fParity:1;			// 패리티 체크
  DWORD fOutxCtsFlow:1;		// CTS 출력 플로제어
  DWORD fOutxDsrFlow:1;		// DSR 출력 플로제어
  DWORD fDtrControl:2;		// DTR 플로 제어 타입
  DWORD fDsrSensitivity:1;	// DSR 감지
  DWORD fTXContinueOnXoff:1;// XOFF라고 계속 전송
  DWORD fOutX:1;			// XON/XOFF 외부 플로 제어
  DWORD fInX:1;				// XON/XOFF 내부 플로 제어 
  DWORD fErrorChar:1;		// 오류 수정(에러 치환 가능)
  DWORD fNull:1;			// 수신 데이터의 NULL 없애기
  DWORD fRtsControl:2;		// RTS 플로 제어
  DWORD fAbortOnError:1;	// 에러 발생시 입출력 취소
  DWORD fDummy2:17;			// 예약
  WORD wReserved;			// 현재 미사용
  WORD XonLim;				// 송신 XON 제한치
  WORD XoffLim;				// 송신 XOFF 제한치
  BYTE ByteSize;			// 1바이트의 비트 수, 4-8
  BYTE Parity;				// 0~4, 패리티 없음, 홀수, 짝수, 마크, 스페이스
  BYTE StopBits;			// 0~2 = 1, 1.5, 2
  char XonChar;				// 송수신 XON 문자
  char XoffChar;			// 송수신 XOFF 문자
  char ErrorChar;			// 에러 치환 문자
  char EofChar;				// 입력 종료 문자
  char EvtChar;				// 수신 이벤트 문자
  WORD wReserved1;			// 예약, 사용불가
｝DCB;
*/

/***************************************************************************************
NAME		: Open
PARAMS		: [IN ] char * pcPortName
			  [OUT] bool
COMMENTS	: 해당 함수를 사용하여 넘겨 받은 인자(char * pcPortName)로 되어있는 port name에
			  접근하여 port를 연다.
			  port를 얻어오지 못할 경우 -1(INVALID_HANDLE_VALUE)을 반환한다.
WARNINGS	: 받아온 인자(char * pcPortName)를 절대 delete해선 안된다.
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
COMMENTS	: 포트를 open 후 멤버변수(m_dcb)가 특정 값에 따라 설정되는 구간이다.
			  인자로 넘겨주는 dwBaudRate는 보어레이트(110 ~ 256k), byDataBit는 데이터 길이,
			  byParity는 패리티비트의 유무, byStopBit는 정지비트를 나타낸다.
WARNINGS	: 일반 Parity와 fParity 변수간의 차이
			  => fParity의 경우 flow control이 설정되어있으면 해당 변수가 사용된다.
			  [20180417] 현재 연습 삼아 fParity의 값을 0(사용 안함)으로 설정
***************************************************************************************/
bool CSerialCommunicationDoc::ConfigurePort(DWORD dwBaudRate, BYTE byDataBit, BYTE byParity, BYTE byStopBit)
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
COMMENTS	: Open된 port를 close 시킨다.
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
COMMENTS	: Open된 port를 close 시킨다.
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
COMMENTS	: Open된 port를 close 시킨다.
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
COMMENTS	: m_hWnd의 내용을 받아 연결 상태의 유무(true, false)를 판단한다.
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
