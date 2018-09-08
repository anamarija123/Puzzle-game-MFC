#pragma once


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
	

	const int GetPictureWidth(void) { return m_pictureWidth; }
	const int GetPictureHeight(void) { return m_pictureHeight; }

	const int GetNumberOfColumns(void) { return m_heightNumber; }
	const int GetNumberOfRows(void) { return m_widthNumber; }

	const int GetWidthOfPiece(void) { return m_quantityOfWidth; }
	const int GetHeightOfPiece(void) { return m_quantityOfHeight; }

private:
	void Deallocate();
	CString LoadStringFromResource(int ID);

private:
	HBITMAP hBitmap;
	HDC hLocalDC;
	HBITMAP hOldBmp;


	POINT pieces;
	std::vector<std::vector<int>> Coords;
	std::vector<std::vector<int>> ShuffleCoords;
	int m_heightNumber;
	int m_widthNumber;

	int m_pictureHeight;
	int m_pictureWidth;

	int m_quantityOfWidth;
	int m_quantityOfHeight;
};

