#if !defined(AFX_SAVE_H__35448A67_FA32_43AC_A34A_6BFBBD403224__INCLUDED_)
#define AFX_SAVE_H__35448A67_FA32_43AC_A34A_6BFBBD403224__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SAVE.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// SAVE dialog

class SAVE : public CDialog
{
// Construction
public:
	SAVE(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(SAVE)
	enum { IDD = IDD_DIALOG_CUNKUAN };
	int		m_CunQian;
	int		m_YuE;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(SAVE)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(SAVE)
	afx_msg void OnButtonQueren();
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SAVE_H__35448A67_FA32_43AC_A34A_6BFBBD403224__INCLUDED_)
