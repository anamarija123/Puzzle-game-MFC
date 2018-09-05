#include "stdafx.h"
#include "PuzzleDetails.h"

/*
CPuzzleDetails setting paths from previewImage in dialog and gameImage for game
@param previewImage path of little picture
@param gameImage path of big picture
*/
CPuzzleDetails::CPuzzleDetails(tstring previewImage, tstring gameImage)
{
	if (previewImage.empty())
	{
		throw "Preview image not specified.";
	}
	
	m_wchPreviewImage.append(previewImage);
	

	if (gameImage.empty())
	{
		throw "Game image not specified.";
	}
	
	m_wchGameImage.append(gameImage);
}


CPuzzleDetails::~CPuzzleDetails()
{
}
