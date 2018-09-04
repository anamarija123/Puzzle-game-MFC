// SetGameDialog.cpp : implementation file
//

#include "stdafx.h"
#include "PuzzleGame-MFC.h"
#include "SetGameDialog.h"
#include "afxdialogex.h"
#define START_GAME 1
#define BACK_TO_MAIN_WINDOW 0

// CSetGameDialog dialog

IMPLEMENT_DYNAMIC(CSetGameDialog, CDialogEx)

CSetGameDialog::CSetGameDialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SELECT_PUZZLE, pParent)
	, X(0)
	, Y(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

CSetGameDialog::~CSetGameDialog()
{
	DeleteBitmap();
}

void CSetGameDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Text(pDX, IDC_EDIT1, X);
	DDV_MinMaxUInt(pDX, X, 3, 10);
	DDX_Text(pDX, IDC_EDIT2, Y);
	DDV_MinMaxUInt(pDX, Y, 3, 10);
}


BEGIN_MESSAGE_MAP(CSetGameDialog, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_PREVIOUS, &CSetGameDialog::OnBnClickedButtonPrevious)
	ON_BN_CLICKED(IDC_BUTTON_NEXT, &CSetGameDialog::OnClickedButtonNext)
	ON_BN_CLICKED(IDOK, &CSetGameDialog::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CSetGameDialog::OnBnClickedCancel)
END_MESSAGE_MAP()

BOOL CSetGameDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	
	SetIcon(m_hIcon, TRUE);			
	SetIcon(m_hIcon, FALSE);		
	
	GetDlgItem(IDC_BUTTON_PREVIOUS)->EnableWindow(FALSE);
	indexOfPicture = 0;
	ShowPicture(indexOfPicture);

	return TRUE;  
}
// CSetGameDialog message handlers

void CSetGameDialog::OnPaint()
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

HCURSOR CSetGameDialog::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

/*
setPuzzleDetails setting details about loaded ini file
@param gameConfiguration contains info loaded from ini
*/
void CSetGameDialog::setPuzzleDetails(CGameConfiguration gameConfiguration)
{
	m_gameConfiguration = gameConfiguration;
	numberOfPictures = m_gameConfiguration.puzzleDetailsCollection.size() - 1;
}

/*
ShowPicture show little picture on dialog
@param picture_index index of picture to display
*/
void CSetGameDialog::ShowPicture(int picture_index)
{
	m_picture = (CStatic*)GetDlgItem(IDC_PUZZLE_PICTURE);
	EntityImage = (HBITMAP)LoadImage(
		NULL,
		m_gameConfiguration.puzzleDetailsCollection[picture_index].GetPreviewImagePath(), 
		IMAGE_BITMAP, 
		160, 140,
		LR_LOADFROMFILE);
	m_picture->SetBitmap(EntityImage);


}

void CSetGameDialog::OnBnClickedButtonPrevious()
{
	if (indexOfPicture > 0)
	{
		GetDlgItem(IDC_BUTTON_NEXT)->EnableWindow(TRUE);
		indexOfPicture--;
		ShowPicture(indexOfPicture);
	}
	
	if (indexOfPicture == 0)
	{
		GetDlgItem(IDC_BUTTON_PREVIOUS)->EnableWindow(FALSE);
	}
}



void CSetGameDialog::OnClickedButtonNext()
{
	indexOfPicture ++;
	if (indexOfPicture < numberOfPictures)
	{
		GetDlgItem(IDC_BUTTON_PREVIOUS)->EnableWindow(TRUE);
		ShowPicture(indexOfPicture);		
	}
	if (indexOfPicture == numberOfPictures)
	{
		ShowPicture(indexOfPicture);
		GetDlgItem(IDC_BUTTON_NEXT)->EnableWindow(FALSE);
	}
}


void CSetGameDialog::OnBnClickedOk()
{
	indicatorToPlay = TRUE;//START GAME
	indicatorToShowMainScreen = FALSE;
	DeleteBitmap();
	UpdateData();
	CDialogEx::OnOK();
}


void CSetGameDialog::OnBnClickedCancel()
{
	indicatorToShowMainScreen = TRUE;//BACK TO MAIN
	indicatorToPlay = FALSE;
	DeleteBitmap();
	UpdateData();
	CDialogEx::OnCancel();
}
/*
GetPictureForGame returns chosen picture for game
*/
const TCHAR* CSetGameDialog::GetPictureForGame()
{
	return m_gameConfiguration.puzzleDetailsCollection[indexOfPicture].GetGameImagePath();
}

void CSetGameDialog::DeleteBitmap()
{
	DeleteObject(EntityImage);
}