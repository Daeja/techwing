#pragma once
#include "afxwin.h"
#include "Serial.h"

#define PORT_NAME (5)
#define BUFF_SIZE (512)

// CDlgModalSerial 대화 상자입니다.

class CDlgModalSerial : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgModalSerial)

public:
	CDlgModalSerial(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CDlgModalSerial();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_SERIAL_MAIN_MODAL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnOpen();
	afx_msg void OnBnClickedBtnClose();
	afx_msg void OnBnClickedBtnSendData();
	afx_msg void OnBnClickedBtnBack();
	virtual BOOL OnInitDialog();
	CComboBox m_comboPort;
	CComboBox m_comboBaudRate;
	CButton m_btnOpen;
	CButton m_btnClose;
	CButton m_btnSendData;
	CButton m_btnBack;
	void RecvMessage(void);
	CCommunication * rsPort;

	int ThreadFunc();
	CListBox m_listReceiveData;
	CEdit m_editData;
	CWinThread * m_pThread;

	bool m_bStopRequest;
};

/**********************************************************************
NAME		: _ThreadFunc
PARAMS		: [IN ] LPVOID pParam
			  [OUT] UINT
COMMENTS	: Thread를 정의하는 함수
WARNINGS	: none
**********************************************************************/
UINT _ThreadFuncModalSerial(LPVOID pParam)
{
	int nReturn = ((CDlgModalSerial *)pParam)->ThreadFunc();

	AfxEndThread(nReturn);

	return nReturn;
}