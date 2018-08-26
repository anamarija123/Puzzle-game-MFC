#pragma once
#include "PuzzleGameView.h"
#include "GameConfiguration.h"
#include "GameIntro.h"
#include "GridDetails.h"
#include "GameSetUp.h"
#include "PuzzleDetails.h"
class CGameDocument
{
public:
	CGameDocument();
	~CGameDocument();

	CChildView childView;
	CGameSetUp gameSetUp;
};

