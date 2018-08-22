
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
	ON_WM_CREATE()
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
	CPaintDC dc(this); 
	
	RECT rc;
	GetClientRect(&rc);
	
	HDC hdc = dc;
	m_start.SetGridAndPicture(hdc,&dc, rc, CWnd::m_hWnd);
	
}
void CChildView::newGameSetUp()
{
	m_start.start();
	indicator = true;
	Invalidate();

}
void CChildView::start()
{
	m_start.start();
	indicator = false;
}

int CChildView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	start();
	// TODO:  Add your specialized creation code here

	return 0;
}
