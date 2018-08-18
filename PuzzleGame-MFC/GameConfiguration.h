#pragma once

#include "PuzzleDetails.h"
#include "TimerDetails.h"
#include <vector>
#include "GridDetails.h"

class CGameConfiguration
{
private:
	int xGrid;
	int yGrid;
public:
	void GetPuzzleDetails(int puzzleId);
	CTimerDetails GetTimerDetails(int timerId);
	void GetGridDetails();
	std::vector<CPuzzleDetails> puzzleDetailsCollection;
};

