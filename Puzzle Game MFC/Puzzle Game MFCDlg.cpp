
// Puzzle Game MFCDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Puzzle Game MFC.h"
#include "Puzzle Game MFCDlg.h"
#include "afxdialogex.h"
#include "PuzzlePictureControl.h"
#include "GameConfiguration.h"
#include <list>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPuzzleGameMFCDlg dialog

enum initialization {
	puzzle1 = 1,
	puzzle2 = 2,
	puzzle3 = 3,
	timer = 1
} ID;

CPuzzleGameMFCDlg::CPuzzleGameMFCDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PUZZLEGAMEMFC_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPuzzleGameMFCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PUZZLE_PICTURE, m_puzzlePicture);
}

BEGIN_MESSAGE_MAP(CPuzzleGameMFCDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_PREVIOUS, &CPuzzleGameMFCDlg::OnBnClickedPrevious)
	ON_BN_CLICKED(IDC_BUTTON_NEXT, &CPuzzleGameMFCDlg::OnBnClickedButtonNext)
	ON_BN_CLICKED(IDC_RADIO_EASY, &CPuzzleGameMFCDlg::OnBnClickedRadioEasy)
	ON_STN_CLICKED(IDC_PUZZLE_PICTURE, &CPuzzleGameMFCDlg::OnStnClickedPuzzlePicture)
	ON_STN_ENABLE(IDC_PUZZLE_PICTURE, &CPuzzleGameMFCDlg::OnStnEnablePuzzlePicture)
END_MESSAGE_MAP()


// CPuzzleGameMFCDlg message handlers

BOOL CPuzzleGameMFCDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	CPuzzleDetails first_puzzle= m_gameConfiguration.GetPuzzleDetails(ID = puzzle1);
	puzzle_details.push_back(first_puzzle);
	CPuzzleDetails second_puzzle = m_gameConfiguration.GetPuzzleDetails(ID = puzzle2);
	puzzle_details.push_back(second_puzzle);
	CPuzzleDetails third_puzzle = m_gameConfiguration.GetPuzzleDetails(ID = puzzle3);
	puzzle_details.push_back(third_puzzle);
	CTimerDetails timer_ = m_gameConfiguration.GetTimerDetails(ID = timer);

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
//	mnrsto(puzzleDetails.GetGameImagePath());
	
	//m_puzzlePicture.ChangePicture((LPCTSTR)puzzleDetails1.GetPreviewImagePath());

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CPuzzleGameMFCDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CPuzzleGameMFCDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CPuzzleGameMFCDlg::OnBnClickedPrevious()
{
	// TODO: Add your control notification handler code here
}


void CPuzzleGameMFCDlg::OnBnClickedButtonNext()
{
	// TODO: Add your control notification handler code here
	//m_puzzlePicture.ChangePicture(_T(".\\smallLandscape1.bmp"));
	picture_indicator++;
	if(picture_indicator <= puzzle_details.size()-1)
	{ 
	ShowPicture(picture_indicator);
	}
	else
	{
		return;
	}
}


void CPuzzleGameMFCDlg::OnBnClickedRadioEasy()
{
	// TODO: Add your control notification handler code here
}


void CPuzzleGameMFCDlg::OnStnClickedPuzzlePicture()
{
	// TODO: Add your control notification handler code here
	ShowPicture(picture_indicator);
	
}

void CPuzzleGameMFCDlg::ShowPicture(int indicator)
{
	//it = puzzle_details.begin();
	//m_puzzlePicture.ChangePicture();
	m_puzzlePicture.ChangePicture((LPCTSTR)puzzle_details[indicator].GetPreviewImagePath());
	
}

void CPuzzleGameMFCDlg::OnStnEnablePuzzlePicture()
{
	// TODO: Add your control notification handler code here

}
