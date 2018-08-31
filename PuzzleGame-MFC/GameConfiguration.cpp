#include "stdafx.h"
#include "GameConfiguration.h"
#include <list>
#include "PuzzleDetails.h"
#include <wchar.h>

/*
GetPuzzleDetails function load picture paths from ini file
@param puzzleId is number of section in ini file
*/
void CGameConfiguration::GetPuzzleDetails(int puzzleId)
{
	const WCHAR* filename = L".\\puzzleGame.ini";
	WCHAR sectionName[100];
	WCHAR previewImage[100];
	WCHAR gameImage[100];

	swprintf(sectionName, sizeof(sectionName), L"Puzzle%d", puzzleId);
	GetPrivateProfileString(sectionName, _T("PreviewImage"), NULL, previewImage, sizeof(previewImage), filename);
	GetPrivateProfileString(sectionName, _T("GameImage"), NULL, gameImage, sizeof(gameImage), filename);

	CPuzzleDetails puzzleDetails(previewImage, gameImage);

	puzzleDetailsCollection.push_back(puzzleDetails);

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

	const WCHAR* filename = L".\\puzzleGame.ini";
	xGrid = GetPrivateProfileInt(_T("GameStart"), _T("Width"),7, filename);
	yGrid = GetPrivateProfileInt(_T("GameStart"), _T("Height"), 7, filename);

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
	const WCHAR* filename = L".\\puzzleGame.ini";
	WritePrivateProfileString(_T("GameStart"), _T("Width"), std::to_wstring(rows).c_str(), filename);
	WritePrivateProfileString(_T("GameStart"), _T("Height"), std::to_wstring(columns).c_str(), filename);
}
