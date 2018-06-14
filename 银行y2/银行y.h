// 银行y.h : main header file for the 银行Y application
//

#if !defined(AFX_Y_H__A736B2BB_D02E_40B7_B309_6E5A6165FA10__INCLUDED_)
#define AFX_Y_H__A736B2BB_D02E_40B7_B309_6E5A6165FA10__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CYApp:
// See 银行y.cpp for the implementation of this class
//

class CYApp : public CWinApp
{
public:
	CString m_Num;
	CYApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CYApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CYApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_Y_H__A736B2BB_D02E_40B7_B309_6E5A6165FA10__INCLUDED_)
