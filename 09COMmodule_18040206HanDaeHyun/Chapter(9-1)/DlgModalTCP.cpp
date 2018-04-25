// DlgModalTCP.cpp : implementation file
//

#include "stdafx.h"
#include "Chapter(9-1).h"
#include "DlgModalTCP.h"
#include "afxdialogex.h"


// CDlgModalTCP dialog

IMPLEMENT_DYNAMIC(CDlgModalTCP, CDialogEx)

CDlgModalTCP::CDlgModalTCP(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgModalTCP::IDD, pParent)
{

}

CDlgModalTCP::~CDlgModalTCP()
{
	
}

void CDlgModalTCP::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_RADIO_SERVER, m_radioServer);
	DDX_Control(pDX, IDC_EDIT_UDP_PORT, m_editPort);
	DDX_Control(pDX, IDC_EDIT_UDP_IP, m_editIP);
	DDX_Control(pDX, IDC_EDIT_SEND_DATA_UDP, m_editSendData);
	DDX_Control(pDX, IDC_LIST_RECEIVE_UDP, m_listReceiveData);
	DDX_Control(pDX, IDC_BTN_OPEN, m_btnOpen);
	DDX_Control(pDX, IDC_BTN_CLOSE, m_btnClose);
	DDX_Control(pDX, IDC_BTN_SEND_DATA, m_btnSendData);
	DDX_Control(pDX, IDC_BTN_BACK, m_btnBack);
}


BEGIN_MESSAGE_MAP(CDlgModalTCP, CDialogEx)
	ON_BN_CLICKED(IDC_BTN_OPEN, &CDlgModalTCP::OnBnClickedBtnOpen)
	ON_BN_CLICKED(IDC_BTN_CLOSE, &CDlgModalTCP::OnBnClickedBtnClose)
	ON_BN_CLICKED(IDC_BTN_SEND_DATA, &CDlgModalTCP::OnBnClickedBtnSendData)
	ON_BN_CLICKED(IDC_BTN_BACK, &CDlgModalTCP::OnBnClickedBtnBack)
	ON_BN_CLICKED(IDC_RADIO_SERVER, &CDlgModalTCP::OnBnClickedRadioServer)
	ON_BN_CLICKED(IDC_RADIO_CLIENT, &CDlgModalTCP::OnBnClickedRadioClient)
END_MESSAGE_MAP()


// CDlgModalTCP message handlers


BOOL CDlgModalTCP::OnInitDialog()
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


void CDlgModalTCP::OnBnClickedBtnOpen()
{
	if(true == !(m_radioServer.GetCheck() || m_radioClient.GetCheck()))
	{
		AfxMessageBox(_T("Please check Baud Rate Group"));
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
		m_SocketTCP = new CTCPServer(pcIP, nPort, SERVER);
	}
	else if(m_radioClient.GetCheck())
	{
		m_SocketTCP = new CTCPClient(pcIP, nPort, CLIENT);
	}

	int nIsOpen = m_SocketTCP->Open(pcIP, nPort);

	if(true == nIsOpen)
	{
		m_pThread = AfxBeginThread(_ThreadReadBufferModalTCP, this, THREAD_PRIORITY_NORMAL, 0, CREATE_SUSPENDED);

		assert(m_pThread);

		m_pThread->m_bAutoDelete = false;
		m_pThread->ResumeThread();

		m_bStopRequest = true;
	}
	delete [] pcPort;
	delete [] pcIP;
}


void CDlgModalTCP::OnBnClickedBtnClose()
{
	m_editPort.EnableWindow(true);
	m_editIP.EnableWindow(true);
	m_btnOpen.EnableWindow(true);
	m_btnClose.EnableWindow(false);
	m_btnSendData.EnableWindow(false);
	m_btnBack.EnableWindow(true);

	m_bStopRequest = false;
	m_SocketTCP->Close();

	delete m_SocketTCP;
}


void CDlgModalTCP::OnBnClickedBtnSendData()
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

	if(m_radioServer.GetCheck())
	{
		if(m_SocketTCP->Send(pcIP, nPort, SendData, SendData.getSize(), SERVER))
		{
			m_bStopRequest = true;
		}
		else
		{
			m_bStopRequest = false;
		}
	}
	else if(m_radioClient.GetCheck())
	{
		if(m_SocketTCP->Send(pcIP, nPort, SendData, SendData.getSize(), CLIENT))
		{
			m_bStopRequest = true;
		}
		else
		{
			m_bStopRequest = false;
		}
	}

	delete [] pcSendData;
	delete [] pcIP;
	delete [] pcPort;
}


int CDlgModalTCP::ThreadFunc()
{
	while (m_bStopRequest)
	{
		char szInput[BUFF_SIZE];

		strcpy_s(szInput, BUFF_SIZE, m_SocketTCP->Receive(NULL, NULL, szInput, strlen(szInput)));
		
		if(NULL != szInput[0])
		{
			m_listReceiveData.AddString(szInput);
		}
	}

	return 0;
}


void CDlgModalTCP::OnBnClickedBtnBack()
{
	this->OnOK();
}


void CDlgModalTCP::OnBnClickedRadioServer()
{
	SetDlgItemText(IDC_STATIC_IP, "Client IP(Unicast)");
}


void CDlgModalTCP::OnBnClickedRadioClient()
{
	SetDlgItemText(IDC_STATIC_IP, "Server IP");
}
