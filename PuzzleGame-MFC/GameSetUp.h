#pragma once
#include <vector>
typedef std::basic_string<TCHAR>   tstring;

class CGameSetUp
{
public:
	CGameSetUp();
	~CGameSetUp();
	void initializeParameters(int height, int width);
	bool Shuffle();
	void DrawPieces(HDC HwINdC);
	void Swap(std::vector<POINT>gamerClickCoords);
	bool LoadBitmapPicture(HDC HwINdC, tstring szFileName);
	void Delete();

	const int GetPictureWidth(void) { return m_pictureWidth; }
	const int GetPictureHeight(void) { return m_pictureHeight; }

	const int GetNumberOfColumns(void) { return heightNumber; }
	const int GetNumberOfRows(void) { return widthNumber; }

	const int GetWidthOfPiece(void) { return quantityOfWidth; }
	const int GetHeightOfPiece(void) { return quantityOfHeight; }

private:
	HBITMAP hBitmap;
	HDC hLocalDC;
	HBITMAP hOldBmp;
	HDC vbc;
	POINT original;
	POINT second_point;	
	POINT pieces;
	std::vector < std::vector<int>> Coords;
	std::vector < std::vector<int>> ShuffleCoords;
	int heightNumber;
	int widthNumber;

	RECT rect;
	

	int m_pictureHeight;
	int m_pictureWidth;

	int quantityOfWidth;
	int quantityOfHeight;

	CString LoadStringFromResource(int ID);
};

