#pragma once
#include "afxwin.h"
#include "TCPClient.h"
#include "TCPServer.h"

// CDlgTCP ��ȭ �����Դϴ�.

class CDlgTCP : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgTCP)

public:
	CDlgTCP(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CDlgTCP();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_TCP_MAIN };

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
	virtual BOOL OnInitDialog();
	CEdit m_editPort;
	CEdit m_editIP;
	CEdit m_editSendData;
	CListBox m_listRecvData;
	CButton m_radioServer;
	CButton m_radioClient;
	CButton m_btnOpen;
	CButton m_btnClose;
	CButton m_btnSendData;
	CButton m_btnBack;

	CWinThread * m_pThread;
	int ThreadFunc();

private :
	CCommunication * m_SocketTCP;
	bool m_bStopRequest;
};

UINT _ThreadReadBufferTCP(LPVOID pParam)
{
	int nReturn = ((CDlgTCP *)pParam)->ThreadFunc();

	AfxEndThread(nReturn);

	return nReturn;
}