#pragma once

#include "PuzzleDetails.h"
#include <vector>
#include "GridDetails.h"
typedef std::basic_string<TCHAR>   tstring;

class CGameConfiguration
{
private:
	int xGrid;
	int yGrid;
public:
	void GetPuzzleDetails(TCHAR puzzleId);
	void checkCollection();
	void GetGridDetails();
	void SetGridDetails(int rows, int columns);
	std::vector<CPuzzleDetails> puzzleDetailsCollection;
	std::vector<CGridDetails> gridDetailsCollection;
	
};

