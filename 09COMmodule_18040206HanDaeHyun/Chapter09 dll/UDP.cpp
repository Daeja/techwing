#include "StdAfx.h"
#include "UDP.h"

/***************************************************************************************
NAME		: CUDP
PARAMS		: [IN ] none
			  [OUT] none
COMMENTS	: �������Լ�, WSA Library�� �ʱ�ȭ��Ű�� �뵵�� ���ȴ�.
WARNINGS	: �ش� �Լ� �� WSAStartup()�� ������� ���� ��� bind()�� ���� �� �� ����
***************************************************************************************/
CUDP::CUDP(char * pcIP, int nPort, int nFlag) : CEthernet( pcIP, nPort, nFlag)
{
	WSADATA m_wsaData;

	if (WSAStartup(MAKEWORD(2, 2), &m_wsaData) != 0)
	{
		fprintf(stderr, "WSAStartup() failed");
		return ;
	}

	int nErrorCode = 0;

	u_long ulMode = 0;

	ioctlsocket(m_RecvSock, FIONBIO, &ulMode);

	m_RecvAddr.sin_family = AF_INET;

	if (0 > (m_RecvSock = socket( PF_INET, SOCK_DGRAM, IPPROTO_UDP )))
	{
		nErrorCode = WSAGetLastError();
	}
}

/***************************************************************************************
NAME		: ~CUDP
PARAMS		: [IN ] none
			  [OUT] none
COMMENTS	: �Ҹ����Լ�, ������ �ݾ��ش�.
WARNINGS	: none
***************************************************************************************/
CUDP::~CUDP(void)
{
	closesocket( m_RecvSock );
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
bool CUDP::Open(char * pcIP, int nPort)
{
	int nErrorCode = 0;

	if (SOCKET_ERROR == bind( m_RecvSock, (struct sockaddr *)&m_RecvAddr, sizeof(m_RecvAddr) ))
	{
		closesocket(m_RecvSock);
		AfxMessageBox(_T("Receive ���� ���� ����"));
		nErrorCode = WSAGetLastError();

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
void CUDP::Close()
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
			  Flag�� BROADCAST�� ��� ��ε�ĳ��Ʈ ���� �������� �ɼ��� ���� �� �����͸� ������.
WARNINGS	: none
***************************************************************************************/
bool CUDP::Send(char * pcIP, int nPort, char * pcContents, int nLength, int nFlag)
{
	SOCKET m_SendSock;
	sockaddr_in m_SendAddr;
	int nSockSize = sizeof( m_SendAddr );
	int nErrorCode = 0;

	if ((m_SendSock = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0)
	{
		nErrorCode = WSAGetLastError();
		AfxMessageBox(_T("Send ���� ���� ����"));
		WSACleanup();
		return false;
	}

	if(BROADCAST == nFlag)
	{
		int nBroadcast = 1;
		int nError = setsockopt(m_SendSock, SOL_SOCKET, SO_BROADCAST, (const char *)&nBroadcast, sizeof(nBroadcast));

		memset(&m_SendAddr, 0, sizeof( m_SendAddr ));
		m_SendAddr.sin_family = AF_INET;
		m_SendAddr.sin_addr.s_addr = INADDR_BROADCAST;
		m_SendAddr.sin_port = htons( nPort );
	}
	else
	{
		memset(&m_SendAddr, 0, sizeof( m_SendAddr ));
		m_SendAddr.sin_family = AF_INET;
		m_SendAddr.sin_addr.s_addr = inet_addr( pcIP );
		m_SendAddr.sin_port = htons( nPort );
	}

	int nReturn = sendto(m_SendSock, pcContents, nLength, 0, (struct sockaddr *) &m_SendAddr, nSockSize);

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
char * CUDP::Receive(char * pcIP, int nPort, char * pcContents, int nLength)
{
	char m_szBuffer[BUFF_SIZE];
	memset(m_szBuffer, 0, BUFF_SIZE);
	
	int nExistBuffer = CountRx();
	int nErrorCode = 0;

	if(0 < nExistBuffer)
	{
		int nSize = sizeof(m_RecvAddr);
		nErrorCode = recvfrom(m_RecvSock, m_szBuffer, BUFF_SIZE, 0, (struct sockaddr *) &m_RecvAddr, &nSize);
		m_szBuffer[BUFF_SIZE - 1] = 0;

		if( SOCKET_ERROR == nErrorCode )
		{
			nErrorCode = WSAGetLastError();
			return "\0";
		}
	}

	strcpy_s(pcContents, BUFF_SIZE, m_szBuffer);

	return pcContents;
}