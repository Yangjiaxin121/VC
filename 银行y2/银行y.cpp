// 银行y.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "银行y.h"
#include "银行yDlg.h"

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
			BOOL fileExist=(BOOL)tempFind.FindFile(PassDlg.m_Name+"_账户.txt"); //找文件

			CString strText;
			CString strText2;
			if (fileExist)
			{
				CString Num1,Num2;
				Num1=PassDlg.m_Name+"_账户.txt";
				Num2=PassDlg.m_Name+"_密码.txt"; 

				CString szLine; //存储行字符串
				CStdioFile file;
				if(!file.Open(Num1,CFile::modeRead))//打开文件	//逐行读取字符串
				{
					AfxMessageBox(_T("File could not be opened \n"));
				}
				while( file.ReadString( szLine ) )
				{
					strText += szLine;
				}			
				file.Close();	//关闭文件

				CString szLine2; //存储行字符串
				CStdioFile file2;
				if(!file2.Open(Num2,CFile::modeRead))//打开文件	//逐行读取字符串
				{
					AfxMessageBox(_T("File could not be opened \n"));
				}
				while( file2.ReadString( szLine2 ) )
				{
					strText2 += szLine2;
				}
				file2.Close();	//关闭文件
		

				if((strcmp(PassDlg.m_Name,strText)!=0)||(strcmp(PassDlg.m_Password,strText2)!=0))
				{

					MessageBox(NULL,"用户名或口令错误，请重试!","错误信息",MB_OK|MB_ICONERROR);
					nCount++;
				}
				else
				{
					m=PassDlg.m_Name;        //m为定义在StdAfx.h里的全局变量，保存当前的账户名字，用于资料里面方便进行查询
					break;
				}
			}
			else
			{
				MessageBox(NULL,"用户名或口令错误，请重试!","错误信息",MB_OK|MB_ICONERROR);
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
		MessageBox(NULL,"口令输入错误超过3次，请退出！","错误信息",MB_OK|MB_ICONERROR);
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
