#include "stdafx.h"
#include <algorithm>
#include <stdlib.h>  
#include "GameSetUp.h"
#include "MainFrm.h"
#include "resource.h"
#include <ctime>     

CGameSetUp::CGameSetUp() : 
	hBitmap(nullptr), 
	hLocalDC(nullptr),
	hOldBmp (nullptr),
	m_heightNumber(0),
	m_widthNumber(0), 
	m_pictureHeight(0),
	m_pictureWidth(0),
	m_quantityOfWidth(0),
	m_quantityOfHeight(0)
{
}


CGameSetUp::~CGameSetUp()
{
	Deallocate();
}
/*
initializeParameters function initialize two dimensional vector with coords of picture, depend on height and width 
@height dimension of picture
@width dimension of picture
@ picturePath chosen picture for game
*/
void CGameSetUp::initializeParameters(int height, int width )
{
	m_heightNumber = height;
	m_widthNumber = width;

	if (!Coords.empty())
	{
		Coords.clear();
	}

	if (!ShuffleCoords.empty())
	{
		ShuffleCoords.clear();
	}
	
	Coords.resize(width*height, std::vector<int>(2));

	m_quantityOfHeight = m_pictureHeight / height;
	m_quantityOfWidth = m_pictureWidth / width;


	int index = 0;
		for (int i = m_quantityOfHeight; i <= m_pictureHeight; i += m_quantityOfHeight)
		{
			for (int j = m_quantityOfWidth; j <= m_pictureWidth; j += m_quantityOfWidth)
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
	int index = firstClickedPieceCoords.y*m_widthNumber + firstClickedPieceCoords.x;
	int index2 = secondClickedPieceCoords.y*m_widthNumber + secondClickedPieceCoords.x;

	/*Swap*/
	temp = ShuffleCoords[index][0];
	ShuffleCoords[index][0] = ShuffleCoords[index2][0];
	ShuffleCoords[index2][0] = temp; 
	
	temp2 = ShuffleCoords[index][1];
	ShuffleCoords[index][1] = ShuffleCoords[index2][1];
	ShuffleCoords[index2][1] = temp2;

	CString msg = LoadStringFromResource(IDS_GAME_OVER);
	CString caption = LoadStringFromResource(IDS_GAME_OVER_CAPTION);

	/*if ShuffleCoords vector equals to Coords give a message for game over*/
	if (ShuffleCoords == Coords)
	{
		::MessageBox(NULL, msg, caption, MB_OK);
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

	int quantity_x = m_pictureWidth / m_widthNumber;
	int quantity_y = m_pictureHeight / m_heightNumber;

	int k = 0;
	for (int i = 0; i < m_widthNumber*m_heightNumber; i++)
	{
	
		if (i % m_widthNumber == 0 && i != 0)
		{
			++k;
		}
		
		pieces.x = ShuffleCoords[i][0];
		pieces.y = ShuffleCoords[i][1];
		bool qRetBlit = BitBlt(
			HwINdC,
			i%m_widthNumber* quantity_x,
			k % m_heightNumber * quantity_y,
			quantity_x, quantity_y,
			hLocalDC, pieces.x - quantity_x, pieces.y - quantity_y, SRCCOPY);
	}

}

/*
LoadBitmapPicture load picture from file 
@param HwINdC a handle to the destination device context.
@param szFileName path to picture
*/

bool CGameSetUp::LoadBitmapPicture(HDC HwINdC, tstring szFileName)
{
	BITMAP qBitmap;
	int lReturn;
	CString msgBitmap;
	CString msgObj;
	CString msgDC;
	CString msgSelectObj;
	CString caption;

	
	msgBitmap = LoadStringFromResource(IDS_FAILED);
	caption = LoadStringFromResource(IDS_ERROR);
	// Load the bitmap image file
	hBitmap = (HBITMAP)LoadImage(NULL, szFileName.c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	// Verify that the image was loaded
	if (hBitmap == NULL)
	{
		MessageBox(NULL, msgBitmap, caption, MB_OK);
	}

	msgObj = LoadStringFromResource(IDS_GET_OBJ);
	// Get the bitmap's parameters and verify the get
	lReturn = GetObject(reinterpret_cast<HGDIOBJ>(hBitmap), sizeof(BITMAP), reinterpret_cast<LPVOID>(&qBitmap));
	if (!lReturn)
	{
		MessageBox(NULL, msgObj, caption, MB_OK);
		return false;
	}

	msgDC = LoadStringFromResource(IDS_DC);
	// Create a device context that is compatible with the window
	hLocalDC = CreateCompatibleDC(HwINdC);
	// Verify that the device context was created
	if (hLocalDC == NULL) {
		MessageBox(NULL, msgDC, caption, MB_OK);
		return false;
	}
	
	msgSelectObj = LoadStringFromResource(IDS_SELECT_OBJ);
	// Select the loaded bitmap into the device context
	hOldBmp = (HBITMAP)SelectObject(hLocalDC, hBitmap);
	if (hOldBmp == NULL)
	{
		MessageBox(NULL, msgSelectObj, caption, MB_OK);
		return false;
	}
	
	m_pictureHeight = qBitmap.bmHeight;
	m_pictureWidth = qBitmap.bmWidth;

	return true;	
}


void CGameSetUp::Deallocate()
{
	if (hLocalDC != nullptr)
	{
		SelectObject(hLocalDC, hOldBmp);
	}
	DeleteDC(hLocalDC);
	DeleteObject(hBitmap);
	
}

/*
LoadStringFromResource get string from resource
@param ID of string
*/
CString CGameSetUp::LoadStringFromResource(int ID)
{
	CString messageString;
	messageString.LoadString(ID);

	return messageString;
}