#if !defined(AFX_DENGLU_H__9CE1FFAB_FBE8_4001_9C91_17E5FD71760C__INCLUDED_)
#define AFX_DENGLU_H__9CE1FFAB_FBE8_4001_9C91_17E5FD71760C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DengLu.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// DengLu dialog

class DengLu : public CDialog
{
// Construction
public:
	DengLu(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DengLu)
	enum { IDD = IDD_DIALOG1 };
	CString	m_Name;
	CString	m_Password;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DengLu)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(DengLu)
	afx_msg void OnPaint();
	afx_msg void OnZhuce();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DENGLU_H__9CE1FFAB_FBE8_4001_9C91_17E5FD71760C__INCLUDED_)
