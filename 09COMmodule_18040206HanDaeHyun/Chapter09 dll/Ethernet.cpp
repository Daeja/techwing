#include "StdAfx.h"
#include "Ethernet.h"

/***************************************************************************************
NAME		: CEthernet
PARAMS		: [IN ] none
			  [OUT] none
COMMENTS	: 디폴트 생성자
WARNINGS	: none
***************************************************************************************/
CEthernet::CEthernet()
{
}

/***************************************************************************************
NAME		: CEthernet
PARAMS		: [IN ] char * _pcIP
					int _nPort
			  [OUT] none
COMMENTS	: Override한 멤버 이니셜라이즈 문법 사용 생성자
WARNINGS	: none
***************************************************************************************/
CEthernet::CEthernet(char * _pcIP, int _nPort, int nFlag) : pcIP(_pcIP), nPort(_nPort)
{
	if(SERVER == nFlag)
	{
		m_RecvAddr.sin_addr.s_addr = INADDR_ANY;
		m_RecvAddr.sin_port = htons(nPort);
	}
	else
	{
		m_RecvAddr.sin_addr.s_addr = inet_addr(pcIP);
		m_RecvAddr.sin_port = htons(nPort);
	}
}

/***************************************************************************************
NAME		: ~CEthernet
PARAMS		: [IN ] none
			  [OUT] none
COMMENTS	: 디폴트 소멸자
WARNINGS	: none
***************************************************************************************/
CEthernet::~CEthernet()
{
}

/***************************************************************************************
NAME		: IsConnected
PARAMS		: [IN ] none
			  [OUT] bool
COMMENTS	: 소켓이 연결상태인지를 확인 할 때 m_ConnectState 변수를 사용하여 확인한다.
			  연결 상태라면 true, 아니라면 false를 반환한다.
WARNINGS	: none
***************************************************************************************/
bool CEthernet::IsConnected()
{
	if(true == m_bConnectState)
	{
		return true;
	}

	return false;
}

/***************************************************************************************
NAME		: CountRx
PARAMS		: [IN ] none
			  [OUT] int
COMMENTS	: recv함수를 통해 버퍼 내에 존재하는 데이터들이 읽혀지기 전 상태의 length 값을
			  알 수 있는 함수
WARNINGS	: none
***************************************************************************************/
int CEthernet::CountRx()
{
	if( m_RecvSock == INVALID_SOCKET )
	{
		return -1;
	}

	unsigned long lsize = 0;

	if( SOCKET_ERROR == ioctlsocket(m_RecvSock, FIONREAD, &lsize) )
	{
		closesocket(m_RecvSock);
		return -1;
	}

	return lsize;
}