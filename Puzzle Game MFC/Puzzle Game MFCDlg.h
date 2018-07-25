
// Puzzle Game MFCDlg.h : header file
//

#pragma once
#include "PuzzlePictureControl.h"
#include "GameConfiguration.h"
#include "PuzzleDetails.h"
#include <vector>
#include <iterator>
// CPuzzleGameMFCDlg dialog
class CPuzzleGameMFCDlg : public CDialogEx
{
// Construction
public:
	CPuzzleGameMFCDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PUZZLEGAMEMFC_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedPrevious();
	afx_msg void OnBnClickedButtonNext();
	void ShowPicture(int indicator);

protected:
	CPuzzlePictureControl m_puzzlePicture;
	CGameConfiguration m_gameConfiguration;
public:
	std::vector<CPuzzleDetails> puzzle_details;
	int indexOfPicture = 0;
	int grid = 0;
	//std::list<CPuzzleDetails>::iterator it;
	
public:
	afx_msg void OnBnClickedRadioEasy();
	afx_msg void OnStnClickedPuzzlePicture();
	afx_msg void OnStnEnablePuzzlePicture();
	afx_msg void OnBnClickedOk();
};
