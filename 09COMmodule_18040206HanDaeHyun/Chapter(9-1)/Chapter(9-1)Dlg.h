
// Chapter(9-1)Dlg.h : ��� ����
//

#include "DlgSerial.h"
#include "DlgUDP.h"
#include "DlgTCP.h"

#include "DlgModalSerial.h"
#include "DlgModalUDP.h"
#include "DlgModalTCP.h"

#pragma once

// CChapter91Dlg ��ȭ ����
class CChapter91Dlg : public CDialogEx
{
// �����Դϴ�.
public:
	CChapter91Dlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_CHAPTER91_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
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
