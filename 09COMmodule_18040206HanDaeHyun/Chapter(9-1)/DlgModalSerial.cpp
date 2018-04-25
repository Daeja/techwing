// DlgModalSerial.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Chapter(9-1).h"
#include "DlgModalSerial.h"
#include "afxdialogex.h"


// CDlgModalSerial ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CDlgModalSerial, CDialogEx)

CDlgModalSerial::CDlgModalSerial(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgModalSerial::IDD, pParent)
{

}

CDlgModalSerial::~CDlgModalSerial()
{
}

void CDlgModalSerial::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_PORT, m_comboPort);
	DDX_Control(pDX, IDC_COMBO_BAUD_RATE, m_comboBaudRate);
	DDX_Control(pDX, IDC_BTN_OPEN, m_btnOpen);
	DDX_Control(pDX, IDC_BTN_CLOSE, m_btnClose);
	DDX_Control(pDX, IDC_BTN_SEND_DATA, m_btnSendData);
	DDX_Control(pDX, IDC_BTN_BACK, m_btnBack);
	DDX_Control(pDX, IDC_LIST_RECEIVE, m_listReceiveData);
	DDX_Control(pDX, IDC_EDIT_SEND_DATA, m_editData);
}


BEGIN_MESSAGE_MAP(CDlgModalSerial, CDialogEx)
	ON_BN_CLICKED(IDC_BTN_OPEN, &CDlgModalSerial::OnBnClickedBtnOpen)
	ON_BN_CLICKED(IDC_BTN_CLOSE, &CDlgModalSerial::OnBnClickedBtnClose)
	ON_BN_CLICKED(IDC_BTN_SEND_DATA, &CDlgModalSerial::OnBnClickedBtnSendData)
	ON_BN_CLICKED(IDC_BTN_BACK, &CDlgModalSerial::OnBnClickedBtnBack)
END_MESSAGE_MAP()


/**********************************************************************
NAME		: OnInitDialog
DECLARATION	: CDlgSerial
PARAMS		: [IN ] none
			  [OUT] BOOL
COMMENTS	: Dialog�� ó�� ȣ��Ǹ� �ش� OnInitDialog()�� ��ģ��.
			  �� �κп��� ComboBox�� ������ �߰��Ѵ�.
			  �߰��Ҷ� ���Ǵ� �Լ��� *.AddString(TEXT)�̸�
			  Ŀ�� ������ SetCurSel(int value)�̴�.
WARNINGS	: Ŀ�� ������ index�� 0���� �����Ѵ�.
**********************************************************************/
BOOL CDlgModalSerial::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	m_comboPort.AddString("COM1");
	m_comboPort.AddString("COM2");
	m_comboPort.AddString("COM3");
	m_comboPort.SetCurSel(0);

	m_comboBaudRate.AddString("110");
	m_comboBaudRate.AddString("300");
	m_comboBaudRate.AddString("600");
	m_comboBaudRate.AddString("1200");
	m_comboBaudRate.AddString("2400");
	m_comboBaudRate.AddString("4800");
	m_comboBaudRate.AddString("9600");
	m_comboBaudRate.AddString("14400");
	m_comboBaudRate.AddString("19200");
	m_comboBaudRate.AddString("38400");
	m_comboBaudRate.AddString("57600");
	m_comboBaudRate.AddString("115200");
	m_comboBaudRate.SetCurSel(8);

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}

/**********************************************************************
NAME		: OnBnClickedBtnOpen
DECLARATION	: CDlgSerial
PARAMS		: [IN ] none
			  [OUT] void
COMMENTS	: COM Port�� �����ϰ� Open�ϴ� �Լ�.
			  Dialog���� Open ��ư�� ������ ȣ��Ǹ�,
			  ó�� OnInitDialog()���� �����Ǿ��� ��ư���� ��Ȱ��ȭ �ǰ�,
			  ������ ��ư�� Ȱ��ȭ�ȴ�.
			  ���� Thread�� �����ϰ� �ڵ����� delete�� �ϴ� �κ��� false��
			  �����Ѵ�.
WARNINGS	: �Ϻ� utility �� �����ؾ� �� ������ �ִ�.(����)
**********************************************************************/
void CDlgModalSerial::OnBnClickedBtnOpen()
{
	char * pcTemp = new char[PORT_NAME];

	m_btnOpen.EnableWindow(false);
	m_btnClose.EnableWindow(true);
	m_btnSendData.EnableWindow(true);
	m_btnBack.EnableWindow(false);

	GetDlgItemText(IDC_COMBO_PORT, pcTemp, PORT_NAME);

	// VSPE�� ����(Stop Bits�� �ٸ��� �����ص� ���� ������ ����)�� ���� �⺻ �ɼ��� ������ ���
	rsPort = new CSerial;

	m_pThread = AfxBeginThread(_ThreadFuncModalSerial, this, THREAD_PRIORITY_NORMAL, 0, CREATE_SUSPENDED);
	
	// Debug mode ���� �Լ�(Release mode�� ������ ���� ���� �ʿ�)
	assert(m_pThread);

	m_pThread->m_bAutoDelete = false;
	m_pThread->ResumeThread();

	m_bStopRequest = false;

	delete [] pcTemp;
}

