; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CQueryDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "ADOPra.h"

ClassCount=5
Class1=CADOPraApp
Class2=CADOPraDlg
Class3=CAboutDlg

ResourceCount=5
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_ADD_RE_DLG
Class4=CAddRecordDlg
Resource4=IDD_ADOPRA_DIALOG
Class5=CQueryDlg
Resource5=IDD_QUERY_DLG

[CLS:CADOPraApp]
Type=0
HeaderFile=ADOPra.h
ImplementationFile=ADOPra.cpp
Filter=N

[CLS:CADOPraDlg]
Type=0
HeaderFile=ADOPraDlg.h
ImplementationFile=ADOPraDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_LIST1

[CLS:CAboutDlg]
Type=0
HeaderFile=ADOPraDlg.h
ImplementationFile=ADOPraDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_ADOPRA_DIALOG]
Type=1
Class=CADOPraDlg
ControlCount=8
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_LIST1,SysListView32,1350631425
Control4=IDC_DELETE,button,1342242816
Control5=IDC_ADD,button,1342242816
Control6=IDC_REFLUSH,button,1342242816
Control7=IDC_Modify,button,1342242816
Control8=IDC_QUERY,button,1342242816

[DLG:IDD_ADD_RE_DLG]
Type=1
Class=CAddRecordDlg
ControlCount=10
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_ID,edit,1350631552
Control4=IDC_PERSON,edit,1350631552
Control5=IDC_IN_OUT,edit,1350631552
Control6=IDC_IO_TIME,edit,1484849280
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC,static,1342308352
Control10=IDC_STATIC,static,1342308352

[CLS:CAddRecordDlg]
Type=0
HeaderFile=AddRecordDlg.h
ImplementationFile=AddRecordDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC

[DLG:IDD_QUERY_DLG]
Type=1
Class=CQueryDlg
ControlCount=6
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_EDIT1,edit,1350631552
Control5=IDC_BEGIN_QUERY,button,1342242816
Control6=IDC_LIST1,SysListView32,1350631425

[CLS:CQueryDlg]
Type=0
HeaderFile=QueryDlg.h
ImplementationFile=QueryDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC

