// DlgSerial.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Chapter(9-1).h"
#include "DlgSerial.h"
#include "afxdialogex.h"

// CDlgSerial 대화 상자입니다.

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
COMMENTS	: Dialog가 처음 호출되면 해당 OnInitDialog()를 거친다.
			  이 부분에서 ComboBox에 내용을 추가한다.
			  추가할때 사용되는 함수는 *.AddString(TEXT)이며
			  커서 설정은 SetCurSel(int value)이다.
WARNINGS	: 커서 설정시 index는 0부터 시작한다.
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
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

/**********************************************************************
NAME		: OnBnClickedBtnBack
DECLARATION	: CDlgSerial
PARAMS		: [IN ] none
			  [OUT] void
COMMENTS	: Dialog 종료함수. Dialog내에 Back 버튼을 누르면 호출되며,
			  OnOk()이후 자동으로 Destroy()가 호출된다.
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
COMMENTS	: COM Port를 정의하고 Open하는 함수.
			  Dialog내에 Open 버튼을 누르면 호출되며,
			  처음 OnInitDialog()에서 설정되었던 버튼들이 비활성화 되고,
			  나머지 버튼이 활성화된다.
			  또한 Thread를 정의하고 자동으로 delete를 하는 부분을 false로
			  설정한다.
WARNINGS	: 일부 utility 및 변경해야 할 내용이 있다.(예정)
**********************************************************************/
void CDlgSerial::OnBnClickedBtnOpen()
{
	char * pcTemp = new char[PORT_NAME];

	m_btnOpen.EnableWindow(false);
	m_btnClose.EnableWindow(true);
	m_btnSendData.EnableWindow(true);
	m_btnBack.EnableWindow(false);

	GetDlgItemText(IDC_COMBO_PORT, pcTemp, PORT_NAME);

	// VSPE의 버그(Stop Bits를 다르게 설정해도 값의 전달이 가능)로 인해 기본 옵션의 생성자 사용
	rsPort = new CSerial;

	m_pThread = AfxBeginThread(_ThreadFuncSerial, this, THREAD_PRIORITY_NORMAL, 0, CREATE_SUSPENDED);
	
	// Debug mode 전용 함수(Release mode로 생성시 따로 변경 필요)
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
COMMENTS	: COM Port를 정의하고 Open하는 함수.
			  Dialog내에 Open 버튼을 누르면 호출되며,
			  OnBnClickedBtnOpen()에서 활성화되었던 버튼들을 비활성화하며,
			  나머지 버튼들을 활성화 시킨다.
			  또한 Thread를 정지할 flag변수에 true값을 대입하며,
			  Thread를 정지시킬 SuspendThread()를 호출한다.
			  마지막으로 Thread가 정지된 이후 COM Port를 닫는 함수를 호출하며,
			  해당 객체를 delete한다.
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
COMMENTS	: Send Data 버튼을 누르면 Text Editor 컴포넌트에 입력된 내용을
			  지정된 크기의 cText 변수에 대입하고 WritePort()를 담고있는
			  WriteCommPort()로 인자를 넘겨준다.
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
COMMENTS	: Thread로 사용될 함수
			  while()안에서 flag 변수인 m_bStopRequest를 사용하여
			  정지시킬 수 있다.
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
COMMENTS	: ThreadFunc()에서 호출되는 함수
			  호출한 함수로 인하여 주기적으로(약 0.01sec마다) 호출되며
			  지정된 크기(100byte)의 변수 pcTemp에 ReadCommPort()를 통해
			  내용을 대입한다.
			  대입 후 ListControl 컴포넌트에 AddString()이용하여 내용을
			  추가한다.
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