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
	void checkCollection();
	void GetGridDetails();
	void SetGridDetails(int rows, int columns);
	std::vector<CPuzzleDetails> puzzleDetailsCollection;
	std::vector<CGridDetails> gridDetailsCollection;
	
};

