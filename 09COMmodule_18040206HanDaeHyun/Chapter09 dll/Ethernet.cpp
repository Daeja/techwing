#include "StdAfx.h"
#include "Ethernet.h"

/***************************************************************************************
NAME		: CEthernet
PARAMS		: [IN ] none
			  [OUT] none
COMMENTS	: ����Ʈ ������
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
COMMENTS	: Override�� ��� �̴ϼȶ����� ���� ��� ������
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
COMMENTS	: ����Ʈ �Ҹ���
WARNINGS	: none
***************************************************************************************/
CEthernet::~CEthernet()
{
}

/***************************************************************************************
NAME		: IsConnected
PARAMS		: [IN ] none
			  [OUT] bool
COMMENTS	: ������ ������������� Ȯ�� �� �� m_ConnectState ������ ����Ͽ� Ȯ���Ѵ�.
			  ���� ���¶�� true, �ƴ϶�� false�� ��ȯ�Ѵ�.
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
COMMENTS	: recv�Լ��� ���� ���� ���� �����ϴ� �����͵��� �������� �� ������ length ����
			  �� �� �ִ� �Լ�
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