#pragma once
#include<string> 
typedef std::basic_string<TCHAR>   tstring;

class CPuzzleDetails
{
private:

	 tstring m_wchPreviewImage;
	 tstring m_wchGameImage;

public:
	CPuzzleDetails (tstring previewImage, tstring gameImage);
	~CPuzzleDetails();

	tstring GetPreviewImagePath(void) { return m_wchPreviewImage; }
	tstring GetGameImagePath(void) { return m_wchGameImage; }

};
