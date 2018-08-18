#pragma once

#include "GridDetails.h"
#include "SetGameDialog.h"

class CGameAbout
{
private:
	int x;
	int y;
public:
	CGameAbout();
	~CGameAbout();
	void SetParametarsInit();
	void start();
	CSetGameDialog setDialogParameters;
};

