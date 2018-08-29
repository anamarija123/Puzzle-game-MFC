#pragma once
#include<string.h>
#include <vector>
#include <iterator>


using namespace std;
class CGameSetUp
{
public:
	CGameSetUp();
	~CGameSetUp();
	void initializeParameters(int height, int width, wstring picturePath);
	bool Shuffle();
	void DrawPieces(HDC HwINdC);
	void Swap(std::vector<POINT>gamerClickCoords);
	bool LoadBitmapPicture(HDC HwINdC, LPCWSTR szFileName);

	const int GetPictureWidth(void) { return m_pictureWidth; }
	const int GetPictureHeight(void) { return m_pictureHeight; }

	const int GetNumberOfColumns(void) { return heightNumber; }
	const int GetNumberOfRows(void) { return widthNumber; }

private:
	POINT original;
	POINT second_point;	
	POINT pieces;
	//std::vector<POINT>Coords;
	std::vector < vector<int>> Coords;
	std::vector < vector<int>> ShuffleCoords;
	int heightNumber;
	int widthNumber;

	RECT rect;
	HBITMAP hBitmap;
	BITMAP qBitmap;
	HDC hLocalDC;
	int lReturn;
	HBITMAP hOldBmp;

	int m_pictureHeight;
	int m_pictureWidth;

	
};

