
// Chapter(9-1).h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CChapter91App:
// �� Ŭ������ ������ ���ؼ��� Chapter(9-1).cpp�� �����Ͻʽÿ�.
//

class CChapter91App : public CWinApp
{
public:
	CChapter91App();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CChapter91App theApp;