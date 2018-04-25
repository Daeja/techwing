// ���� ifdef ����� DLL���� ���������ϴ� �۾��� ���� �� �ִ� ��ũ�θ� ����� 
// ǥ�� ����Դϴ�. �� DLL�� ��� �ִ� ������ ��� ����ٿ� ���ǵ� _EXPORTS ��ȣ��
// �����ϵǸ�, �ٸ� ������Ʈ������ �� ��ȣ�� ������ �� �����ϴ�.
// �̷��� �ϸ� �ҽ� ���Ͽ� �� ������ ��� �ִ� �ٸ� ��� ������Ʈ������ 
// CHAPTER09DLL_API �Լ��� DLL���� �������� ������ ����, �� DLL��
// �� DLL�� �ش� ��ũ�η� ���ǵ� ��ȣ�� ���������� ������ ���ϴ�.
#ifdef CHAPTER09DLL_EXPORTS
#define CHAPTER09DLL_API __declspec(dllexport)
#else
#define CHAPTER09DLL_API __declspec(dllimport)
#endif

#pragma once
#include "stdafx.h"

class CHAPTER09DLL_API CCommunication
{
public:
	virtual ~CCommunication();
	virtual bool Open(char * pcIP, int nPort) = 0;
	virtual void Close() = 0;
	virtual bool Send(char * pcIP, int nPort, char * pcContents, int nLength, int nFlag) = 0;
	virtual char * Receive(char * pcIP, int nPort, char * pcContents, int nLength) = 0;
	virtual int CountRx() = 0;
	virtual bool IsConnected() = 0;
};