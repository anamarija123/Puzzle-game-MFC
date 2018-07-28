#pragma once
#include<string> 
using namespace std;
class CPuzzleDetails
{
private:

	wstring m_wchPreviewImage;
	wstring m_wchGameImage;

public:
	CPuzzleDetails(const wstring previewImg, const wstring gameImg);
	~CPuzzleDetails();
	
	const wstring GetPreviewImagePath(void) { return m_wchPreviewImage; }
	const wstring GetGameImagePath(void) { return m_wchGameImage; }
	
};

