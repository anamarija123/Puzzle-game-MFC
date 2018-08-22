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
	wstring imagePath = setDialogParameters.GetPictureForGame();
	bool pictureOpened = setup.LoadBitmapPicture(imagePath.c_str());
	if (pictureOpened == true)
	{
		setup.init(x, y, imagePath);
	}


}

void CGameAbout::SetGridAndPicture(CPaintDC* dc, RECT rect, HWND hwnd)
{
	setup.DrawGrid(dc, rect, hwnd);	
	setup.DrawPicture();
}
