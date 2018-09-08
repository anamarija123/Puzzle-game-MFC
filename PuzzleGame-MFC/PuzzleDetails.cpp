#include "stdafx.h"
#include "PuzzleDetails.h"

/*
CPuzzleDetails setting paths from previewImage in dialog and gameImage for game
@param previewImage path of little picture
@param gameImage path of big picture
*/
CPuzzleDetails::CPuzzleDetails(const tstring& previewImage, const tstring& gameImage) : m_wchPreviewImage(previewImage), m_wchGameImage(gameImage)
{
	if (previewImage.empty())
	{
		throw "Preview image not specified.";
	}
	
	if (gameImage.empty())
	{
		throw "Game image not specified.";
	}
}


CPuzzleDetails::~CPuzzleDetails()
{
}
