#include "stdafx.h"
#include "GameConfiguration.h"
#include <list>
#include "PuzzleDetails.h"
#include <string.h>

using namespace std;
void CGameConfiguration::GetPuzzleDetails(int puzzleId)
{
	const TCHAR* filename = _T(".\\puzzleGame.ini");
	WCHAR sectionName[100];
	WCHAR previewImage[100];
	WCHAR gameImage[100];

	swprintf(sectionName, sizeof(sectionName), L"Puzzle%d", puzzleId);
	GetPrivateProfileString(sectionName, _T("PreviewImage"), NULL, previewImage, sizeof(previewImage), filename);
	GetPrivateProfileString(sectionName, _T("GameImage"), NULL, gameImage, sizeof(gameImage), filename);

	CPuzzleDetails puzzleDetails(previewImage, gameImage);

	puzzleDetailsCollection.push_back(puzzleDetails);

}
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
void CGameConfiguration::SetGridDetails(int x, int y)
{
	const TCHAR* filename = _T(".\\puzzleGame.ini");
	WritePrivateProfileString(_T("GameStart"), _T("Width"), std::to_wstring(x).c_str(), filename);
	WritePrivateProfileString(_T("GameStart"), _T("Height"), std::to_wstring(y).c_str(), filename);
}
