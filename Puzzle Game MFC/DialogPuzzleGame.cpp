// DialogPuzzleGame.cpp : implementation file
//

#include "stdafx.h"
#include "Puzzle Game MFC.h"
#include "DialogPuzzleGame.h"
#include "Puzzle Game MFCDlg.h"
#include "afxdialogex.h"


// CDialogPuzzleGame dialog

IMPLEMENT_DYNAMIC(CDialogPuzzleGame, CDialogEx)

CDialogPuzzleGame::CDialogPuzzleGame(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_GAME_PLAY, pParent)
{

}

CDialogPuzzleGame::~CDialogPuzzleGame()
{
}

void CDialogPuzzleGame::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDialogPuzzleGame, CDialogEx)
END_MESSAGE_MAP()

BOOL CDialogPuzzleGame::OnInitDialog()
{


	return true;
}

// CDialogPuzzleGame message handlers
