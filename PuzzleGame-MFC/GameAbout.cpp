#include "stdafx.h"
#include "GameAbout.h"

void CGameAbout::start()
{
	
	
	SetParametarsInit();
}
CGameAbout::CGameAbout()
{
}


CGameAbout::~CGameAbout()
{
}
void CGameAbout::SetParametarsInit()
{
	m_gameConfiguration.GetGridDetails();
	m_gameConfiguration.GetPuzzleDetails(1);
	m_gameConfiguration.GetPuzzleDetails(2);
	m_gameConfiguration.GetPuzzleDetails(3);
	setDialogParameters.setPuzzleDetails(m_gameConfiguration);
	x = m_gameConfiguration.gridDetailsCollection[0].GetXSize();
	y = m_gameConfiguration.gridDetailsCollection[0].GetYSize();
	setDialogParameters.Y = y;
	setDialogParameters.X = x;
	
	setDialogParameters.DoModal();
	
	
	x = setDialogParameters.X;
	y = setDialogParameters.Y;
	m_gameConfiguration.SetGridDetails(x, y);
	imagePath = setDialogParameters.GetPictureForGame();
	
}

void CGameAbout::SetGridAndPicture(HDC hDC,CPaintDC* dc, RECT rect, HWND hwnd)
{
	bool pictureOpened = setup.LoadBitmapPicture(hDC,imagePath.c_str());
	if (pictureOpened == true)
	{
		setup.init(x, y, imagePath);
	}
	setup.Shuffle();
//	setup.ShowPicture(hDC);
	setup.DrawGrid(dc, rect, hwnd, hDC);
//	setup.DrawPieces(hwnd,hDC);
}
