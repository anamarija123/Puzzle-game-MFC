#pragma once

#include "PuzzleDetails.h"
#include "TimerDetails.h"
#include <vector>
#include "GridDetails.h"

class CGameConfiguration
{
private:
	
public:
	void GetPuzzleDetails(int puzzleId);
	CTimerDetails GetTimerDetails(int timerId);
	void GetGridDetails();
	void SetGridDetails(int x, int y);
	std::vector<CPuzzleDetails> puzzleDetailsCollection;
	std::vector<CGridDetails> gridDetailsCollection;
	int xGrid;
	int yGrid;
};

