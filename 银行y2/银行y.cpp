// ����y.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "����y.h"
#include "����yDlg.h"

#include "Ziliao.h"
#include "DengLu.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CYApp

BEGIN_MESSAGE_MAP(CYApp, CWinApp)
	//{{AFX_MSG_MAP(CYApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CYApp construction

CYApp::CYApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CYApp object

CYApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CYApp initialization

BOOL CYApp::InitInstance()
{
	int nCount=0;

	while(nCount<3)
	{
		DengLu PassDlg;	

		if(PassDlg.DoModal()==IDOK)
		{
			CFileFind tempFind;
			BOOL fileExist=(BOOL)tempFind.FindFile(PassDlg.m_Name+"_�˻�.txt"); //���ļ�

			CString strText;
			CString strText2;
			if (fileExist)
			{
				CString Num1,Num2;
				Num1=PassDlg.m_Name+"_�˻�.txt";
				Num2=PassDlg.m_Name+"_����.txt"; 

				CString szLine; //�洢���ַ���
				CStdioFile file;
				if(!file.Open(Num1,CFile::modeRead))//���ļ�	//���ж�ȡ�ַ���
				{
					AfxMessageBox(_T("File could not be opened \n"));
				}
				while( file.ReadString( szLine ) )
				{
					strText += szLine;
				}			
				file.Close();	//�ر��ļ�

				CString szLine2; //�洢���ַ���
				CStdioFile file2;
				if(!file2.Open(Num2,CFile::modeRead))//���ļ�	//���ж�ȡ�ַ���
				{
					AfxMessageBox(_T("File could not be opened \n"));
				}
				while( file2.ReadString( szLine2 ) )
				{
					strText2 += szLine2;
				}
				file2.Close();	//�ر��ļ�
		

				if((strcmp(PassDlg.m_Name,strText)!=0)||(strcmp(PassDlg.m_Password,strText2)!=0))
				{

					MessageBox(NULL,"�û�����������������!","������Ϣ",MB_OK|MB_ICONERROR);
					nCount++;
				}
				else
				{
					m=PassDlg.m_Name;        //mΪ������StdAfx.h���ȫ�ֱ��������浱ǰ���˻����֣������������淽����в�ѯ
					break;
				}
			}
			else
			{
				MessageBox(NULL,"�û�����������������!","������Ϣ",MB_OK|MB_ICONERROR);
				nCount++;
			}
		}
		else
		{
			return FALSE;
		}
	}
	if(nCount>=3)
	{
		MessageBox(NULL,"����������󳬹�3�Σ����˳���","������Ϣ",MB_OK|MB_ICONERROR);
		return FALSE;
	}
	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	CYDlg dlg;
	m_pMainWnd = &dlg;
	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}
