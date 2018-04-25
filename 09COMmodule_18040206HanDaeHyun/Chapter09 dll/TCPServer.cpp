#include "StdAfx.h"
#include "TCPServer.h"

/***************************************************************************************
NAME		: CTCPClient
PARAMS		: [IN ] none
			  [OUT] none
COMMENTS	: �������Լ�, WSA Library�� �ʱ�ȭ��Ű�� �뵵�� ���ȴ�.
WARNINGS	: �ش� �Լ� �� WSAStartup()�� ������� ���� ��� bind()�� ���� �� �� ����
***************************************************************************************/
CTCPServer::CTCPServer(char * pcIP, int nPort, int nFlag) : CEthernet( pcIP, nPort, nFlag)
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

	if (SOCKET_ERROR == bind( m_RecvSock, (struct sockaddr *)&m_RecvAddr, sizeof(m_RecvAddr) ))
	{
		nErrorCode = WSAGetLastError();
		closesocket(m_RecvSock);
		AfxMessageBox(_T("Receive ���� ���� ����"));
	}
}

/***************************************************************************************
NAME		: ~CTCPClient
PARAMS		: [IN ] none
			  [OUT] none
COMMENTS	: �Ҹ����Լ�, ������ �ݾ��ش�.
WARNINGS	: none
***************************************************************************************/
CTCPServer::~CTCPServer(void)
{
}

/***************************************************************************************
NAME		: Open
PARAMS		: [IN ] char * pcIP
					int nPort
			  [OUT] bool
COMMENTS	: �Ѱܹ��� pcIP�� nPort�� �̿��Ͽ� sockaddr_in ����ü ������ �� �� ������ �Ҵ�޴´�.
			  ���� �Ҵ� �� bind�� listen ���н� ������ �� �� �ְ� WSAGetLastError()�� ���
WARNINGS	: WSAGetLastError()�� ���� ���� �ڵ� ���� Ȯ��
			  URL => https://msdn.microsoft.com/en-us/library/windows/desktop/ms740668(v=vs.85).aspx
***************************************************************************************/
bool CTCPServer::Open(char * pcIP, int nPort)
{
	int nErrorCode = 0;
	if (SOCKET_ERROR == listen(m_RecvSock, CLIENT_NUMBER))
	{
		nErrorCode = WSAGetLastError();
		WSACleanup();
		closesocket(m_RecvSock);
		return false;
	}

	return true;
}

/***************************************************************************************
NAME		: Close
PARAMS		: [IN ] none
			  [OUT] none
COMMENTS	: �Ѱܹ޼����� �ݾ��ش�.
WARNINGS	: none
***************************************************************************************/
void CTCPServer::Close()
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
COMMENTS	: Send ���� ���� �� �ش� ������ ���� send()�� ȣ���Ͽ� ������ ip�� port��ȣ��
			  �����͸� �����Ѵ�. ������ true, ���н� false�� ��ȯ�Ѵ�.
WARNINGS	: none
***************************************************************************************/
bool CTCPServer::Send(char * pcIP, int nPort, char * pcContents, int nLength, int nFlag)
{
	int nSockSize = sizeof( m_SendAddr );
	int nErrorCode = 0;

	if(SOCKET_ERROR == send(m_SendSock, pcContents, nLength, 0))
	{
		nErrorCode = WSAGetLastError();
		WSACleanup();
		closesocket(m_SendSock);
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
COMMENTS	: ó�� open()���� ������ ������ ����Ͽ� �����͸� receive�Ѵ�.
			  �ش� receive������ Ÿ Ŭ���̾�Ʈ���� connect�Ҷ����� accept() ������ �ٰ�
			  ��ٸ��� connect ��û�� ��������� m_SendSock�� �ش� ������ �� ���δ�.
WARNINGS	: none
***************************************************************************************/
char * CTCPServer::Receive(char * pcIP, int nPort, char * pcContents, int nLength)
{
	char m_szBuffer[BUFF_SIZE];
	int nClntAddrSize = sizeof(m_SendAddr);
	int nErrorCode = 0;

	if(false == m_bConnectState)
	{
		m_SendSock = accept(m_RecvSock, (struct sockaddr *)&m_SendAddr, &nClntAddrSize);

		//getpeername()

		m_bConnectState = true;
	}

	if (m_SendSock == INVALID_SOCKET || m_SendSock == SOCKET_ERROR)
	{
		nErrorCode = WSAGetLastError();
		WSACleanup();
		closesocket(m_SendSock);
	}

	memset(m_szBuffer, 0, BUFF_SIZE);
	memset(pcContents, 0, BUFF_SIZE);

	nErrorCode = recv(m_SendSock, m_szBuffer, BUFF_SIZE, 0);

	if('\0' == m_szBuffer[0])
	{
		m_bConnectState = false;
	}

	nErrorCode = send(m_SendSock, "�ݻ�", BUFF_SIZE, 0);
	nErrorCode = WSAGetLastError();

	strcpy_s(pcContents, BUFF_SIZE, m_szBuffer);

	return pcContents;
}