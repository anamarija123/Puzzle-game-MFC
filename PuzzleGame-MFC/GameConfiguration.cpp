#include "stdafx.h"
#include "GameConfiguration.h"
#include "PuzzleDetails.h"

/*
GetPuzzleDetails function load picture paths from ini file
@param puzzleId is number of section in ini file
*/
void CGameConfiguration::GetPuzzleDetails(TCHAR puzzleId)
{

	tstring filename = _T(".\\puzzleGame.ini");
	tstring sectionName;
	TCHAR previewImage[100];
	TCHAR gameImage[100];

	sectionName = _T("Puzzle");
	sectionName += puzzleId;
	
	GetPrivateProfileString(sectionName.c_str(), _T("PreviewImage"), NULL, previewImage, sizeof(previewImage), filename.c_str());
	GetPrivateProfileString(sectionName.c_str(), _T("GameImage"), NULL, gameImage, sizeof(gameImage), filename.c_str());

	CPuzzleDetails puzzleDetails(previewImage, gameImage);

	puzzleDetailsCollection.push_back(puzzleDetails);

}

void CGameConfiguration::checkCollection()
{
	if (!puzzleDetailsCollection.empty())
	{
		puzzleDetailsCollection.clear();
	}
}

/*
GetGridDetails function load rows and columns from ini file.
If there is no writen number, default is 7
*/
void CGameConfiguration::GetGridDetails()
{
	if (!gridDetailsCollection.empty())
	{
		gridDetailsCollection.clear();
	}

	tstring filename = _T(".\\puzzleGame.ini");
	xGrid = GetPrivateProfileInt(_T("GameStart"), _T("Width"),7, filename.c_str());
	yGrid = GetPrivateProfileInt(_T("GameStart"), _T("Height"), 7, filename.c_str());

	CGridDetails gridDetails(xGrid, yGrid);
	gridDetailsCollection.push_back(gridDetails);
	
}
/*
SetGridDetails function write in ini file entered rows and columns by user in dialog.
@param rows is number of rows
@param columns is number of columns
*/

void CGameConfiguration::SetGridDetails(int rows, int columns)
{

	tstring filename = _T(".\\puzzleGame.ini");
#ifdef UNICODE
	WritePrivateProfileString(_T("GameStart"), _T("Width"), std::to_wstring(rows).c_str(), filename.c_str());
	WritePrivateProfileString(_T("GameStart"), _T("Height"), std::to_wstring(columns).c_str(), filename.c_str());
#else
	WritePrivateProfileString(_T("GameStart"), _T("Width"), std::to_string(rows).c_str(), filename.c_str());
	WritePrivateProfileString(_T("GameStart"), _T("Height"), std::to_string(columns).c_str(), filename.c_str());
#endif

}
