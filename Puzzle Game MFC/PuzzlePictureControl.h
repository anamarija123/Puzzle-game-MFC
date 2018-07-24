#pragma once
class CPuzzlePictureControl : public CStatic
{
public:
	CPuzzlePictureControl();
	virtual ~CPuzzlePictureControl();
	void ChangePicture(const LPCTSTR picturePath);
};

