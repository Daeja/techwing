#pragma once
#include "Ethernet.h"

class CHAPTER09DLL_API CUDP : public CEthernet
{
public:
	CUDP(char * pcIP, int nPort, int nFlag);
	~CUDP(void);
	virtual bool Open(char * pcIP, int nPort);
	virtual void Close();
	virtual bool Send(char * pcIP, int nPort, char * pcContents, int nLength, int nFlag);
	virtual char * Receive(char * pcIP, int nPort, char * pcContents, int nLength);
};