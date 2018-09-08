#include "stdafx.h"
#include "GameIntro.h"

CGameIntro::CGameIntro() : x(0), y(0)
{
}


CGameIntro::~CGameIntro()
{
}

/*
start function call other functions to load from ini file or dialog.
*/
void CGameIntro::start()
{
	SetParametarsLoadedFromIniFile();
	SetParametarsLoadedFromDialog();
}
/*
SetParametarsLoadedFromIniFile function call functions for loading from ini
*/
void CGameIntro::SetParametarsLoadedFromIniFile()
{
	m_gameConfiguration.checkCollection();
	m_gameConfiguration.GetPuzzleDetails('1');
	m_gameConfiguration.GetPuzzleDetails('2');
	m_gameConfiguration.GetPuzzleDetails('3');
}

/*
SetParametarsLoadedFromDialog function call functions for setting game from user input in dialog
*/
void CGameIntro::SetParametarsLoadedFromDialog()
{	
	m_gameConfiguration.GetGridDetails();
	m_dialogParameters.setPuzzleDetails(m_gameConfiguration);
	x = m_gameConfiguration.gridDetailsCollection[0].GetXSize();
	y = m_gameConfiguration.gridDetailsCollection[0].GetYSize();
	m_dialogParameters.Y = y;
	m_dialogParameters.X = x;
	
	m_dialogParameters.DoModal();
	
	
	x = m_dialogParameters.X;
	y = m_dialogParameters.Y;
	m_gameConfiguration.SetGridDetails(x, y);
	m_wchImagePath = m_dialogParameters.GetPictureForGame();
}

/*
SetParametersForGame function call functions and give them loaded parameters
*/
void CGameIntro::SetParametersForGame(HDC hDC)
{
	bool pictureOpened = m_setupGame.LoadBitmapPicture(hDC,m_wchImagePath);
	if (pictureOpened == true)
	{
		m_setupGame.initializeParameters(x, y);
	}
	
	ShufflePieces();
}

/*
ShufflePieces function call function for shuffle.
*/
void CGameIntro::ShufflePieces()
{
	m_setupGame.Shuffle();
}

/*
SetPictureForGame function call function to draw on board.
@param hDC a handle to the destination device context.
*/
void CGameIntro::SetPictureForGame(HDC hDC)
{
	m_setupGame.DrawPieces(hDC);
}
