// SAVE.cpp : implementation file
//

#include "stdafx.h"
#include "����y.h"
#include "SAVE.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// SAVE dialog


SAVE::SAVE(CWnd* pParent /*=NULL*/)
	: CDialog(SAVE::IDD, pParent)
{
	//{{AFX_DATA_INIT(SAVE)
	m_CunQian = 0;
	m_YuE = 0;
	//}}AFX_DATA_INIT
}


void SAVE::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(SAVE)
	DDX_Text(pDX, IDC_EDIT_CUN, m_CunQian);
	DDX_Text(pDX, IDC_EDIT_YUE, m_YuE);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(SAVE, CDialog)
	//{{AFX_MSG_MAP(SAVE)
	ON_BN_CLICKED(IDC_BUTTON_QUEREN, OnButtonQueren)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// SAVE message handlers


BOOL SAVE::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here

	CString strText1;
	CString szLine1; //�洢���ַ���
	CStdioFile file1;
	file1.Open(m+"_���.txt",CFile::modeRead);//���ļ�
	//���ж�ȡ�ַ���
	while( file1.ReadString( szLine1 ) )
	{
		strText1 += szLine1;
	}
	file1.Close();	//�ر��ļ�
	m_YuE=_ttoi(_T(strText1));            //���ַ���ת��Ϊ���Σ�����ֵ��������

	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void SAVE::OnButtonQueren() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	m_YuE=m_YuE+m_CunQian;
	CFile file1(m+"_���.txt", CFile::modeCreate|CFile::modeReadWrite);
	CString str1;
	str1.Format("%d",m_YuE);//��Щ�������Ǳ༭���Ӧ�ı���
	file1.Write(str1, str1.GetLength());   
	file1.Close();
	
	UpdateData(FALSE);
	MessageBox("���ɹ���");
}




void SAVE::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	CBitmap m_bitmap;                                      //������ӱ���ͼƬ
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
