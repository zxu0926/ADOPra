#if !defined(AFX_QUERYDLG_H__5D121E9A_AC0F_4D06_BD0E_4A1CEFD3D513__INCLUDED_)
#define AFX_QUERYDLG_H__5D121E9A_AC0F_4D06_BD0E_4A1CEFD3D513__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// QueryDlg.h : header file
//
#include "ADOPraDlg.h"
/////////////////////////////////////////////////////////////////////////////
// CQueryDlg dialog

class CQueryDlg : public CDialog
{
// Construction
public:
	CQueryDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CQueryDlg)
	enum { IDD = IDD_QUERY_DLG };
	CListCtrl	m_QueryList;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CQueryDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CQueryDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnBeginQuery();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CADOPraDlg *m_pADOPraDlg;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_QUERYDLG_H__5D121E9A_AC0F_4D06_BD0E_4A1CEFD3D513__INCLUDED_)
