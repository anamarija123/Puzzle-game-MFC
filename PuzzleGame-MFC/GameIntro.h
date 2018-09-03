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
	const TCHAR* m_wchImagePath;
public:
	CGameIntro();
	~CGameIntro();
	void SetParametarsLoadedFromDialog();
	void SetParametarsLoadedFromIniFile();
	void SetPictureForGame(HDC hDC);
	void SetParametersForGame(HDC hDC);
	void ShufflePieces();
	const TCHAR* GameImagePath(void) { return m_wchImagePath; }
	void start();
	CGameConfiguration m_gameConfiguration;
	CSetGameDialog m_dialogParameters;
	CGameSetUp m_setupGame;
};

