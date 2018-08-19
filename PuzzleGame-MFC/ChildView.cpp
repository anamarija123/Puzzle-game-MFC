
// ChildView.cpp : implementation of the CChildView class
//

#include "stdafx.h"
#include "PuzzleGame-MFC.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
  

// CChildView

CChildView::CChildView()
{

}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_COMMAND(ID_FILE_NEW, &CChildView::newGameSetUp)
END_MESSAGE_MAP()



// CChildView message handlers

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(nullptr, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), nullptr);

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	
	// Do not call CWnd::OnPaint() for painting messages
}



void CChildView::newGameSetUp()
{
	// TODO: Add your command handler code here ne kuzim u cem je stvar, nigdje ih ne pozivamo
	//kod mene imaju neke stvari ali ne kuzim sta se desavba
	m_start.start();
}

void CChildView::start()
{
	m_start.start();
}

BOOL CChildView::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext)
{
	// TODO: Add your specialized code here and/or call the base class
	start();
	return CWnd::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
}
