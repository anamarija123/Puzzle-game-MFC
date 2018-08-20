
// ChildView.h : interface of the CChildView class
//



#include "GameAbout.h"
#include "PictureSetUp.h"
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

	void OnGetMinMaxInfo(MINMAXINFO * lpMMI);

// Implementation
public:
	virtual ~CChildView();

	// Generated message map functions
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void newGameSetUp();
	CSetGameDialog m_setUpDialog;
	CGameAbout m_start;
	CPictureSetUp setGrid;
	void start();
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);
};