/**********************************************************************
NAME		: OnBnClickedBtnClose
DECLARATION	: CDlgSerial
PARAMS		: [IN ] none
			  [OUT] void
COMMENTS	: COM Port�� �����ϰ� Open�ϴ� �Լ�.
			  Dialog���� Open ��ư�� ������ ȣ��Ǹ�,
			  OnBnClickedBtnOpen()���� Ȱ��ȭ�Ǿ��� ��ư���� ��Ȱ��ȭ�ϸ�,
			  ������ ��ư���� Ȱ��ȭ ��Ų��.
			  ���� Thread�� ������ flag������ true���� �����ϸ�,
			  Thread�� ������ų SuspendThread()�� ȣ���Ѵ�.
			  ���������� Thread�� ������ ���� COM Port�� �ݴ� �Լ��� ȣ���ϸ�,
			  �ش� ��ü�� delete�Ѵ�.
WARNINGS	: none
**********************************************************************/
void CDlgModalSerial::OnBnClickedBtnClose()
{
	m_bStopRequest = true;

	m_btnOpen.EnableWindow(true);
	m_btnClose.EnableWindow(false);
	m_btnSendData.EnableWindow(false);
	m_btnBack.EnableWindow(true);

	m_pThread->SuspendThread();

	rsPort->Close();

	delete rsPort;
}

/**********************************************************************
NAME		: OnBnClickedBtnSendData
DECLARATION	: CDlgSerial
PARAMS		: [IN ] none
			  [OUT] void
COMMENTS	: Send Data ��ư�� ������ Text Editor ������Ʈ�� �Էµ� ������
			  ������ ũ���� cText ������ �����ϰ� WritePort()�� ����ִ�
			  WriteCommPort()�� ���ڸ� �Ѱ��ش�.
WARNINGS	: none
**********************************************************************/
void CDlgModalSerial::OnBnClickedBtnSendData()
{
	char szText[BUFF_SIZE];
	GetDlgItemText(IDC_EDIT_SEND_DATA, szText, BUFF_SIZE);

	char szPort[5];
	GetDlgItemText(IDC_COMBO_PORT, szPort, 5);

	if(NULL != rsPort)
	{
		rsPort->Send(szPort, 0, szText, strlen(szText), 0);
	}
}

/**********************************************************************
NAME		: OnBnClickedBtnBack
DECLARATION	: CDlgSerial
PARAMS		: [IN ] none
			  [OUT] void
COMMENTS	: Dialog �����Լ�. Dialog���� Back ��ư�� ������ ȣ��Ǹ�,
			  OnOk()���� �ڵ����� Destroy()�� ȣ��ȴ�.
WARNINGS	: none
**********************************************************************/
void CDlgModalSerial::OnBnClickedBtnBack()
{
	this->OnOK();
}

/**********************************************************************
NAME		: ThreadFunc
DECLARATION	: CDlgSerial
PARAMS		: [IN ] none
			  [OUT] int
COMMENTS	: Thread�� ���� �Լ�
			  while()�ȿ��� flag ������ m_bStopRequest�� ����Ͽ�
			  ������ų �� �ִ�.
WARNINGS	: none
**********************************************************************/
int CDlgModalSerial::ThreadFunc()
{
	while( !(m_bStopRequest) )
	{
		if(rsPort->IsConnected())
		{
			RecvMessage();
		}
	}

	return 0;
}

/**********************************************************************
NAME		: RecvMessage
DECLARATION	: CDlgSerial
PARAMS		: [IN ] none
			  [OUT] void
COMMENTS	: ThreadFunc()���� ȣ��Ǵ� �Լ�
			  ȣ���� �Լ��� ���Ͽ� �ֱ�������(�� 0.01sec����) ȣ��Ǹ�
			  ������ ũ��(100byte)�� ���� pcTemp�� ReadCommPort()�� ����
			  ������ �����Ѵ�.
			  ���� �� ListControl ������Ʈ�� AddString()�̿��Ͽ� ������
			  �߰��Ѵ�.
WARNINGS	: none
**********************************************************************/
void CDlgModalSerial::RecvMessage(void)
{
	char pcTemp[BUFF_SIZE] = {0, };
	memset(pcTemp, 0, BUFF_SIZE);

	int nExistBuffer = rsPort->CountRx();

	rsPort->Receive(0, 0, pcTemp, BUFF_SIZE);

	if(0 < strlen(pcTemp))
	{
		pcTemp[BUFF_SIZE - 1] = '\0';

		m_listReceiveData.AddString(pcTemp);
	}

	Sleep(10);
}
