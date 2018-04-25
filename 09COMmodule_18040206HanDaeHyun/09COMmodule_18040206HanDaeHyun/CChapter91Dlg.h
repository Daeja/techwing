
// CChapter91Dlg.h : ��� ����
//

#pragma once
#include "CSerialCommunicationDoc.h"

#define INITIALIZE (1)

// CChapter91Dlg ��ȭ ����
class CChapter91Dlg : public CDialogEx, public CSerialCommunicationDoc
{
// �����Դϴ�.
public:
	CChapter91Dlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_MY09COMMODULE_18040206HANDAEHYUN_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.

	CSerialCommunicationDoc serialComm;

// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnOpen();
	afx_msg void OnBnClickedBtnClose();
	afx_msg void OnBnClickedBtnSendData();
	afx_msg void OnBnClickedBtnExit();
	int ThreadFunc(void);

private :
	bool m_bStopRequest;
	char * pcContents;
};
