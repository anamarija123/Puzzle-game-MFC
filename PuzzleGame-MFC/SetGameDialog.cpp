// SetGameDialog.cpp : implementation file
//

#include "stdafx.h"
#include "PuzzleGame-MFC.h"
#include "SetGameDialog.h"
#include "afxdialogex.h"


// CSetGameDialog dialog

IMPLEMENT_DYNAMIC(CSetGameDialog, CDialogEx)

CSetGameDialog::CSetGameDialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

CSetGameDialog::~CSetGameDialog()
{
}

void CSetGameDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSetGameDialog, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_PREVIOUS, &CSetGameDialog::OnBnClickedButtonPrevious)
	ON_BN_CLICKED(IDC_RADIO_EASY, &CSetGameDialog::OnBnClickedRadioEasy)
	ON_BN_CLICKED(IDC_RADIO_HARD, &CSetGameDialog::OnBnClickedRadioHard)
	ON_BN_CLICKED(IDC_RADIO_MEDIUM, &CSetGameDialog::OnBnClickedRadioMedium)
	ON_BN_CLICKED(IDC_BUTTON_NEXT, &CSetGameDialog::OnClickedButtonNext)
	ON_BN_CLICKED(IDOK, &CSetGameDialog::OnBnClickedOk)
END_MESSAGE_MAP()

BOOL CSetGameDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	m_gameConfiguration.GetPuzzleDetails(1);
	m_gameConfiguration.GetPuzzleDetails(2);
	m_gameConfiguration.GetPuzzleDetails(3);
	
	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

							
	ShowPicture(indexOfPicture);
	return TRUE;  // return TRUE  unless you set the focus to a control
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



void CSetGameDialog::ShowPicture(int picture_index)//picture_index
{
	m_picture = (CStatic*)GetDlgItem(IDC_PUZZLE_PICTURE);
	HBITMAP EntityImage = (HBITMAP)LoadImage(
		NULL,
		m_gameConfiguration.puzzleDetailsCollection[picture_index].GetPreviewImagePath().c_str(), 
		IMAGE_BITMAP, 
		160, 140,
		LR_LOADFROMFILE);
	m_picture->SetBitmap(EntityImage);

}

void CSetGameDialog::OnBnClickedButtonPrevious()
{
	if (indexOfPicture > 0)
	{
		indexOfPicture--;
		ShowPicture(indexOfPicture);
	}
	else
	{
		return;
	}
}

void CSetGameDialog::OnBnClickedRadioEasy()
{
	gridNumber = 3;
}


void CSetGameDialog::OnBnClickedRadioHard()
{
	gridNumber = 7;
}


void CSetGameDialog::OnBnClickedRadioMedium()
{
	gridNumber = 5;
}


void CSetGameDialog::OnClickedButtonNext()
{
	indexOfPicture++;
	if (indexOfPicture <= m_gameConfiguration.puzzleDetailsCollection.size() - 1)
	{
		ShowPicture(indexOfPicture);
	}
	else
	{
		return;
	}
}


void CSetGameDialog::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}
