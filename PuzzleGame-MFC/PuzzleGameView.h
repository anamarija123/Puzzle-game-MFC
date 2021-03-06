
// ChildView.h : interface of the CChildView class
//



#include "GameIntro.h"
#include "GameSetUp.h"
#include "PuzzlePicturePreview.h"

// CChildView window

class PuzzleGameView : public CWnd
{
// Construction
public:
	PuzzleGameView();

// Attributes
public:

// Operations
public:

// Overrides
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
// Implementation
public:
	virtual ~PuzzleGameView();

	// Generated message map functions
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
	
public:
	afx_msg void newGameSetUp();
	CGameIntro m_startGame;
	CPuzzlePicturePreview m_preview;
	std::vector<POINT>clickedPixelCoords;
	
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnFileShowpicture();
	afx_msg void OnFileShuffle();
	afx_msg void OnAppExit();

private:
	bool ActivateMenu();
	void Initialize();
	void ResizeWindow();

public:
	afx_msg void OnUpdateFileShuffle(CCmdUI *pCmdUI);
	afx_msg void OnUpdateFileShowpicture(CCmdUI *pCmdUI);
	
};

