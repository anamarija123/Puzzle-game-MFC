#include "stdafx.h"
#include <algorithm>
#include <stdlib.h>  
#include "GameSetUp.h"
#include "MainFrm.h"
#include <ctime>     

CGameSetUp::CGameSetUp()
{
}


CGameSetUp::~CGameSetUp()
{
}
/*
initializeParameters function initialize two dimensional vector with coords of picture, depend on height and width 
@height dimension of picture
@width dimension of picture
@ picturePath chosen picture for game
*/
void CGameSetUp::initializeParameters(int height, int width, std::wstring picturePath )
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
	
	Coords.resize(width*height, std::vector<int>(2));

	quantityOfHeight = m_pictureHeight / height;
	quantityOfWidth = m_pictureWidth / width;


	int index = 0;
		for (int i = quantityOfHeight; i <= m_pictureHeight; i += quantityOfHeight)
		{
			for (int j = quantityOfWidth; j <= m_pictureWidth; j += quantityOfWidth)
			{
				Coords[index][0] = j;
				Coords[index][1] = i;
				++index;
			}
		}

	ShuffleCoords = Coords;
}

/*
Swap function swaping piece of picture depend on user clicks
*/

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

	/*algorithm for find index in Coords vector*/
	int index = firstClickedPieceCoords.y*widthNumber + firstClickedPieceCoords.x;
	int index2 = secondClickedPieceCoords.y*widthNumber + secondClickedPieceCoords.x;

	/*Swap*/
	temp = ShuffleCoords[index][0];
	ShuffleCoords[index][0] = ShuffleCoords[index2][0];
	ShuffleCoords[index2][0] = temp; 
	
	temp2 = ShuffleCoords[index][1];
	ShuffleCoords[index][1] = ShuffleCoords[index2][1];
	ShuffleCoords[index2][1] = temp2;

	/*if ShuffleCoords vector equals to Coords give a message for game over*/
	if (ShuffleCoords == Coords)
	{
		::MessageBox(NULL, _T("GAME OVER"), _T("FINISH"), MB_OK);
	}
}

bool CGameSetUp::Shuffle() 
{
	std::srand(unsigned(std::time(0)));
	
	std::random_shuffle(ShuffleCoords.begin(), ShuffleCoords.end());
	return true;
}

/*
DrawPieces function draw puzzles on window from ShuffleCoords vector
@param HwINdC a handle to the destination device context.
*/
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

/*
LoadBitmapPicture load picture from file 
@param HwINdC a handle to the destination device context.
@param szFileName path to picture
*/

bool CGameSetUp::LoadBitmapPicture(HDC HwINdC, LPCWSTR szFileName)
{
	BITMAP qBitmap;
	int lReturn;

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


void CGameSetUp::Delete()
{
	::DeleteDC(hLocalDC);
	::DeleteObject(hBitmap);
}