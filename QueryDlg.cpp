// QueryDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ADOPra.h"
#include "QueryDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CQueryDlg dialog


CQueryDlg::CQueryDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CQueryDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CQueryDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_pADOPraDlg=(CADOPraDlg *)pParent;
}


void CQueryDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CQueryDlg)
	DDX_Control(pDX, IDC_LIST1, m_QueryList);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CQueryDlg, CDialog)
	//{{AFX_MSG_MAP(CQueryDlg)
	ON_BN_CLICKED(IDC_BEGIN_QUERY, OnBeginQuery)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CQueryDlg message handlers

BOOL CQueryDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_QueryList.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
	m_QueryList.InsertColumn(0,"ID",LVCFMT_LEFT,80);
	m_QueryList.InsertColumn(1,"PERSON",LVCFMT_LEFT,100);
	m_QueryList.InsertColumn(2,"IN_OUT",LVCFMT_LEFT,80);
	m_QueryList.InsertColumn(3,"IO_TIME",LVCFMT_LEFT,160);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CQueryDlg::OnBeginQuery() 
{
	// TODO: Add your control notification handler code here
	CString Str,Sql;
	_variant_t VarID,VarPerson,VarINOut,VarIOTime;
	int i=0;
	int Len=GetDlgItem(IDC_EDIT1)->GetWindowTextLength();
	if (Len==0)
	{
		MessageBox(_T("请输入查询条件（员工号）"),_T("提示"),MB_OK | MB_ICONINFORMATION);
		return;
	}
	GetDlgItem(IDC_EDIT1)->GetWindowText(Str);
    
	Sql=_T("select * from ATTENDANCE where PERSON = '") + Str + "'";
	
	_RecordsetPtr RePtr;
	RePtr.CreateInstance(__uuidof(Recordset));
	RePtr->Open(_variant_t(Sql),m_pADOPraDlg->m_ConnectionPtr.GetInterfacePtr( ),adOpenDynamic,adLockOptimistic,adCmdText);
	
	while (!RePtr->adoEOF)
	{
		m_QueryList.InsertItem(i," ");
		VarID=RePtr->GetCollect(_variant_t(_T("ID")));
		VarPerson=RePtr->GetCollect(_variant_t("PERSON"));
		VarINOut=RePtr->GetCollect(_variant_t("IN_OUT"));
		VarIOTime=RePtr->GetCollect(_variant_t("IO_TIME"));
		//
		m_QueryList.SetItemText(i,0,(LPCSTR)(_bstr_t)VarID);
		m_QueryList.SetItemText(i,1,(LPCSTR)(_bstr_t)VarPerson);
		m_QueryList.SetItemText(i,2,(LPCSTR)(_bstr_t)VarINOut);
		m_QueryList.SetItemText(i,3,(LPCSTR)(_bstr_t)VarIOTime);
		//
		RePtr->MoveNext();
		i++;
	}
	RePtr->Close();
}
