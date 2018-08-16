#pragma once

#include "PuzzleDetails.h"
#include "TimerDetails.h"
#include <vector>

class CGameConfiguration
{
public:
	void GetPuzzleDetails(int puzzleId);
	CTimerDetails GetTimerDetails(int timerId);
	std::vector<CPuzzleDetails> puzzleDetailsCollection;
};

