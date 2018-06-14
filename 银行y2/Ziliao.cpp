// Ziliao.cpp : implementation file
//

#include "stdafx.h"
#include "����y.h"
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

BOOL Ziliao::OnInitDialog()         //���ļ��ж�ȡ��Ϣ
{
	CDialog::OnInitDialog();

	CString strText1;
	CString szLine1; //�洢���ַ���
	CStdioFile file1;
	CString Num1,Num2,Num3,Num4;
	Num1=m+"_�˻�.txt";
	file1.Open(Num1,CFile::modeRead);//���ļ�
	//���ж�ȡ�ַ���
	while( file1.ReadString( szLine1 ) )
	{
		strText1 += szLine1;
	}
	m_Zhanghu=strText1;
	file1.Close();	//�ر��ļ�


	CString strText2;
	CString szLine2; //�洢���ַ���
	CStdioFile file2;
	Num2=m+"_����.txt";
	file2.Open(Num2,CFile::modeRead);//���ļ�
	//���ж�ȡ�ַ���
	while( file2.ReadString( szLine2 ) )
	{
		strText2 += szLine2;
	}
	m_Mima=strText2;
	file2.Close();	//�ر��ļ�


	CString strText3;
	CString szLine3; //�洢���ַ���
	CStdioFile file3;
	Num3=m+"_����.txt";
	file3.Open(Num3,CFile::modeRead);//���ļ�
	//���ж�ȡ�ַ���
	while( file3.ReadString( szLine3 ) )
	{
		strText3 += szLine3;
	}
	m_Xingming=strText3;
	file3.Close();	//�ر��ļ�


	CString strText4;
	CString szLine4; //�洢���ַ���
	CStdioFile file4;
	Num4=m+"_סַ.txt";
	file4.Open(Num4,CFile::modeRead);//���ļ�
	//���ж�ȡ�ַ���
	while( file4.ReadString( szLine4 ) )
	{
		strText4 += szLine4;
	}
	m_Zhuzhi=strText4;
	file4.Close();	//�ر��ļ�


	UpdateData(FALSE);

	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void Ziliao::OnBaocun()  //������Ϣ���ļ���
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	CFile file1(m_Zhanghu+"_�˻�.txt", CFile::modeCreate|CFile::modeReadWrite);
	CString str1;
	str1.Format("%s",m_Zhanghu);//��Щ�������Ǳ༭���Ӧ�ı���
	file1.Write(str1, str1.GetLength());  
	file1.Close();

	CFile file2(m_Zhanghu+"_����.txt", CFile::modeReadWrite | CFile::modeCreate|CFile::modeNoTruncate);
	CString str2;
	str2.Format("%s",m_Mima);//��Щ�������Ǳ༭���Ӧ�ı���
	file2.Write(str2, str2.GetLength());   
	file2.Close();

	CFile file3(m_Zhanghu+"_����.txt", CFile::modeReadWrite | CFile::modeCreate|CFile::modeNoTruncate);
	CString str3;
	str3.Format("%s",m_Xingming);//��Щ�������Ǳ༭���Ӧ�ı���
	file3.Write(str3, str3.GetLength());   
	file3.Close();

	CFile file4(m_Zhanghu+"_סַ.txt", CFile::modeReadWrite | CFile::modeCreate|CFile::modeNoTruncate);
	CString str4;
	str4.Format("%s",m_Zhuzhi);//��Щ�������Ǳ༭���Ӧ�ı���
	file4.Write(str4, str4.GetLength());   
	file4.Close();

	MessageBox("��~����ɹ���( ^3^ )�u~~");
}

void Ziliao::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	CBitmap m_bitmap;                                //������ӱ���ͼƬ
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

//DEL void Ziliao::SetShareValue(CString value)
//DEL {
//DEL 	m_shareValue=value;
//DEL }
