#pragma once
#include<string.h>
#include <vector>

using namespace std;
class CPictureSetUp
{
public:
	CPictureSetUp();
	~CPictureSetUp();
	void init(int height, int width, wstring picturePath);
	bool DrawPicture(HDC HwINdC, CRect rect);
	void DrawGrid(CPaintDC* dc, CRect rect);
	bool LoadBitmapPicture(LPCWSTR szFileName);
	bool ShowPicture(HDC HwINdC);
private:
	std::vector<int>xCoords;
	std::vector<int>yCoords;
	std::vector<int>indexX;
	std::vector<int>indexY;
	int heightNumber;
	int widthNumber;
	int pictureHeight;
	int pictureWidth;
	RECT rect;
	HBITMAP hBitmap;
	HDC hLocalDC;
};

