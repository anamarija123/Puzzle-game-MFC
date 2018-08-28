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
	, X(0)
	, Y(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

CSetGameDialog::~CSetGameDialog()
{
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
void CSetGameDialog::setPuzzleDetails(CGameConfiguration gameConfiguration)
{
	m_gameConfiguration = gameConfiguration;
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
	UpdateData();
	CDialogEx::OnOK();
}


void CSetGameDialog::OnBnClickedCancel()
{
	PostQuitMessage(0);
	CDialogEx::OnCancel();
}

wstring CSetGameDialog::GetPictureForGame()
{
	return m_gameConfiguration.puzzleDetailsCollection[indexOfPicture].GetGameImagePath().c_str();
}