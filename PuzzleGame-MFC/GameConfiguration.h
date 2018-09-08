#pragma once

#include "PuzzleDetails.h"
#include "GridDetails.h"


class CGameConfiguration
{
public:
	const static int DEFAULT_GRID_ROWS = 7;
	const static int DEFAULT_GRID_COLUMNS = 7;

private:
	int xGrid;
	int yGrid;
public:
	CGameConfiguration(int rows = DEFAULT_GRID_ROWS, int columns = DEFAULT_GRID_COLUMNS) : xGrid(rows), yGrid(columns)
	{
		///Možda nešto
	}

	void GetPuzzleDetails(TCHAR puzzleId);
	void checkCollection();
	void GetGridDetails();
	void SetGridDetails(int rows, int columns);
	std::vector<CPuzzleDetails> puzzleDetailsCollection;
	std::vector<CGridDetails> gridDetailsCollection;
	
};

