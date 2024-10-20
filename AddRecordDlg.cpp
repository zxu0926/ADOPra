// AddRecordDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ADOPra.h"
#include "AddRecordDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAddRecordDlg dialog


CAddRecordDlg::CAddRecordDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAddRecordDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAddRecordDlg)
	m_Id = _T("");
	m_In_Out = _T("");
	m_Person = _T("");
	m_Flag=FALSE;
	m_StrTime=_T("");
	//}}AFX_DATA_INIT
}


void CAddRecordDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAddRecordDlg)
	DDX_Text(pDX, IDC_ID, m_Id);
	DDX_Text(pDX, IDC_IN_OUT, m_In_Out);
	DDX_Text(pDX, IDC_PERSON, m_Person);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAddRecordDlg, CDialog)
	//{{AFX_MSG_MAP(CAddRecordDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAddRecordDlg message handlers

BOOL CAddRecordDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	if (m_Flag==FALSE)
	{
		m_CurTime=CTime::GetCurrentTime();
		CString str=m_CurTime.Format(_T("%Y-%m-%d %H:%M:%S"));
		GetDlgItem(IDC_IO_TIME)->SetWindowText(str);
	}
	else
	{
		SetWindowText(_T("ÐÞ¸Ä¼ÇÂ¼"));
		GetDlgItem(IDOK)->SetWindowText(_T("ÐÞ¸Ä"));
		GetDlgItem(IDC_ID)->EnableWindow(FALSE);
		GetDlgItem(IDC_IO_TIME)->SetWindowText(m_StrTime);
	}
	//
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
