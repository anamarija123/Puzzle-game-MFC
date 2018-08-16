
// ChildView.h : interface of the CChildView class
//


#include "SetGameDialog.h"
// CChildView window

class CChildView : public CWnd
{
// Construction
public:
	CChildView();

// Attributes
public:

// Operations
public:

// Overrides
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Implementation
public:
	virtual ~CChildView();

	// Generated message map functions
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void newGameSetUp();
	CSetGameDialog GameSetUp;
	bool LoadAndBlitBitmap(LPCWSTR szFileName, HDC HwINDdC);
};

