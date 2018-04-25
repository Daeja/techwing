
// Chapter(9-1)Dlg.h : 헤더 파일
//

#include "DlgSerial.h"
#include "DlgUDP.h"
#include "DlgTCP.h"

#include "DlgModalSerial.h"
#include "DlgModalUDP.h"
#include "DlgModalTCP.h"

#pragma once

// CChapter91Dlg 대화 상자
class CChapter91Dlg : public CDialogEx
{
// 생성입니다.
public:
	CChapter91Dlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
	enum { IDD = IDD_CHAPTER91_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedExit();
	afx_msg void OnBnClickedRadioDlgSerial();
	afx_msg void OnBnClickedRadioDlgUdp();
	afx_msg void OnBnClickedRadioDlgTcp();

private :
	CDlgSerial dlgSerial;
	CDlgUDP dlgUDP;
	CDlgTCP dlgTCP;
	CRect m_rectCurHist;
public:
	afx_msg void OnBnClickedBtnSerial();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButtonModelUdp();
	afx_msg void OnBnClickedButtonModalTcp();
};
