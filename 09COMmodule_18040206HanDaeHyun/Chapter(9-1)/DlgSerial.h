#pragma once
#include "afxwin.h"
#include "Serial.h"

#define PORT_NAME (5)
#define BUFF_SIZE (512)

// CDlgSerial 대화 상자입니다.

class CDlgSerial : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgSerial)

public:
	CDlgSerial(CWnd* pParent = NULL);
	virtual ~CDlgSerial();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_SERIAL_MAIN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);

	DECLARE_MESSAGE_MAP()
public:
	CComboBox m_comboPort;
	CComboBox m_comboBaudRate;
	CEdit m_editData;
	CButton m_btnOpen;
	CButton m_btnClose;
	CButton m_btnSendData;
	CButton m_btnBack;
	CCommunication * rsPort;
	CListBox m_listReceiveData;

	afx_msg void OnBnClickedBtnBack();
	afx_msg void OnBnClickedBtnOpen();
	afx_msg void OnBnClickedBtnClose();
	afx_msg void OnBnClickedBtnSendData();
	virtual BOOL OnInitDialog();

	int ThreadFunc();
	void RecvMessage();

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
UINT _ThreadFuncSerial(LPVOID pParam)
{
	int nReturn = ((CDlgSerial *)pParam)->ThreadFunc();

	AfxEndThread(nReturn);

	return nReturn;
}