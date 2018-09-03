#pragma once
#include<string> 


class CPuzzleDetails
{
private:

	 TCHAR m_wchPreviewImage[100];
	 TCHAR m_wchGameImage[100];

public:
	CPuzzleDetails (TCHAR* previewImage, TCHAR* gameImage);
	~CPuzzleDetails();

	const TCHAR* GetPreviewImagePath(void) { return m_wchPreviewImage; }
	const TCHAR* GetGameImagePath(void) { return m_wchGameImage; }

};
