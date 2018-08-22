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
	void SetParametarsInit();
	void SetGridAndPicture(HDC hDC, CPaintDC* dc, RECT rect, HWND hwnd);
	void start();
	CGameConfiguration m_gameConfiguration;
	CSetGameDialog setDialogParameters;
	CPictureSetUp setup;
	wstring imagePath;
};

