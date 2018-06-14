#if !defined(AFX_ZILIAO_H__5850F471_1C68_4C8D_98BA_8A07A8057B68__INCLUDED_)
#define AFX_ZILIAO_H__5850F471_1C68_4C8D_98BA_8A07A8057B68__INCLUDED_


#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Ziliao.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Ziliao dialog

class Ziliao : public CDialog
{
// Construction
public:
	CString m_shareValue;
	Ziliao(CWnd* pParent = NULL);   // standard constructor
// Dialog Data
	//{{AFX_DATA(Ziliao)
	enum { IDD = IDD_DIALOG2 };
	CString	m_Zhuzhi;
	CString	m_Zhanghu;
	CString	m_Xingming;
	CString	m_Mima;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Ziliao)
	public:
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Ziliao)
	virtual BOOL OnInitDialog();
	afx_msg void OnBaocun();
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ZILIAO_H__5850F471_1C68_4C8D_98BA_8A07A8057B68__INCLUDED_)
