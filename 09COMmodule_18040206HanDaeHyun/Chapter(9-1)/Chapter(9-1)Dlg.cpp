// Chapter(9-1)Dlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "Chapter(9-1).h"
#include "Chapter(9-1)Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CChapter91Dlg 대화 상자
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


// CChapter91Dlg 메시지 처리기

BOOL CChapter91Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 이 대화 상자의 아이콘을 설정합니다. 응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	dlgSerial.Create(IDD_SERIAL_MAIN, this);
	dlgUDP.Create(IDD_UDP_MAIN, this);
	dlgTCP.Create(IDD_TCP_MAIN, this);

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다. 문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.
void CChapter91Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CChapter91Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


/**********************************************************************
NAME		: OnBnClickedExit
DECLARATION	: CChapter91Dlg
PARAMS		: [IN ] none
			  [OUT] void
COMMENTS	: 종료함수
			  OnOk()이후 자동으로 Destroy()가 호출된다.
WARNINGS	: none
**********************************************************************/
void CChapter91Dlg::OnBnClickedExit()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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
