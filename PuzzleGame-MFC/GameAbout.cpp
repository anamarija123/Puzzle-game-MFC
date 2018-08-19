#include "stdafx.h"
#include "GameAbout.h"

void CGameAbout::start()
{
	
	m_gameConfiguration.GetGridDetails();
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
	
	x = m_gameConfiguration.gridDetailsCollection[0].GetXSize();
	y = m_gameConfiguration.gridDetailsCollection[0].GetYSize();
	setDialogParameters.Y = y;
	setDialogParameters.X = x;
	
	setDialogParameters.DoModal();
	
	
	x = setDialogParameters.X;
	y = setDialogParameters.Y;
	config.SetGridDetails(x, y);
}