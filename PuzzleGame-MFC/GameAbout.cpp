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
	CGridDetails details;
	x = details.GetXSize();
	y = details.GetYSize();
	setDialogParameters.Y = y;
	setDialogParameters.X = x;

	setDialogParameters.DoModal();

	x = setDialogParameters.X;
	y = setDialogParameters.Y;

}