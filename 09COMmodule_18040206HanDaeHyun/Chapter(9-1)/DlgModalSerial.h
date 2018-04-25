#pragma once
#include "afxwin.h"
#include "Serial.h"

#define PORT_NAME (5)
#define BUFF_SIZE (512)

// CDlgModalSerial ��ȭ �����Դϴ�.

class CDlgModalSerial : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgModalSerial)

public:
	CDlgModalSerial(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CDlgModalSerial();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_SERIAL_MAIN_MODAL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

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
COMMENTS	: Thread�� �����ϴ� �Լ�
WARNINGS	: none
**********************************************************************/
UINT _ThreadFuncModalSerial(LPVOID pParam)
{
	int nReturn = ((CDlgModalSerial *)pParam)->ThreadFunc();

	AfxEndThread(nReturn);

	return nReturn;
}