// DlgModalUDP.cpp : implementation file
//

#include "stdafx.h"
#include "Chapter(9-1).h"
#include "DlgModalUDP.h"
#include "afxdialogex.h"


// CDlgModalUDP dialog

IMPLEMENT_DYNAMIC(CDlgModalUDP, CDialogEx)

CDlgModalUDP::CDlgModalUDP(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgModalUDP::IDD, pParent)
{

}

CDlgModalUDP::~CDlgModalUDP()
{
	
}

void CDlgModalUDP::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BTN_OPEN, m_btnOpen);
	DDX_Control(pDX, IDC_BTN_CLOSE, m_btnClose);
	DDX_Control(pDX, IDC_BTN_SEND_DATA, m_btnSendData);
	DDX_Control(pDX, IDC_BTN_BACK, m_btnBack);
	DDX_Control(pDX, IDC_EDIT_UDP_PORT, m_editPort);
	DDX_Control(pDX, IDC_EDIT_UDP_IP, m_editIP);
	DDX_Control(pDX, IDC_EDIT_SEND_DATA_UDP, m_editSendData);
	DDX_Control(pDX, IDC_LIST_RECEIVE_UDP, m_listReceiveData);
	DDX_Control(pDX, IDC_RADIO_SERVER, m_radioServer);
	DDX_Control(pDX, IDC_RADIO_CLIENT, m_radioClient);
	DDX_Control(pDX, IDC_RADIO_BROADCAST, m_radioBroadcast);
	DDX_Control(pDX, IDC_RADIO_UNICAST, m_radioUnicast);
}


BEGIN_MESSAGE_MAP(CDlgModalUDP, CDialogEx)
	ON_BN_CLICKED(IDC_BTN_OPEN, &CDlgModalUDP::OnBnClickedBtnOpen)
	ON_BN_CLICKED(IDC_BTN_CLOSE, &CDlgModalUDP::OnBnClickedBtnClose)
	ON_BN_CLICKED(IDC_BTN_SEND_DATA, &CDlgModalUDP::OnBnClickedBtnSendData)
	ON_BN_CLICKED(IDC_BTN_BACK, &CDlgModalUDP::OnBnClickedBtnBack)
	ON_BN_CLICKED(IDC_RADIO_SERVER, &CDlgModalUDP::OnBnClickedRadioServer)
	ON_BN_CLICKED(IDC_RADIO_CLIENT, &CDlgModalUDP::OnBnClickedRadioClient)
	ON_BN_CLICKED(IDC_RADIO_BROADCAST, &CDlgModalUDP::OnBnClickedRadioBroadcast)
	ON_BN_CLICKED(IDC_RADIO_UNICAST, &CDlgModalUDP::OnBnClickedRadioUnicast)
END_MESSAGE_MAP()


// CDlgModalUDP message handlers
BOOL CDlgModalUDP::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	m_editPort.EnableWindow(true);
	m_editIP.EnableWindow(true);
	m_btnOpen.EnableWindow(true);
	m_btnClose.EnableWindow(false);
	m_btnSendData.EnableWindow(false);
	m_btnBack.EnableWindow(true);

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void CDlgModalUDP::OnBnClickedBtnOpen()
{
	if(true == !(m_radioServer.GetCheck() || m_radioClient.GetCheck()))
	{
		AfxMessageBox(_T("Please check Baud Rate Group"));
		return ;
	}
	if(true == !(m_radioBroadcast.GetCheck() || m_radioUnicast.GetCheck()))
	{
		AfxMessageBox(_T("Please check Cast Group"));
		return ;
	}

	m_editPort.EnableWindow(false);
	m_editIP.EnableWindow(false);
	m_btnOpen.EnableWindow(false);
	m_btnClose.EnableWindow(true);
	m_btnSendData.EnableWindow(true);
	m_btnBack.EnableWindow(false);

	int nLength = m_editIP.GetWindowTextLengthA() + 1;
	char * pcIP = new char [ nLength ];
	m_editIP.GetWindowText( pcIP, nLength );

	nLength = m_editPort.GetWindowTextLengthA() + 1;
	char * pcPort = new char [ nLength ];
	m_editPort.GetWindowText( pcPort, nLength );
	int nPort = atoi( pcPort );

	if(m_radioServer.GetCheck())
	{
		m_SocketUDP = new CUDP(pcIP, nPort, SERVER);
	}
	else if(m_radioClient.GetCheck())
	{
		m_SocketUDP = new CUDP(pcIP, nPort, CLIENT);
	}

	bool nIsOpen = m_SocketUDP->IsConnected();

	if(true == nIsOpen)
	{
		m_pThread = AfxBeginThread(_ThreadReadBufferModalUDP, this, THREAD_PRIORITY_NORMAL, 0, CREATE_SUSPENDED);

		assert(m_pThread);

		m_pThread->m_bAutoDelete = false;
		m_pThread->ResumeThread();

		m_bStopFlag = true;
	}

	delete [] pcPort;
	delete [] pcIP;
}


void CDlgModalUDP::OnBnClickedBtnClose()
{
	m_editPort.EnableWindow(true);
	m_editIP.EnableWindow(true);
	m_btnOpen.EnableWindow(true);
	m_btnClose.EnableWindow(false);
	m_btnSendData.EnableWindow(false);
	m_btnBack.EnableWindow(true);

	m_bStopFlag = false;
	m_SocketUDP->Close();

	delete m_SocketUDP;
}


void CDlgModalUDP::OnBnClickedBtnSendData()
{
	char * pcSendData = new char[BUFF_SIZE];

	memset(pcSendData, 0, BUFF_SIZE);

	m_editSendData.GetWindowTextA(pcSendData, BUFF_SIZE);

	CMyString SendData(pcSendData);

	int nLength = m_editIP.GetWindowTextLengthA() + 1;
	char * pcIP = new char [ nLength ];
	m_editIP.GetWindowText( pcIP, nLength );

	nLength = m_editPort.GetWindowTextLengthA() + 1;
	char * pcPort = new char [ nLength ];
	m_editPort.GetWindowText( pcPort, nLength );
	int nPort = atoi( pcPort );

	if(m_radioBroadcast.GetCheck())
	{
		m_SocketUDP->Send(pcIP, nPort, SendData, SendData.getSize(), BROADCAST);
	}
	else
	{
		m_SocketUDP->Send(pcIP, nPort, SendData, SendData.getSize(), NULL);
	}

	delete [] pcSendData;
	delete [] pcIP;
	delete [] pcPort;
}


void CDlgModalUDP::OnBnClickedBtnBack()
{
	this->OnOK();
}


void CDlgModalUDP::OnBnClickedRadioServer()
{
	SetDlgItemText(IDC_STATIC_IP, "Client IP(Unicast)");
}


void CDlgModalUDP::OnBnClickedRadioClient()
{
	SetDlgItemText(IDC_STATIC_IP, "Server IP");
}


void CDlgModalUDP::OnBnClickedRadioBroadcast()
{
	m_editIP.SetWindowTextA("255.255.255.255");
	m_editIP.EnableWindow(false);
}


void CDlgModalUDP::OnBnClickedRadioUnicast()
{
	m_editIP.SetWindowTextA("");
	m_editIP.EnableWindow(true);
}


int CDlgModalUDP::ThreadFunc()
{
	while (m_bStopFlag)
	{
		char szInput[BUFF_SIZE];

		strcpy_s(szInput, BUFF_SIZE, m_SocketUDP->Receive(NULL, NULL, szInput, strlen(szInput)));
		
		if(NULL != szInput[0])
		{
			m_listReceiveData.AddString(szInput);
		}
	}

	return 0;
}