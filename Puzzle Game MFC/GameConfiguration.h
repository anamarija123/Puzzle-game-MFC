#pragma once
#include "PuzzleDetails.h"
#include "TimerDetails.h"


class CGameConfiguration {
public:
	CPuzzleDetails GetPuzzleDetails (int puzzleId);
	CTimerDetails GetTimerDetails(int timerId);
};