#include "stdafx.h"
#include "GameConfiguration.h"
#include <list>
#include "PuzzleDetails.h"
#include <tchar.h>

/*
GetPuzzleDetails function load picture paths from ini file
@param puzzleId is number of section in ini file
*/
void CGameConfiguration::GetPuzzleDetails(int puzzleId)
{

	const TCHAR* filename = _T(".\\puzzleGame.ini");
	TCHAR sectionName[100];
	TCHAR previewImage[100];
	TCHAR gameImage[100];


	_stprintf(sectionName, _T("Puzzle%d"), puzzleId);
	GetPrivateProfileString(sectionName, _T("PreviewImage"), NULL, previewImage, sizeof(previewImage), filename);
	GetPrivateProfileString(sectionName, _T("GameImage"), NULL, gameImage, sizeof(gameImage), filename);

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

	const TCHAR* filename = _T(".\\puzzleGame.ini");
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
	TCHAR theRows[10];
	TCHAR theColumns[10];
	_stprintf(theRows, _T("%d"), rows);
	_stprintf(theColumns, _T("%d"), columns);

	const TCHAR* filename = _T(".\\puzzleGame.ini");
	WritePrivateProfileString(_T("GameStart"), _T("Width"), theRows, filename);
	WritePrivateProfileString(_T("GameStart"), _T("Height"), theColumns, filename);
}
