
// CChapter91Dlg.h : 헤더 파일
//

#pragma once
#include "CSerialCommunicationDoc.h"

#define INITIALIZE (1)

// CChapter91Dlg 대화 상자
class CChapter91Dlg : public CDialogEx, public CSerialCommunicationDoc
{
// 생성입니다.
public:
	CChapter91Dlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
	enum { IDD = IDD_MY09COMMODULE_18040206HANDAEHYUN_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.

	CSerialCommunicationDoc serialComm;

// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
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
