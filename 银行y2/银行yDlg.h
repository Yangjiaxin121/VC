// ÒøÐÐyDlg.h : header file
//

#if !defined(AFX_YDLG_H__F0C20F83_09DA_4333_86DF_BB425E2DA85F__INCLUDED_)
#define AFX_YDLG_H__F0C20F83_09DA_4333_86DF_BB425E2DA85F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CYDlg dialog

class CYDlg : public CDialog
{
// Construction
public:
	CYDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CYDlg)
	enum { IDD = IDD_Y_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CYDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CYDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBUTTONChaxun();
	afx_msg void OnBUTTONCunkuan();
	afx_msg void OnBUTTONZiliao();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_YDLG_H__F0C20F83_09DA_4333_86DF_BB425E2DA85F__INCLUDED_)
