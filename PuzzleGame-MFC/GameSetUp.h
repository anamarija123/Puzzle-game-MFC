#pragma once
#include <vector>


class CGameSetUp
{
public:
	CGameSetUp();
	~CGameSetUp();
	void initializeParameters(int height, int width, const TCHAR* picturePath);
	bool Shuffle();
	void DrawPieces(HDC HwINdC);
	void Swap(std::vector<POINT>gamerClickCoords);
	bool LoadBitmapPicture(HDC HwINdC, const TCHAR* szFileName);
	CString LoadStringFromResource(int ID);
	void Delete();

	const int GetPictureWidth(void) { return m_pictureWidth; }
	const int GetPictureHeight(void) { return m_pictureHeight; }

	const int GetNumberOfColumns(void) { return heightNumber; }
	const int GetNumberOfRows(void) { return widthNumber; }

	const int GetWidthOfPiece(void) { return quantityOfWidth; }
	const int GetHeightOfPiece(void) { return quantityOfHeight; }

private:
	POINT original;
	POINT second_point;	
	POINT pieces;
	std::vector < std::vector<int>> Coords;
	std::vector < std::vector<int>> ShuffleCoords;
	int heightNumber;
	int widthNumber;

	RECT rect;
	HBITMAP hBitmap;
	
	HDC hLocalDC;
	HBITMAP hOldBmp;

	int m_pictureHeight;
	int m_pictureWidth;

	int quantityOfWidth;
	int quantityOfHeight;

};

