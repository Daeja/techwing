#include "StdAfx.h"
#include "TCPClient.h"

/***************************************************************************************
NAME		: CTCPClient
PARAMS		: [IN ] none
			  [OUT] none
COMMENTS	: 생성자함수, WSA Library를 초기화시키는 용도로 사용된다.
WARNINGS	: 해당 함수 내 WSAStartup()가 실행되지 않을 경우 bind()를 실패 할 수 있음
***************************************************************************************/
CTCPClient::CTCPClient(char * pcIP, int nPort, int nFlag) : CEthernet( pcIP, nPort, nFlag)
{
	WSADATA m_wsaData;

	if (WSAStartup(MAKEWORD(2, 2), &m_wsaData) != 0)
	{
		int nErrorcode = 0;
		nErrorcode = WSAGetLastError();
	}

	m_bConnectState = false;

	int nErrorCode = 0;
	u_long ulMode = 0;

	ioctlsocket(m_RecvSock, FIONBIO, &ulMode);

	m_RecvAddr.sin_family = AF_INET;

	if (0 > (m_RecvSock = socket( PF_INET, SOCK_STREAM, 0 )))
	{
		nErrorCode = WSAGetLastError();
	}
}

/***************************************************************************************
NAME		: ~CTCPClient
PARAMS		: [IN ] none
			  [OUT] none
COMMENTS	: 소멸자함수, 소켓을 닫아준다.
WARNINGS	: none
***************************************************************************************/
CTCPClient::~CTCPClient(void)
{
	closesocket( m_RecvSock );
}

/***************************************************************************************
NAME		: Open
PARAMS		: [IN ] char * pcIP
					int nPort
			  [OUT] bool
COMMENTS	: 넘겨받은 pcIP와 nPort를 이용하여 sockaddr_in 구조체 설정을 한 후 소켓을 할당받는다.
			  소켓 할당 및 bind와 listen 실패시 오류를 알 수 있게 WSAGetLastError()를 사용
WARNINGS	: WSAGetLastError()을 통한 오류 코드 내용 확인
			  URL => https://msdn.microsoft.com/en-us/library/windows/desktop/ms740668(v=vs.85).aspx
***************************************************************************************/
bool CTCPClient::Open(char * pcIP, int nPort)
{
	int nErrorCode = 0;

	if(false == m_bConnectState)
	{
		if(SOCKET_ERROR == connect(m_RecvSock, (SOCKADDR*)&m_RecvAddr, sizeof(m_RecvAddr)))
		{
			nErrorCode = WSAGetLastError();
			WSACleanup();
			closesocket(m_RecvSock);

			return false;
		}
		m_bConnectState = true;
	}

	return true;
}

/***************************************************************************************
NAME		: Close
PARAMS		: [IN ] none
			  [OUT] none
COMMENTS	: 넘겨받소켓을 닫아준다.
WARNINGS	: none
***************************************************************************************/
void CTCPClient::Close()
{
	closesocket(m_RecvSock);
}

/***************************************************************************************
NAME		: Send
PARAMS		: [IN ] char * pcIP
					int nPort
					char * pcContents
					int nLength
					int nFlag
			  [OUT] bool
COMMENTS	: Send 소켓 생성 후 해당 소켓을 통해 send()를 호출하여 지정된 ip와 port번호로
			  데이터를 전송한다. 성공시 true, 실패시 false를 반환한다.
WARNINGS	: none
***************************************************************************************/
bool CTCPClient::Send(char * pcIP, int nPort, char * pcContents, int nLength, int nFlag)
{
	int nErrorCode = 0;

	if(SOCKET_ERROR == send(m_RecvSock, pcContents, nLength, 0))
	{
		nErrorCode = WSAGetLastError();
		WSACleanup();
		closesocket(m_RecvSock);
		return false;
	}

	return true;
}

/***************************************************************************************
NAME		: Receive
PARAMS		: [IN ] char * pcIP
					int nPort
					char * pcContents
					int nLength
			  [OUT] char *
COMMENTS	: 처음 open()에서 생성한 소켓을 사용하여 데이터를 receive한다.
			  해당 receive소켓은 타 클라이언트에서 connect할때까지 accept() 내에서 줄곧
			  기다리며 connect 요청이 들어왔을경우 m_SendSock에 해당 내용을 덧 붙인다.
WARNINGS	: none
***************************************************************************************/
char * CTCPClient::Receive(char * pcIP, int nPort, char * pcContents, int nLength)
{
	sockaddr_in m_SendAddr;
	char m_szBuffer[BUFF_SIZE];
	int nClntAddrSize = sizeof(m_SendAddr);
	int nErrorCode = 0;

	if (m_RecvSock == INVALID_SOCKET || m_RecvSock == SOCKET_ERROR)
	{
		nErrorCode = WSAGetLastError();
		WSACleanup();
		closesocket(m_RecvSock);
	}

	memset(m_szBuffer, 0, BUFF_SIZE);
	memset(pcContents, 0, BUFF_SIZE);

	nErrorCode = recv(m_RecvSock, m_szBuffer, BUFF_SIZE, 0);

	if('\0' == m_szBuffer[0])
	{
		m_bConnectState = false;
	}

	nErrorCode = WSAGetLastError();

	strcpy_s(pcContents, BUFF_SIZE, m_szBuffer);

	return pcContents;
}