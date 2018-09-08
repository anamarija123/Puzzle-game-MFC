#pragma once


class CPuzzleDetails
{
private:

	 tstring m_wchPreviewImage;
	 tstring m_wchGameImage;

public:
	CPuzzleDetails (const tstring& previewImage, const tstring& gameImage);
	~CPuzzleDetails();

	tstring GetPreviewImagePath(void) { return m_wchPreviewImage; }
	tstring GetGameImagePath(void) { return m_wchGameImage; }

};
