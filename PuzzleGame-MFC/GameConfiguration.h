#pragma once

#include "PuzzleDetails.h"
#include "GridDetails.h"


class CGameConfiguration
{
private:
	int xGrid;
	int yGrid;
public:
	CGameConfiguration();
	~CGameConfiguration();
	void GetPuzzleDetails(TCHAR puzzleId);
	void checkCollection();
	void GetGridDetails();
	void SetGridDetails(int rows, int columns);
	std::vector<CPuzzleDetails> puzzleDetailsCollection;
	std::vector<CGridDetails> gridDetailsCollection;
	
};

