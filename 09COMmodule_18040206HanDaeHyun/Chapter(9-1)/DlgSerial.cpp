// DlgSerial.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Chapter(9-1).h"
#include "DlgSerial.h"
#include "afxdialogex.h"

// CDlgSerial ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CDlgSerial, CDialogEx)

CDlgSerial::CDlgSerial(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgSerial::IDD, pParent)
{

}

CDlgSerial::~CDlgSerial()
{
	
}

void CDlgSerial::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_PORT, m_comboPort);
	DDX_Control(pDX, IDC_COMBO_BAUD_RATE, m_comboBaudRate);
	DDX_Control(pDX, IDC_EDIT_SEND_DATA, m_editData);
	DDX_Control(pDX, IDC_LIST_RECEIVE, m_listReceiveData);
	DDX_Control(pDX, IDC_BTN_OPEN, m_btnOpen);
	DDX_Control(pDX, IDC_BTN_CLOSE, m_btnClose);
	DDX_Control(pDX, IDC_BTN_SEND_DATA, m_btnSendData);
	DDX_Control(pDX, IDC_BTN_BACK, m_btnBack);
}


BEGIN_MESSAGE_MAP(CDlgSerial, CDialogEx)
	ON_BN_CLICKED(IDC_BTN_BACK, &CDlgSerial::OnBnClickedBtnBack)
	ON_BN_CLICKED(IDC_BTN_OPEN, &CDlgSerial::OnBnClickedBtnOpen)
	ON_BN_CLICKED(IDC_BTN_CLOSE, &CDlgSerial::OnBnClickedBtnClose)
	ON_BN_CLICKED(IDC_BTN_SEND_DATA, &CDlgSerial::OnBnClickedBtnSendData)
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
BOOL CDlgSerial::OnInitDialog()
{
	CDialogEx::OnInitDialog();

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
NAME		: OnBnClickedBtnBack
DECLARATION	: CDlgSerial
PARAMS		: [IN ] none
			  [OUT] void
COMMENTS	: Dialog �����Լ�. Dialog���� Back ��ư�� ������ ȣ��Ǹ�,
			  OnOk()���� �ڵ����� Destroy()�� ȣ��ȴ�.
WARNINGS	: none
**********************************************************************/
void CDlgSerial::OnBnClickedBtnBack()
{
	this->OnOK();
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
void CDlgSerial::OnBnClickedBtnOpen()
{
	char * pcTemp = new char[PORT_NAME];

	m_btnOpen.EnableWindow(false);
	m_btnClose.EnableWindow(true);
	m_btnSendData.EnableWindow(true);
	m_btnBack.EnableWindow(false);

	GetDlgItemText(IDC_COMBO_PORT, pcTemp, PORT_NAME);

	// VSPE�� ����(Stop Bits�� �ٸ��� �����ص� ���� ������ ����)�� ���� �⺻ �ɼ��� ������ ���
	rsPort = new CSerial;

	m_pThread = AfxBeginThread(_ThreadFuncSerial, this, THREAD_PRIORITY_NORMAL, 0, CREATE_SUSPENDED);
	
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
void CDlgSerial::OnBnClickedBtnClose()
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
void CDlgSerial::OnBnClickedBtnSendData()
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
NAME		: ThreadFunc
DECLARATION	: CDlgSerial
PARAMS		: [IN ] none
			  [OUT] int
COMMENTS	: Thread�� ���� �Լ�
			  while()�ȿ��� flag ������ m_bStopRequest�� ����Ͽ�
			  ������ų �� �ִ�.
WARNINGS	: none
**********************************************************************/
int CDlgSerial::ThreadFunc()
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
void CDlgSerial::RecvMessage()
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