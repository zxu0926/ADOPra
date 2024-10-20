// ADOPra.h : main header file for the ADOPRA application
//

#if !defined(AFX_ADOPRA_H__EB020A11_E79E_4EFD_A04F_BE0976621CEE__INCLUDED_)
#define AFX_ADOPRA_H__EB020A11_E79E_4EFD_A04F_BE0976621CEE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

#import "C:\\Program Files\\Common Files\\System\\ado\\msado15.dll" no_namespace,rename("EOF","adoEOF")
/////////////////////////////////////////////////////////////////////////////
// CADOPraApp:
// See ADOPra.cpp for the implementation of this class
//

class CADOPraApp : public CWinApp
{
public:
	CADOPraApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CADOPraApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CADOPraApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADOPRA_H__EB020A11_E79E_4EFD_A04F_BE0976621CEE__INCLUDED_)
