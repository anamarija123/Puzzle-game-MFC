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
	bool Shuffle();
	void DrawPieces(HWND hwnd, HDC HwINdC);
	void DrawGrid(CPaintDC* dc, RECT rect, HWND hwnd, HDC HwINdC);
	//bool LoadBitmapPicture(LPCWSTR szFileName);
	bool LoadBitmapPicture(HDC HwINdC, LPCWSTR szFileName);
	bool ShowPicture(HDC HwINdC);
private:
	POINT point;
	POINT a;
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
	BITMAP qBitmap;
	HDC hLocalDC;
	int lReturn;
	HBITMAP hOldBmp;
};

