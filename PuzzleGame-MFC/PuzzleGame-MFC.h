
// PuzzleGame-MFC.h : main header file for the PuzzleGame-MFC application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols

// CPuzzleGameMFCApp:
// See PuzzleGame-MFC.cpp for the implementation of this class
//

class CPuzzleGameMFCApp : public CWinApp
{
public:
	CPuzzleGameMFCApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CPuzzleGameMFCApp theApp;
