#pragma once
#include "afxwin.h"
#include "UDP.h"

#define BUFF_SIZE (512)

// CDlgUDP ��ȭ �����Դϴ�.

class CDlgUDP : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgUDP)

public:
	CDlgUDP(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CDlgUDP();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_UDP_MAIN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnBnClickedBtnOpen();
	afx_msg void OnBnClickedBtnClose();
	afx_msg void OnBnClickedBtnSendData();
	afx_msg void OnBnClickedBtnBack();
	afx_msg void OnBnClickedRadioServer();
	afx_msg void OnBnClickedRadioClient();
	afx_msg void OnBnClickedRadioBroadcast();
	afx_msg void OnBnClickedRadioUnicast();
	virtual BOOL OnInitDialog();

	CWinThread * m_pThread;
	int ThreadFunc();

private :
	CButton m_radioServer;
	CButton m_radioClient;
	CButton m_radioBroadcast;
	CButton m_radioUnicast;
	CButton m_btnOpen;
	CButton m_btnClose;
	CButton m_btnSendData;
	CButton m_btnBack;
	CEdit m_editPort;
	CEdit m_editIP;
	CEdit m_editSendData;
	CListBox m_listReceiveData;
	CStatic staticIP;

	CCommunication * m_SocketUDP;

	bool m_bStopFlag;
};

/**********************************************************************
NAME		: _ThreadFunc
PARAMS		: [IN ] LPVOID pParam
			  [OUT] UINT
COMMENTS	: Thread�� �����ϴ� �Լ�
WARNINGS	: none
**********************************************************************/
UINT _ThreadReadBufferUDP(LPVOID pParam)
{
	int nReturn = ((CDlgUDP *)pParam)->ThreadFunc();

	AfxEndThread(nReturn);

	return nReturn;
}