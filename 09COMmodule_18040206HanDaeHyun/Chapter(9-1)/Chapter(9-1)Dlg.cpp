// Chapter(9-1)Dlg.cpp : ���� ����
//

#include "stdafx.h"
#include "Chapter(9-1).h"
#include "Chapter(9-1)Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CChapter91Dlg ��ȭ ����
CChapter91Dlg::CChapter91Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CChapter91Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CChapter91Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CChapter91Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_EXIT, &CChapter91Dlg::OnBnClickedExit)
	ON_BN_CLICKED(IDC_RADIO_DLG_SERIAL, &CChapter91Dlg::OnBnClickedRadioDlgSerial)
	ON_BN_CLICKED(IDC_RADIO_DLG_UDP, &CChapter91Dlg::OnBnClickedRadioDlgUdp)
	ON_BN_CLICKED(IDC_RADIO_DLG_TCP, &CChapter91Dlg::OnBnClickedRadioDlgTcp)
	ON_BN_CLICKED(IDC_BTN_SERIAL, &CChapter91Dlg::OnBnClickedBtnSerial)
	ON_BN_CLICKED(IDC_BUTTON_MODEL_UDP, &CChapter91Dlg::OnBnClickedButtonModelUdp)
	ON_BN_CLICKED(IDC_BUTTON_MODAL_TCP, &CChapter91Dlg::OnBnClickedButtonModalTcp)
END_MESSAGE_MAP()


// CChapter91Dlg �޽��� ó����

BOOL CChapter91Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �� ��ȭ ������ �������� �����մϴ�. ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	dlgSerial.Create(IDD_SERIAL_MAIN, this);
	dlgUDP.Create(IDD_UDP_MAIN, this);
	dlgTCP.Create(IDD_TCP_MAIN, this);

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�. ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.
void CChapter91Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CChapter91Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


/**********************************************************************
NAME		: OnBnClickedExit
DECLARATION	: CChapter91Dlg
PARAMS		: [IN ] none
			  [OUT] void
COMMENTS	: �����Լ�
			  OnOk()���� �ڵ����� Destroy()�� ȣ��ȴ�.
WARNINGS	: none
**********************************************************************/
void CChapter91Dlg::OnBnClickedExit()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	OnOK();
}

void CChapter91Dlg::OnBnClickedRadioDlgSerial()
{
	dlgSerial.ShowWindow(true);
	dlgUDP.ShowWindow(false);
	dlgTCP.ShowWindow(false);

	dlgSerial.GetWindowRect(m_rectCurHist);
	dlgSerial.SetWindowPos(NULL, 0, 30, m_rectCurHist.Width(), m_rectCurHist.Height(), SWP_NOSIZE);
}


void CChapter91Dlg::OnBnClickedRadioDlgUdp()
{
	dlgUDP.ShowWindow(true);
	dlgTCP.ShowWindow(false);
	dlgSerial.ShowWindow(false);

	dlgUDP.GetWindowRect(m_rectCurHist);
	dlgUDP.SetWindowPos(NULL, 0, 30, m_rectCurHist.Width(), m_rectCurHist.Height(), SWP_NOSIZE);
}


void CChapter91Dlg::OnBnClickedRadioDlgTcp()
{
	dlgTCP.ShowWindow(true);
	dlgUDP.ShowWindow(false);
	dlgSerial.ShowWindow(false);

	dlgTCP.GetWindowRect(m_rectCurHist);
	dlgTCP.SetWindowPos(NULL, 0, 30, m_rectCurHist.Width(), m_rectCurHist.Height(), SWP_NOSIZE);
}


void CChapter91Dlg::OnBnClickedBtnSerial()
{
	CDlgModalSerial modalSerial;
	modalSerial.DoModal();
}

void CChapter91Dlg::OnBnClickedButtonModelUdp()
{
	CDlgModalUDP modalUDP;
	modalUDP.DoModal();
}


void CChapter91Dlg::OnBnClickedButtonModalTcp()
{
	CDlgModalTCP modalTCP;
	modalTCP.DoModal();
}
