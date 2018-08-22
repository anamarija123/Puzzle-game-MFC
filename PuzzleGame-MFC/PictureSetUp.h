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
	bool DrawPicture();
	void DrawGrid(CPaintDC* dc, RECT rect, HWND hwnd);
	bool LoadBitmapPicture(LPCWSTR szFileName);
	bool ShowPicture(HDC HwINdC);
private:
	POINT point;
	POINT second_point;
	std::vector<POINT>Coords;
	std::vector<POINT>ShuffledCoords;
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

