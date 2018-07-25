#pragma once
#include "Puzzle Game MFCDlg.h"
// CDialogPuzzleGame dialog

class CDialogPuzzleGame : public CDialogEx
{
	DECLARE_DYNAMIC(CDialogPuzzleGame)

public:
	CDialogPuzzleGame(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CDialogPuzzleGame();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_GAME_PLAY };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CStatic PuzzlePictureControlGame;
	
protected:
	BOOL CDialogPuzzleGame::OnInitDialog();
};
