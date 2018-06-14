// Zhuce.cpp : implementation file
//

#include "stdafx.h"
#include "银行y.h"
#include "Zhuce.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Zhuce dialog


Zhuce::Zhuce(CWnd* pParent /*=NULL*/)
	: CDialog(Zhuce::IDD, pParent)
{
	//{{AFX_DATA_INIT(Zhuce)
	m_mima = _T("");
	m_xingming = _T("");
	m_zhanghu = _T("");
	m_zhuzhi = _T("");
	//}}AFX_DATA_INIT
}


void Zhuce::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Zhuce)
	DDX_Text(pDX, IDC_Mima, m_mima);
	DDX_Text(pDX, IDC_Xingming, m_xingming);
	DDX_Text(pDX, IDC_Zhanghu, m_zhanghu);
	DDX_Text(pDX, IDC_Zhuzhi, m_zhuzhi);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Zhuce, CDialog)
	//{{AFX_MSG_MAP(Zhuce)
	ON_BN_CLICKED(IDC_BAOCUN, OnBaocun)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Zhuce message handlers

void Zhuce::OnBaocun() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	CFile file1(m_zhanghu+"_账户.txt", CFile::modeCreate|CFile::modeReadWrite);
	CString str1;
	str1.Format("%s",m_zhanghu);//这些变量都是编辑框对应的变量
	file1.Write(str1, str1.GetLength());    //不是sizeof(str), sizeof(str) ==4，就算保存也是指保存4个，应该使用str.GetLength()
	file1.Close();

	CFile file2(m_zhanghu+"_密码.txt", CFile::modeReadWrite | CFile::modeCreate|CFile::modeNoTruncate);
	CString str2;
	str2.Format("%s",m_mima);//这些变量都是编辑框对应的变量
	file2.Write(str2, str2.GetLength());    //不是sizeof(str), sizeof(str) ==4，就算保存也是指保存4个，应该使用str.GetLength()
	file2.Close();

	CFile file3(m_zhanghu+"_姓名.txt", CFile::modeReadWrite | CFile::modeCreate|CFile::modeNoTruncate);
	CString str3;
	str3.Format("%s",m_xingming);//这些变量都是编辑框对应的变量
	file3.Write(str3, str3.GetLength());    //不是sizeof(str), sizeof(str) ==4，就算保存也是指保存4个，应该使用str.GetLength()
	file3.Close();

	CFile file4(m_zhanghu+"_住址.txt", CFile::modeReadWrite | CFile::modeCreate|CFile::modeNoTruncate);
	CString str4;
	str4.Format("%s",m_zhuzhi);//这些变量都是编辑框对应的变量
	file4.Write(str4, str4.GetLength());    //不是sizeof(str), sizeof(str) ==4，就算保存也是指保存4个，应该使用str.GetLength()
	file4.Close();

	CFile file5(m_zhanghu+"_余额.txt", CFile::modeCreate|CFile::modeReadWrite);
	CString str5;
	m_yue=0;
	str5.Format("%d",m_yue);//这些变量都是编辑框对应的变量
	file5.Write(str5, str5.GetLength());    //不是sizeof(str), sizeof(str) ==4，就算保存也是指保存4个，应该使用str.GetLength()
	file5.Close();

	MessageBox("亲~注册成功！快去登录存钱吧！( ^3^ )╱~~");
}

void Zhuce::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
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
    dc.StretchBlt(rect.left,rect.top,rect.Width(),rect.Height(),&memdc,0,0,width,height,SRCCOPY); 
	// Do not call CDialog::OnPaint() for painting messages
}
