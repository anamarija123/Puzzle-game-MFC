#include "stdafx.h"
#include "PuzzlePictureControl.h"


CPuzzlePictureControl::CPuzzlePictureControl()
{
}

CPuzzlePictureControl::~CPuzzlePictureControl()
{
}

void CPuzzlePictureControl::ChangePicture(const LPCTSTR picturePath)
{
	
	CImage image;
	image.Load(picturePath);

	CDC* cdc = this->GetDC();
	
	RECT rect;
	this->GetClientRect(&rect); 

	image.StretchBlt(cdc->GetSafeHdc(), rect);

	CBitmap bitmap;
	bitmap.Attach(image.Detach());
	
	
	this->SetBitmap((HBITMAP) bitmap);
	
}
