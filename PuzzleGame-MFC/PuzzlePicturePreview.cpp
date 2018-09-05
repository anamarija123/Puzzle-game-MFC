// PuzzlePicturePreview.cpp : implementation file
//

#include "stdafx.h"
#include "PuzzleGame-MFC.h"
#include "PuzzlePicturePreview.h"
#include "afxdialogex.h"
#include "PuzzleGameView.h"
#include <string>
// CPuzzlePicturePreview dialog

IMPLEMENT_DYNAMIC(CPuzzlePicturePreview, CDialogEx)

CPuzzlePicturePreview::CPuzzlePicturePreview(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PICTURE_PREVIEW, pParent)
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

void CPuzzlePicturePreview::SetPicturePreview(tstring pictureInfo, int width, int height)
{
	m_widthOfPicture = width;
	m_heightOfPicture = height;
	m_picturePath = pictureInfo;
}

void CPuzzlePicturePreview::OnPaint()
{

	CPaintDC dc(this); // device context for painting
	CRect rect;
	GetClientRect(&rect);

	m_Bmap = (HBITMAP)LoadImage(NULL, m_picturePath.c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	memdc = CreateCompatibleDC(dc.m_hDC);
	SelectObject(memdc, m_Bmap);

	BitBlt(dc.m_hDC, 0, 0, rect.right, rect.bottom, memdc, 0, 0, SRCCOPY);

	DeleteDC(memdc);
	DeleteObject(m_Bmap);
}

BOOL CPuzzlePicturePreview::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	this->SetWindowPos(NULL, 0, 0, m_widthOfPicture, m_heightOfPicture, SWP_NOMOVE | SWP_NOZORDER);

	return TRUE;  			 
}

