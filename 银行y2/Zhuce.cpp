// Zhuce.cpp : implementation file
//

#include "stdafx.h"
#include "����y.h"
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
	CFile file1(m_zhanghu+"_�˻�.txt", CFile::modeCreate|CFile::modeReadWrite);
	CString str1;
	str1.Format("%s",m_zhanghu);//��Щ�������Ǳ༭���Ӧ�ı���
	file1.Write(str1, str1.GetLength());    //����sizeof(str), sizeof(str) ==4�����㱣��Ҳ��ָ����4����Ӧ��ʹ��str.GetLength()
	file1.Close();

	CFile file2(m_zhanghu+"_����.txt", CFile::modeReadWrite | CFile::modeCreate|CFile::modeNoTruncate);
	CString str2;
	str2.Format("%s",m_mima);//��Щ�������Ǳ༭���Ӧ�ı���
	file2.Write(str2, str2.GetLength());    //����sizeof(str), sizeof(str) ==4�����㱣��Ҳ��ָ����4����Ӧ��ʹ��str.GetLength()
	file2.Close();

	CFile file3(m_zhanghu+"_����.txt", CFile::modeReadWrite | CFile::modeCreate|CFile::modeNoTruncate);
	CString str3;
	str3.Format("%s",m_xingming);//��Щ�������Ǳ༭���Ӧ�ı���
	file3.Write(str3, str3.GetLength());    //����sizeof(str), sizeof(str) ==4�����㱣��Ҳ��ָ����4����Ӧ��ʹ��str.GetLength()
	file3.Close();

	CFile file4(m_zhanghu+"_סַ.txt", CFile::modeReadWrite | CFile::modeCreate|CFile::modeNoTruncate);
	CString str4;
	str4.Format("%s",m_zhuzhi);//��Щ�������Ǳ༭���Ӧ�ı���
	file4.Write(str4, str4.GetLength());    //����sizeof(str), sizeof(str) ==4�����㱣��Ҳ��ָ����4����Ӧ��ʹ��str.GetLength()
	file4.Close();

	CFile file5(m_zhanghu+"_���.txt", CFile::modeCreate|CFile::modeReadWrite);
	CString str5;
	m_yue=0;
	str5.Format("%d",m_yue);//��Щ�������Ǳ༭���Ӧ�ı���
	file5.Write(str5, str5.GetLength());    //����sizeof(str), sizeof(str) ==4�����㱣��Ҳ��ָ����4����Ӧ��ʹ��str.GetLength()
	file5.Close();

	MessageBox("��~ע��ɹ�����ȥ��¼��Ǯ�ɣ�( ^3^ )�u~~");
}

void Zhuce::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	CBitmap m_bitmap;                                           //������ӱ���ͼƬ
    m_bitmap.LoadBitmap(IDB_BITMAP8);         //λͼ��Դ��ʶ
    CDC memdc;
    memdc.CreateCompatibleDC(&dc);
    memdc.SelectObject(&m_bitmap);
    int width,height;
    BITMAP bmp;
    m_bitmap.GetBitmap(&bmp);                 //��ȡλͼ�Ŀ�ȣ��߶ȣ�
    width= bmp.bmWidth;
    height= bmp.bmHeight;
    CRect rect;
    this->GetClientRect(&rect);             //���Ρ�
    dc.StretchBlt(rect.left,rect.top,rect.Width(),rect.Height(),&memdc,0,0,width,height,SRCCOPY); 
	// Do not call CDialog::OnPaint() for painting messages
}
