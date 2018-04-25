#pragma once
#include "Ethernet.h"

class CHAPTER09DLL_API CTCPServer : public CEthernet
{
public:
	CTCPServer(char * pcIP, int nPort, int nFlag);
	~CTCPServer(void);
	virtual bool Open(char * pcIP, int nPort);
	virtual void Close();
	virtual bool Send(char * pcIP, int nPort, char * pcContents, int nLength, int nFlag);
	virtual char * Receive(char * pcIP, int nPort, char * pcContents, int nLength);

private :
	SOCKET m_SendSock;
	sockaddr_in m_SendAddr;
};

