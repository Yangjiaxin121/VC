#if !defined(AFX_ZHUCE_H__077E33BD_28A9_447D_BA8A_1B91A1196E38__INCLUDED_)
#define AFX_ZHUCE_H__077E33BD_28A9_447D_BA8A_1B91A1196E38__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Zhuce.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Zhuce dialog

class Zhuce : public CDialog
{
// Construction
public:
	int m_yue;
	Zhuce(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(Zhuce)
	enum { IDD = IDD_DIALOG3 };
	CString	m_mima;
	CString	m_xingming;
	CString	m_zhanghu;
	CString	m_zhuzhi;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Zhuce)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Zhuce)
	afx_msg void OnBaocun();
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ZHUCE_H__077E33BD_28A9_447D_BA8A_1B91A1196E38__INCLUDED_)
