#pragma once

#include "GridDetails.h"
#include "SetGameDialog.h"
#include "GameConfiguration.h"
#include "PictureSetUp.h"
class CGameAbout
{
private:
	int x;
	int y;
public:
	CGameAbout();
	~CGameAbout();
	CGameConfiguration m_gameConfiguration;
	void SetParametarsInit();
	void SetGridAndPicture(CPaintDC* dc, RECT rect, HWND hwnd);
	void start();
	CSetGameDialog setDialogParameters;
	CGameConfiguration config;
	CPictureSetUp setup;
};

