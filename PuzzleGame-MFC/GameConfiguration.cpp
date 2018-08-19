#include "stdafx.h"
#include "GameConfiguration.h"
#include <list>
#include "PuzzleDetails.h"
#include "TimerDetails.h"
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

	//return puzzleDetailsCollection;
}

CTimerDetails CGameConfiguration::GetTimerDetails(int timerId)
{
	const TCHAR* filename = _T(".\\puzzleGame.ini");
	WCHAR sectionName[100];
	int minutesForEasyGrid = 0;
	int minutesForMediumGrid = 0;
	int minutesForHardGrid = 0;

	swprintf(sectionName, sizeof(sectionName), L"Timer%d", timerId);
	minutesForEasyGrid = GetPrivateProfileInt(sectionName, _T("TimerEasyGame"), 3, filename);
	minutesForMediumGrid = GetPrivateProfileInt(sectionName, _T("TimerMediumGame"), 5, filename);
	minutesForHardGrid = GetPrivateProfileInt(sectionName, _T("TimerHardGame"), 7, filename);

	CTimerDetails timerDetails(minutesForEasyGrid, minutesForMediumGrid, minutesForHardGrid);
	return timerDetails;
}

void CGameConfiguration::GetGridDetails()
{
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