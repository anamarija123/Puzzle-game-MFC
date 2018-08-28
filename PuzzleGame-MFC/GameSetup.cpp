#include "stdafx.h"
#include <algorithm>
#include <stdlib.h>  
#include "GameSetUp.h"
#include "MainFrm.h"
#include <ctime>        // std::time
CGameSetUp::CGameSetUp()
{
}


CGameSetUp::~CGameSetUp()
{
}

void CGameSetUp::initializeParameters(int height, int width, wstring picturePath )
{
	heightNumber = height;
	widthNumber = width;

	if (!Coords.empty())
	{
		Coords.clear();
	}

	if (!ShuffleCoords.empty())
	{
		ShuffleCoords.clear();
	}

	for (int i = 0; i < width*height; i++)
	{
		vector<int>temp;
		for (int j = 0; j < 2; j++)
		{
			temp.push_back(i);
		}
		Coords.push_back(temp);
	}

	int index = 0;
	while (index < height*width)
	{
		for (int i = m_pictureHeight / height; i <= m_pictureHeight; i += m_pictureHeight / height)
		{
			for (int j = m_pictureWidth / width; j <= m_pictureWidth; j += m_pictureWidth / width)
			{
				Coords[index][0] = j;
				Coords[index][1] = i;
				++index;
			}
		}

	}

	ShuffleCoords = Coords;
}

void CGameSetUp::DrawGrid(CPaintDC* dc, RECT rect, HWND hwnd, HDC HwINdC)
{

	GetClientRect(hwnd, &rect);
	int i;
	int k = 0;
	for (i = 0; i < rect.right; i = i + rect.right / widthNumber)
		
	{
		dc->MoveTo(i, 0), dc->LineTo(i, rect.bottom);		
	}
	
	for (int i = 0; i < rect.bottom; i = i + rect.bottom / heightNumber)
		dc->MoveTo(0, i), dc->LineTo(rect.right, i);

}


void CGameSetUp::Swap(std::vector<POINT>gamerClickCoords)
{
	POINT firstClickedPieceCoords;
	POINT secondClickedPieceCoords;
	int temp;
	int temp2;
	if (gamerClickCoords.empty())
	{
		throw "there are no gamer clicks coordinates";
	}

	firstClickedPieceCoords.x = gamerClickCoords[0].x;
	firstClickedPieceCoords.y = gamerClickCoords[0].y;

	secondClickedPieceCoords.x = gamerClickCoords[1].x;
	secondClickedPieceCoords.y = gamerClickCoords[1].y;


	int index = firstClickedPieceCoords.y*widthNumber + firstClickedPieceCoords.x;
	int index2 = secondClickedPieceCoords.y*widthNumber + secondClickedPieceCoords.x;
	
	temp = ShuffleCoords[index][0];
	ShuffleCoords[index][0] = ShuffleCoords[index2][0];
	ShuffleCoords[index2][0] = temp; 
	
	temp2 = ShuffleCoords[index][1];
	ShuffleCoords[index][1] = ShuffleCoords[index2][1];
	ShuffleCoords[index2][1] = temp2;

	if (ShuffleCoords == Coords)
	{
		::MessageBox(NULL, _T("FINISH"), _T("GAME OVER"), MB_OK);
	}
}


bool CGameSetUp::Shuffle() 
{
	//std::srand(unsigned(std::time(0)));
	
	std::random_shuffle(ShuffleCoords.begin(), ShuffleCoords.end());
	return true;
}


void CGameSetUp::DrawPieces(HDC HwINdC)
{
	int quantity_x = m_pictureWidth / widthNumber;
	int quantity_y = m_pictureHeight / heightNumber;

	int k = 0;
	for (int i = 0; i < widthNumber*heightNumber; i++)
	{
	
		if (i % widthNumber == 0 && i != 0)
		{
			++k;
		}
		
		pieces.x = ShuffleCoords[i][0];
		pieces.y = ShuffleCoords[i][1];
		BOOL qRetBlit = ::BitBlt(
			HwINdC,
			i%widthNumber* quantity_x,
			k % heightNumber * quantity_y,
			quantity_x, quantity_y,
			hLocalDC, pieces.x - quantity_x, pieces.y - quantity_y, SRCCOPY);

	
	}

}



bool CGameSetUp::LoadBitmapPicture(HDC HwINdC, LPCWSTR szFileName)
{
	hBitmap = (HBITMAP)LoadImage(NULL, szFileName, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

	if (hBitmap == NULL)
	{
		::MessageBox(NULL, _T("FAILED"), _T("ERROR"), MB_OK);
	}
	lReturn = GetObject(reinterpret_cast<HGDIOBJ>(hBitmap), sizeof(BITMAP), reinterpret_cast<LPVOID>(&qBitmap));
	if (!lReturn)
	{
		::MessageBox(NULL, _T("GetObj failed"), _T("Error"), MB_OK);
		return false;
	}

	hLocalDC = ::CreateCompatibleDC(HwINdC);
	// Verify that the device context was created
	if (hLocalDC == NULL) {
		::MessageBox(NULL, __T("CreateCompatibleDC Failed"), __T("Error"), MB_OK);
		return false;
	}

	hOldBmp = (HBITMAP)::SelectObject(hLocalDC, hBitmap);
	if (hOldBmp == NULL)
	{
		::MessageBox(NULL, _T("SelectObj failed"), _T("Error"), MB_OK);
		return false;
	}

	m_pictureHeight = qBitmap.bmHeight;
	m_pictureWidth = qBitmap.bmWidth;

	return true;
}

bool CGameSetUp::ShowPicture(HDC HwINdC)
{
	BOOL qRetBlit = ::BitBlt(HwINdC, 0, 0, qBitmap.bmWidth, qBitmap.bmHeight, hLocalDC, 0, 0, SRCCOPY);
	if (!qRetBlit)
	{
		::MessageBox(NULL, _T("BItBlt failed"), _T("Error"), MB_OK);
		return false;
	}
	
	::SelectObject(hLocalDC, hOldBmp);
	::DeleteDC(hLocalDC);
	::DeleteObject(hBitmap);
	
}

