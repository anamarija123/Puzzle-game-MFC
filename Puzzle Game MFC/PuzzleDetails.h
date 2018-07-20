#pragma once

class CPuzzleDetails
{
private:
	WCHAR m_wchPreviewImage[100];
	WCHAR m_wchGameImage[100];
public:
	CPuzzleDetails(const LPTSTR previewImg, const LPTSTR gameImg);
	~CPuzzleDetails();

	const WCHAR* GetPreviewImagePath(void) { return m_wchPreviewImage; }
	const WCHAR* GetGameImagePath(void) { return m_wchGameImage; }
};

