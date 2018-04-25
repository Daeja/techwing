#pragma once
#include "afxwin.h"
#include "TCPClient.h"
#include "TCPServer.h"

// CDlgTCP 대화 상자입니다.

class CDlgTCP : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgTCP)

public:
	CDlgTCP(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CDlgTCP();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_TCP_MAIN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

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