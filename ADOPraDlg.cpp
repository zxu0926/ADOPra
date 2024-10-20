// ADOPraDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ADOPra.h"
#include "ADOPraDlg.h"
#include "AddRecordDlg.h"
#include "QueryDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CADOPraDlg dialog

CADOPraDlg::CADOPraDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CADOPraDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CADOPraDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CADOPraDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CADOPraDlg)
	DDX_Control(pDX, IDC_LIST1, m_ListCtrl);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CADOPraDlg, CDialog)
	//{{AFX_MSG_MAP(CADOPraDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_DELETE, OnDelete)
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_BN_CLICKED(IDC_Modify, OnModify)
	ON_BN_CLICKED(IDC_QUERY, OnQuery)
	ON_BN_CLICKED(IDC_REFLUSH, OnReflush)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CADOPraDlg message handlers

BOOL CADOPraDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	m_ListCtrl.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
	m_ListCtrl.InsertColumn(0,"ID",LVCFMT_LEFT,80);
	m_ListCtrl.InsertColumn(1,"PERSON",LVCFMT_LEFT,100);
	m_ListCtrl.InsertColumn(2,"IN_OUT",LVCFMT_LEFT,80);
	m_ListCtrl.InsertColumn(3,"IO_TIME",LVCFMT_LEFT,160);
	//
	HRESULT hr=m_ConnectionPtr.CreateInstance(__uuidof(Connection));
	if(SUCCEEDED(hr)) 
	{
 		CString CurDir;
 		TCHAR DirPath[260];
 		GetCurrentDirectory(sizeof(DirPath),DirPath);
 		CurDir=DirPath;
 		CString ConnectStr="Provider=Microsoft.Jet.OLEDB.4.0;Data Source=" + CurDir + "\\Misdb.mdb";
 		m_ConnectionPtr->Open((LPCTSTR)ConnectStr,"","",adModeUnknown);
		///*hr = */m_ConnectionPtr->Open("Provider=Microsoft.Jet.OLEDB.4.0;Data Source=D:\\vc\\vc6.0\\Misdb.mdb","","",adModeUnknown);
		
	}
    //
	_RecordsetPtr RePtr;
	RePtr.CreateInstance(__uuidof(Recordset));
	RePtr->Open(_variant_t("select * from ATTENDANCE"),m_ConnectionPtr.GetInterfacePtr( ),adOpenDynamic,adLockOptimistic,adCmdText);
	ShowData(RePtr);
	//
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CADOPraDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CADOPraDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CADOPraDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CADOPraDlg::ShowData(_RecordsetPtr RePtr)
{
	_variant_t VarID,VarPERSON,VarIN_OUT,VarIO_TIME;
	m_ListCtrl.DeleteAllItems();
	int i=0;
	while (!RePtr->adoEOF)
	{
		m_ListCtrl.InsertItem(i,_T(""));
		VarID=RePtr->GetCollect(_variant_t(_T("ID")));
		VarPERSON=RePtr->GetCollect(_variant_t(_T("PERSON")));
		VarIN_OUT=RePtr->GetCollect(_variant_t(_T("IN_OUT")));
		VarIO_TIME=RePtr->GetCollect(_variant_t(_T("IO_TIME")));
		//
		m_ListCtrl.SetItemText(i,0,(LPCSTR)(_bstr_t)VarID);
		m_ListCtrl.SetItemText(i,1,(LPCSTR)(_bstr_t)VarPERSON);
		m_ListCtrl.SetItemText(i,2,(LPCSTR)(_bstr_t)VarIN_OUT);
		m_ListCtrl.SetItemText(i,3,(LPCSTR)(_bstr_t)VarIO_TIME);
		//
		RePtr->MoveNext();
		i++;
	}
	RePtr->Close();
}

void CADOPraDlg::OnAdd() 
{
	// TODO: Add your control notification handler code here
	CAddRecordDlg Dlg;
	if (Dlg.DoModal()==IDCANCEL)
	{
		return;
	}
	//add data
	_RecordsetPtr RePtr;
	_variant_t VarIO_TIME;
	SYSTEMTIME SystemTime;
	double Time;
	
	RePtr.CreateInstance(__uuidof(Recordset));
	RePtr->Open(_variant_t("select * from ATTENDANCE"),m_ConnectionPtr.GetInterfacePtr( ),adOpenDynamic,adLockOptimistic,adCmdText);
	/*RePtr->MoveLast();*/
	// 	try
	// 	{
	RePtr->AddNew();
	RePtr->PutCollect(_T("ID"),_variant_t(Dlg.m_Id));
	RePtr->PutCollect(_T("PERSON"), _variant_t(Dlg.m_Person));
	RePtr->PutCollect(_T("IN_OUT"), _variant_t(Dlg.m_In_Out));
	
	//增加时间参数
	Dlg.m_CurTime.GetAsSystemTime(SystemTime);
	SystemTimeToVariantTime(&SystemTime,&Time);
	/*_variant_t VarIO_TIME(Time,VT_DATE);;*/          //另一种赋值方法
	VarIO_TIME.ChangeType(VT_DATE);
	VarIO_TIME.dblVal=Time;
	RePtr->PutCollect(_T("IO_TIME"), /*_variant_t(Dlg.m_In_Out)*/VarIO_TIME);
	// 	}
	// 	catch (_com_error e)
	// 	{
	// 		AfxMessageBox(e.ErrorMessage());
	// 	}
	
	RePtr->Update();
	RePtr->MoveFirst();
	ShowData(RePtr);
}

