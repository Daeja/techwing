#pragma once
#include "Ethernet.h"

class CHAPTER09DLL_API CTCPClient : public CEthernet
{
public:
	CTCPClient(char * pcIP, int nPort, int nFlag);
	~CTCPClient(void);
	virtual bool Open(char * pcIP, int nPort);
	virtual void Close();
	virtual bool Send(char * pcIP, int nPort, char * pcContents, int nLength, int nFlag);
	virtual char * Receive(char * pcIP, int nPort, char * pcContents, int nLength);
};