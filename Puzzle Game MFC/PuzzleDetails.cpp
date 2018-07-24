#include "stdafx.h"
#include "PuzzleDetails.h"


CPuzzleDetails::CPuzzleDetails(const LPTSTR previewImage, const LPTSTR gameImage)
{
	if (previewImage == NULL)
	{
		throw "Preview image not specified.";
	}
	wcscpy(this->m_wchPreviewImage, previewImage);

	if (gameImage == NULL)
	{
		throw "Game image not specified.";
	}
	wcscpy(this->m_wchGameImage, gameImage);
	
}


CPuzzleDetails::~CPuzzleDetails()
{
}