void CADOPraDlg::OnDelete() 
{
	// TODO: Add your control notification handler code here
	//****************************第一种删除方式，利用_CommandPtr进行删除 
	// 	int Index;
	// 	CString Sql;
	// 	POSITION pos=m_ListCtrl.GetFirstSelectedItemPosition();
	// 	if (pos==NULL)
	// 	{
	// 		return;
	// 	}
	// 	Index=m_ListCtrl.GetNextSelectedItem(pos);
	// 	Sql="delete * from ATTENDANCE where ID="+m_ListCtrl.GetItemText(Index,0);
	//     
	// 	//
	// 	_CommandPtr CmdPtr;
	//     CmdPtr.CreateInstance(__uuidof(Command)/*"ADODB.Command"*/);
	// 	CmdPtr->ActiveConnection=m_ConnectionPtr;
	// 	CmdPtr->CommandText=(_bstr_t)(LPCTSTR)Sql;
	// 	CmdPtr->CommandType=adCmdText;
	// 	CmdPtr->Parameters->Refresh();
	// 
	// 	CmdPtr->Execute(NULL,NULL,adCmdUnknown);
	// 
	// 	//重新显示列表
	// 	_RecordsetPtr RePtr;
	// 	RePtr.CreateInstance(__uuidof(Recordset));
	// 	RePtr->Open(_variant_t("select * from ATTENDANCE"),m_ConnectionPtr.GetInterfacePtr( ),adOpenDynamic,adLockOptimistic,adCmdText);
	// 	ShowData(RePtr); 
	
	
	//第二种删除方式
	int Index;
	CString Sql;
	POSITION pos=m_ListCtrl.GetFirstSelectedItemPosition();
	if (pos==NULL)
	{
		return;
	}
	Index=m_ListCtrl.GetNextSelectedItem(pos);
	Sql="select * from ATTENDANCE where ID="+m_ListCtrl.GetItemText(Index,0);
	_RecordsetPtr RePtr;
	_variant_t VarSql;
	VarSql.SetString(Sql);
	RePtr.CreateInstance(__uuidof(Recordset));
	try
	{
		RePtr->Open(VarSql,m_ConnectionPtr.GetInterfacePtr( ),adOpenDynamic,adLockOptimistic,adCmdText);
		RePtr->Delete(adAffectCurrent);
	}
	catch (_com_error e)
	{
		AfxMessageBox(e.ErrorMessage());
	}
	RePtr->Update();
	RePtr->Close();
	RePtr->Open(_variant_t("select * from ATTENDANCE"),m_ConnectionPtr.GetInterfacePtr( ),adOpenDynamic,adLockOptimistic,adCmdText);
	ShowData(RePtr);
}

void CADOPraDlg::OnModify() 
{
	// TODO: Add your control notification handler code here
	CString Sql,Time,Temp;
	//get selected item index
	POSITION pos=m_ListCtrl.GetFirstSelectedItemPosition();
	if (pos == NULL)
	{
		return;
	}
	int Index=m_ListCtrl.GetNextSelectedItem(pos);
	//
    CAddRecordDlg ChangeDlg;
	ChangeDlg.m_Flag=TRUE;

	ChangeDlg.m_Id=m_ListCtrl.GetItemText(Index,0);
	ChangeDlg.m_Person=m_ListCtrl.GetItemText(Index,1);
	ChangeDlg.m_In_Out=m_ListCtrl.GetItemText(Index,2);
	ChangeDlg.m_StrTime=m_ListCtrl.GetItemText(Index,3);

	if (ChangeDlg.DoModal()==IDOK)
	{
		_RecordsetPtr RePtr;
		_variant_t  VarINOut,VarIOTime;
		_variant_t VarID;
        
		Sql=_T("select * from ATTENDANCE where ID=") + ChangeDlg.m_Id;
		RePtr.CreateInstance(__uuidof(Recordset));
		RePtr->Open(_variant_t(Sql),m_ConnectionPtr.GetInterfacePtr( ),adOpenDynamic,adLockOptimistic,adCmdText);
		/*RePtr->PutCollect(_variant_t(ChangeDlg.m_Person),_variant_t(_T("PERSON")));
		RePtr->PutCollect(_variant_t(ChangeDlg.m_In_Out),_variant_t(_T("IN_OUT")));*/
		RePtr->PutCollect(_variant_t(_T("PERSON")),_variant_t(ChangeDlg.m_Person));
		RePtr->PutCollect(_variant_t(_T("IN_OUT")),_variant_t(ChangeDlg.m_In_Out));
		RePtr->Update();
		RePtr->Close();
		RePtr->Open(_variant_t(_T("select * from ATTENDANCE")),m_ConnectionPtr.GetInterfacePtr( ),adOpenDynamic,adLockOptimistic,adCmdText);
		ShowData(RePtr);
	}
}

void CADOPraDlg::OnQuery() 
{
	// TODO: Add your control notification handler code here
	CQueryDlg Dlg(this);
	Dlg.DoModal();
}

void CADOPraDlg::OnReflush() 
{
	// TODO: Add your control notification handler code here
	_RecordsetPtr RePtr;
	RePtr.CreateInstance(__uuidof(Recordset));
	RePtr->Open(_variant_t("select * from ATTENDANCE"),m_ConnectionPtr.GetInterfacePtr( ),adOpenDynamic,adLockOptimistic,adCmdText);
	ShowData(RePtr);
}
