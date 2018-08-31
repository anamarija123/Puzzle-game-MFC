#pragma once
#include<string> 


class CPuzzleDetails
{
private:

	std::wstring m_wchPreviewImage;
	std::wstring m_wchGameImage;

public:
	CPuzzleDetails(const std::wstring previewImg, const std::wstring gameImg);
	~CPuzzleDetails();

	const std::wstring GetPreviewImagePath(void) { return m_wchPreviewImage; }
	const std::wstring GetGameImagePath(void) { return m_wchGameImage; }

};
