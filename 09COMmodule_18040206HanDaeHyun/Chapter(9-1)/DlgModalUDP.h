#pragma once
#include "afxwin.h"
#include "UDP.h"

#define BUFF_SIZE (512)

// CDlgModalUDP dialog

class CDlgModalUDP : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgModalUDP)

public:
	CDlgModalUDP(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgModalUDP();

// Dialog Data
	enum { IDD = IDD_UDP_MAIN_MODAL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

private:
	CButton m_btnOpen;
	CButton m_btnClose;
	CButton m_btnSendData;
	CButton m_btnBack;
	CButton m_radioServer;
	CButton m_radioClient;
	CButton m_radioBroadcast;
	CButton m_radioUnicast;
	CEdit m_editPort;
	CEdit m_editIP;
	CEdit m_editSendData;
	CListBox m_listReceiveData;
	CCommunication * m_SocketUDP;
	bool m_bStopFlag;

public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedBtnOpen();
	afx_msg void OnBnClickedBtnClose();
	afx_msg void OnBnClickedBtnSendData();
	afx_msg void OnBnClickedBtnBack();
	afx_msg void OnBnClickedRadioServer();
	afx_msg void OnBnClickedRadioClient();
	afx_msg void OnBnClickedRadioBroadcast();
	afx_msg void OnBnClickedRadioUnicast();

	CWinThread * m_pThread;
	int ThreadFunc();
};

/**********************************************************************
NAME		: _ThreadFunc
PARAMS		: [IN ] LPVOID pParam
			  [OUT] UINT
COMMENTS	: Thread를 정의하는 함수
WARNINGS	: none
**********************************************************************/
UINT _ThreadReadBufferModalUDP(LPVOID pParam)
{
	int nReturn = ((CDlgModalUDP *)pParam)->ThreadFunc();

	AfxEndThread(nReturn);

	return nReturn;
}