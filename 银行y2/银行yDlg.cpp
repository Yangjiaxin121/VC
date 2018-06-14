// 银行yDlg.cpp : implementation file
//

#include "stdafx.h"
#include "银行y.h"
#include "银行yDlg.h"

#include "Ziliao.h"
#include "SAVE.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CYDlg dialog

CYDlg::CYDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CYDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CYDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CYDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CYDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CYDlg, CDialog)
	//{{AFX_MSG_MAP(CYDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_Chaxun, OnBUTTONChaxun)
	ON_BN_CLICKED(IDC_BUTTON_Cunkuan, OnBUTTONCunkuan)
	ON_BN_CLICKED(IDC_BUTTON_Ziliao, OnBUTTONZiliao)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CYDlg message handlers

BOOL CYDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CYDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CYDlg::OnPaint() 
{
	CPaintDC dc(this); // device context for painting           
	CBitmap m_bitmap;                                           //用于添加背景图片
    m_bitmap.LoadBitmap(IDB_BITMAP8);         //位图资源标识
    CDC memdc;
    memdc.CreateCompatibleDC(&dc);
    memdc.SelectObject(&m_bitmap);
    int width,height;
    BITMAP bmp;
    m_bitmap.GetBitmap(&bmp);                 //获取位图的宽度，高度，
    width= bmp.bmWidth;
    height= bmp.bmHeight;
    CRect rect;
    this->GetClientRect(&rect);             //矩形。
    dc.StretchBlt(rect.left,rect.top,rect.Width(),rect.Height(),&memdc,0,0,width,height,SRCCOPY);        //此函数实现位图文件的缩放等，这里不缩放。
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}


// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CYDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CYDlg::OnBUTTONChaxun()                     //查询余额
{
	// TODO: Add your control notification handler code here
	CString YuE;
	CFile OpenFile1;
	OpenFile1.Open(m+"_余额.txt",CFile::modeReadWrite);
         //dlgOpen为CFileDialog对象
	int length1=OpenFile1.GetLength();//获取文件长度
	char *pBuf1=(char *)malloc(sizeof(char)*length1);//开辟缓冲区
	char *tp1=pBuf1;
	while (tp1<pBuf1+length1)
	{
		*tp1=NULL;
		tp1++;
	}//清空缓冲区
	OpenFile1.Read(pBuf1,length1);//读文件
	OpenFile1.Close();
	YuE=pBuf1;
	CString x="亲~您的余额还有:";
	x=x+YuE;
	MessageBox(x);
}

void CYDlg::OnBUTTONCunkuan()             //存款
{
	// TODO: Add your control notification handler code here
	SAVE save;
	save.DoModal();
}

void CYDlg::OnBUTTONZiliao()                        //查看资料
{
	// TODO: Add your control notification handler code here

	Ziliao ziliao;
	ziliao.DoModal();	
}
