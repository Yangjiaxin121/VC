// DengLu.cpp : implementation file
//

#include "stdafx.h"
#include "银行y.h"
#include "DengLu.h"

#include "Zhuce.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DengLu dialog


DengLu::DengLu(CWnd* pParent /*=NULL*/)
	: CDialog(DengLu::IDD, pParent)
{
	//{{AFX_DATA_INIT(DengLu)
	m_Name = _T("");
	m_Password = _T("");
	//}}AFX_DATA_INIT
}


void DengLu::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DengLu)
	DDX_Text(pDX, IDC_EDIT_Name, m_Name);
	DDX_Text(pDX, IDC_EDIT_Password, m_Password);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DengLu, CDialog)
	//{{AFX_MSG_MAP(DengLu)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_ZHUCE, OnZhuce)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DengLu message handlers

void DengLu::OnPaint() 
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
    dc.StretchBlt(rect.left,rect.top,rect.Width(),rect.Height(),&memdc,0,0,width,height,SRCCOPY);        //此函数实现位图文件的缩放等，这里不缩放。
	// Do not call CDialog::OnPaint() for painting messages
}

void DengLu::OnZhuce() 
{
	// TODO: Add your control notification handler code here
	Zhuce z;
	z.DoModal();
}
