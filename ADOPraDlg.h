// ADOPraDlg.h : header file
//

#if !defined(AFX_ADOPRADLG_H__07A4D515_8232_4D6F_BC2A_C4F8971578EA__INCLUDED_)
#define AFX_ADOPRADLG_H__07A4D515_8232_4D6F_BC2A_C4F8971578EA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CADOPraDlg dialog

class CADOPraDlg : public CDialog
{
// Construction
public:
	CADOPraDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CADOPraDlg)
	enum { IDD = IDD_ADOPRA_DIALOG };
	CListCtrl	m_ListCtrl;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CADOPraDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CADOPraDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnDelete();
	afx_msg void OnAdd();
	afx_msg void OnModify();
	afx_msg void OnQuery();
	afx_msg void OnReflush();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	_ConnectionPtr m_ConnectionPtr;
	void ShowData(_RecordsetPtr RePtr);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADOPRADLG_H__07A4D515_8232_4D6F_BC2A_C4F8971578EA__INCLUDED_)
