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

}

CSetGameDialog::~CSetGameDialog()
{
}

void CSetGameDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSetGameDialog, CDialogEx)
END_MESSAGE_MAP()


// CSetGameDialog message handlers
