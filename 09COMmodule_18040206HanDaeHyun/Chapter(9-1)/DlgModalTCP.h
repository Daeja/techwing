#pragma once
#include "afxwin.h"
#include "TCPServer.h"
#include "TCPClient.h"

// CDlgModalTCP dialog

class CDlgModalTCP : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgModalTCP)

public:
	CDlgModalTCP(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgModalTCP();

// Dialog Data
	enum { IDD = IDD_TCP_MAIN_MODAL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedBtnOpen();
	afx_msg void OnBnClickedBtnClose();
	afx_msg void OnBnClickedBtnSendData();
	afx_msg void OnBnClickedBtnBack();
	afx_msg void OnBnClickedRadioServer();
	afx_msg void OnBnClickedRadioClient();
	CButton m_radioServer;
	CButton m_radioClient;
	CButton m_btnOpen;
	CButton m_btnClose;
	CButton m_btnSendData;
	CButton m_btnBack;
	CEdit m_editPort;
	CEdit m_editIP;
	CEdit m_editSendData;
	CListBox m_listReceiveData;

	CWinThread * m_pThread;
	int ThreadFunc();

private :
	CCommunication * m_SocketTCP;
	bool m_bStopRequest;
};

UINT _ThreadReadBufferModalTCP(LPVOID pParam)
{
	int nReturn = ((CDlgModalTCP *)pParam)->ThreadFunc();

	AfxEndThread(nReturn);

	return nReturn;
}