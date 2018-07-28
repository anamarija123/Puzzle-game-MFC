#include "stdafx.h"
#include "PuzzleDetails.h"
#include<string.h>

CPuzzleDetails::CPuzzleDetails(const wstring previewImage, const wstring gameImage)
{
	if (previewImage.empty())
	{
		throw "Preview image not specified.";
	}
	//m_wchPreviewImage +=previewImage;
	m_wchPreviewImage.append(previewImage);
//	strcpy(m_wchPreviewImage, previewImage);

	if (gameImage.empty())
	{
		throw "Game image not specified.";
	}
	//m_wchGameImage += gameImage;
//	strcpy(m_wchGameImage, gameImage);
	m_wchGameImage.append(gameImage);
}


CPuzzleDetails::~CPuzzleDetails()
{
}
