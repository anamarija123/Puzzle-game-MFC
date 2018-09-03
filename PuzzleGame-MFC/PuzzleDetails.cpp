#include "stdafx.h"
#include "PuzzleDetails.h"

/*
CPuzzleDetails setting paths from previewImage in dialog and gameImage for game
@param previewImage path of little picture
@param gameImage path of big picture
*/
CPuzzleDetails::CPuzzleDetails(TCHAR* previewImage, TCHAR* gameImage)
{
	if (previewImage == NULL)
	{
		throw "Preview image not specified.";
	}
	_stprintf(m_wchPreviewImage, _T ("%s"),previewImage);
	

	if (gameImage == NULL)
	{
		throw "Game image not specified.";
	}
	
	_stprintf(m_wchGameImage, _T("%s"), gameImage);
}


CPuzzleDetails::~CPuzzleDetails()
{
}
