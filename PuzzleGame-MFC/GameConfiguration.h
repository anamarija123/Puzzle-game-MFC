#pragma once

#include "PuzzleDetails.h"
#include <vector>
#include "GridDetails.h"

class CGameConfiguration
{
private:
	int xGrid;
	int yGrid;
public:
	void GetPuzzleDetails(int puzzleId);
	void GetGridDetails();
	void SetGridDetails(int x, int y);
	std::vector<CPuzzleDetails> puzzleDetailsCollection;
	std::vector<CGridDetails> gridDetailsCollection;
	
};

