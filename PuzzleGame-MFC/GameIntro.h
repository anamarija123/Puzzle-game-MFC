#pragma once

#include "GridDetails.h"
#include "SetGameDialog.h"
#include "GameConfiguration.h"
#include "GameSetUp.h"
typedef std::basic_string<TCHAR>   tstring;

class CGameIntro
{
private:
	int x;
	int y;
	tstring m_wchImagePath;
public:
	CGameIntro();
	~CGameIntro();
	void SetParametarsLoadedFromDialog();
	void SetParametarsLoadedFromIniFile();
	void SetPictureForGame(HDC hDC);
	void SetParametersForGame(HDC hDC);
	void ShufflePieces();
	void start();

	tstring GameImagePath(void) { return m_wchImagePath; }

	CGameConfiguration m_gameConfiguration;
	CSetGameDialog m_dialogParameters;
	CGameSetUp m_setupGame;
};

