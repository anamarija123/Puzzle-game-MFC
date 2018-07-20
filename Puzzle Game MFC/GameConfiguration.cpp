#include "stdafx.h"
#include "GameConfiguration.h"
#include <list>
#include "PuzzleDetails.h"

CPuzzleDetails CGameConfiguration::GetPuzzleDetails(int puzzleId)
{
	const TCHAR* filename = _T(".\\puzzleGame.ini");
	WCHAR sectionName[100];
	WCHAR previewImageBuffer[100];
	WCHAR gameImage [100];
	
	swprintf(sectionName, sizeof(sectionName), L"Puzzle%d", puzzleId);
	GetPrivateProfileString(sectionName, _T("PreviewImage"), NULL, previewImageBuffer, sizeof(previewImageBuffer), filename);
	GetPrivateProfileString(sectionName, _T("GameImage"), NULL, gameImage, sizeof(gameImage), filename);

	CPuzzleDetails puzzleDetails(previewImageBuffer, gameImage);
	return puzzleDetails;
}
/*
void CGameConfiguration::GetTimerDetails(int timerId)//enumerator
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
}
*/