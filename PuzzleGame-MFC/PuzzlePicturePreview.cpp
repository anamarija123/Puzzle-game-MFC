// PuzzlePicturePreview.cpp : implementation file
//

#include "stdafx.h"
#include "PuzzleGame-MFC.h"
#include "PuzzlePicturePreview.h"
#include "afxdialogex.h"
#include "PuzzleGameView.h"

// CPuzzlePicturePreview dialog

IMPLEMENT_DYNAMIC(CPuzzlePicturePreview, CDialogEx)

CPuzzlePicturePreview::CPuzzlePicturePreview(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG2, pParent)
{

}

CPuzzlePicturePreview::~CPuzzlePicturePreview()
{
}

void CPuzzlePicturePreview::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CPuzzlePicturePreview, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CPuzzlePicturePreview message handlers

void CPuzzlePicturePreview::SetPicturePreview(std::wstring pictureInfo)
{
	m_picturePath = pictureInfo;
}

void CPuzzlePicturePreview::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: Add your message handler code here
					   // Do not call CDialogEx::OnPaint() for painting messages
}

BOOL CPuzzlePicturePreview::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	ShowPicture();
	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}

/*
ShowPicture function show whole picture 
*/
void CPuzzlePicturePreview::ShowPicture()//picture_index
{
	m_picture = (CStatic*)GetDlgItem(IDC_STATIC);
	HBITMAP EntityImage = (HBITMAP)LoadImage(
		NULL,
		m_picturePath.c_str(),
		IMAGE_BITMAP,
		600, 350,
		LR_LOADFROMFILE);
	m_picture->SetBitmap(EntityImage);

}