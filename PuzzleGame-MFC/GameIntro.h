#pragma once

#include "GridDetails.h"
#include "SetGameDialog.h"
#include "GameConfiguration.h"
#include "GameSetUp.h"

class CGameIntro
{
private:
	int x;
	int y;
public:
	CGameIntro();
	~CGameIntro();
	void SetParametarsLoadedFromDialog();
	void SetParametarsLoadedFromIniFile();
	void SetPictureForGame(HDC hDC);
	void SetParametersForGame(HDC hDC);
	void ShufflePieces();
	void start();
	CGameConfiguration m_gameConfiguration;
	CSetGameDialog m_dialogParameters;
	CGameSetUp m_setupGame;
	wstring imagePath;
};

