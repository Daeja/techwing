#pragma once
#include <WinSock2.h>
#include "Chapter09 dll.h"
#include "CMyString.h"

#define BUFF_SIZE		(512)
#define SERVER			(1)
#define CLIENT			(2)
#define BROADCAST		(1)
#define UNICAST			(2)
#define CLIENT_NUMBER	(3)

class CHAPTER09DLL_API CEthernet : public CCommunication
{
public:
	CEthernet();
	CEthernet(char * _pcIP, int _nPort, int nFlag);
	virtual ~CEthernet();
	virtual bool IsConnected();
	virtual int CountRx();
	bool m_bConnectState;

protected :
	SOCKET m_RecvSock;
	sockaddr_in m_RecvAddr;
	char * pcIP;
	int nPort;
};

