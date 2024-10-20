#if !defined(AFX_ADDRECORDDLG_H__CD4D0218_DC3D_44AC_B082_E1F9FE79F9EE__INCLUDED_)
#define AFX_ADDRECORDDLG_H__CD4D0218_DC3D_44AC_B082_E1F9FE79F9EE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AddRecordDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAddRecordDlg dialog

class CAddRecordDlg : public CDialog
{
// Construction
public:
	CAddRecordDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAddRecordDlg)
	enum { IDD = IDD_ADD_RE_DLG };
	CString	m_Id;
	CString	m_In_Out;
	CString	m_Person;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAddRecordDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAddRecordDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	CTime m_CurTime;
	BOOL m_Flag; //指示为添加或删除标志
	CString m_StrTime;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADDRECORDDLG_H__CD4D0218_DC3D_44AC_B082_E1F9FE79F9EE__INCLUDED_)
