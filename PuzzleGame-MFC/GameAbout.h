#pragma once

#include "GridDetails.h"
#include "SetGameDialog.h"
#include "GameConfiguration.h"

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
	void start();
	CSetGameDialog setDialogParameters;
	CGameConfiguration config;
};

