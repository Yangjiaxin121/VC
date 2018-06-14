// Ziliao.cpp : implementation file
//

#include "stdafx.h"
#include "银行y.h"
#include "Ziliao.h"

#include "DengLu.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Ziliao dialog


Ziliao::Ziliao(CWnd* pParent /*=NULL*/)
	: CDialog(Ziliao::IDD, pParent)
{
	//{{AFX_DATA_INIT(Ziliao)
	m_Zhuzhi = _T("");
	m_Zhanghu = _T("");
	m_Xingming = _T("");
	m_Mima = _T("");
	//}}AFX_DATA_INIT
}


void Ziliao::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Ziliao)
	DDX_Text(pDX, IDC_Zhuzhi, m_Zhuzhi);
	DDX_Text(pDX, IDC_Zhanghu, m_Zhanghu);
	DDX_Text(pDX, IDC_Xingming, m_Xingming);
	DDX_Text(pDX, IDC_Mima, m_Mima);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Ziliao, CDialog)
	//{{AFX_MSG_MAP(Ziliao)
	ON_BN_CLICKED(IDC_BAOCUN, OnBaocun)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Ziliao message handlers

//DEL void Ziliao::Serialize(CArchive& ar) 
//DEL {
//DEL 	if (ar.IsStoring())
//DEL 	{	// storing code
//DEL 		ar<<m_Xingming<<m_Mima<<m_Zhanghu<<m_Zhuzhi;
//DEL 	}
//DEL 	else
//DEL 	{	// loading code
//DEL 		ar>>m_Xingming>>m_Mima>>m_Zhanghu>>m_Zhuzhi;
//DEL 	}
//DEL }

BOOL Ziliao::OnInitDialog()         //从文件中读取信息
{
	CDialog::OnInitDialog();

	CString strText1;
	CString szLine1; //存储行字符串
	CStdioFile file1;
	CString Num1,Num2,Num3,Num4;
	Num1=m+"_账户.txt";
	file1.Open(Num1,CFile::modeRead);//打开文件
	//逐行读取字符串
	while( file1.ReadString( szLine1 ) )
	{
		strText1 += szLine1;
	}
	m_Zhanghu=strText1;
	file1.Close();	//关闭文件


	CString strText2;
	CString szLine2; //存储行字符串
	CStdioFile file2;
	Num2=m+"_密码.txt";
	file2.Open(Num2,CFile::modeRead);//打开文件
	//逐行读取字符串
	while( file2.ReadString( szLine2 ) )
	{
		strText2 += szLine2;
	}
	m_Mima=strText2;
	file2.Close();	//关闭文件


	CString strText3;
	CString szLine3; //存储行字符串
	CStdioFile file3;
	Num3=m+"_姓名.txt";
	file3.Open(Num3,CFile::modeRead);//打开文件
	//逐行读取字符串
	while( file3.ReadString( szLine3 ) )
	{
		strText3 += szLine3;
	}
	m_Xingming=strText3;
	file3.Close();	//关闭文件


	CString strText4;
	CString szLine4; //存储行字符串
	CStdioFile file4;
	Num4=m+"_住址.txt";
	file4.Open(Num4,CFile::modeRead);//打开文件
	//逐行读取字符串
	while( file4.ReadString( szLine4 ) )
	{
		strText4 += szLine4;
	}
	m_Zhuzhi=strText4;
	file4.Close();	//关闭文件


	UpdateData(FALSE);

	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void Ziliao::OnBaocun()  //保存信息进文件中
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	CFile file1(m_Zhanghu+"_账户.txt", CFile::modeCreate|CFile::modeReadWrite);
	CString str1;
	str1.Format("%s",m_Zhanghu);//这些变量都是编辑框对应的变量
	file1.Write(str1, str1.GetLength());  
	file1.Close();

	CFile file2(m_Zhanghu+"_密码.txt", CFile::modeReadWrite | CFile::modeCreate|CFile::modeNoTruncate);
	CString str2;
	str2.Format("%s",m_Mima);//这些变量都是编辑框对应的变量
	file2.Write(str2, str2.GetLength());   
	file2.Close();

	CFile file3(m_Zhanghu+"_姓名.txt", CFile::modeReadWrite | CFile::modeCreate|CFile::modeNoTruncate);
	CString str3;
	str3.Format("%s",m_Xingming);//这些变量都是编辑框对应的变量
	file3.Write(str3, str3.GetLength());   
	file3.Close();

	CFile file4(m_Zhanghu+"_住址.txt", CFile::modeReadWrite | CFile::modeCreate|CFile::modeNoTruncate);
	CString str4;
	str4.Format("%s",m_Zhuzhi);//这些变量都是编辑框对应的变量
	file4.Write(str4, str4.GetLength());   
	file4.Close();

	MessageBox("亲~保存成功！( ^3^ )╱~~");
}

void Ziliao::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	CBitmap m_bitmap;                                //用于添加背景图片
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
    dc.StretchBlt(rect.left,rect.top,rect.Width(),rect.Height(),&memdc,0,0,width,height,SRCCOPY); 
	// Do not call CDialog::OnPaint() for painting messages
}

//DEL void Ziliao::SetShareValue(CString value)
//DEL {
//DEL 	m_shareValue=value;
//DEL }
