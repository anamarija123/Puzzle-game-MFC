
// ChildView.h : interface of the CChildView class
//



#include "GameIntro.h"
#include "GameSetUp.h"
#include "PuzzlePicturePreview.h"
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
	int indicator = 0;
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
	CGameIntro m_startGame;
	CPuzzlePicturePreview m_preview;
	std::vector<POINT>clickedPixelCoords;
	void start();
	
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnFileShowpicture();
	afx_msg void OnFileShuffle();
	afx_msg void OnAppExit();

private:
	void initialize();
	void resizeWindow();
	HDC hdc;


};

