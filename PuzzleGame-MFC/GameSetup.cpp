#include "stdafx.h"
#include "GameSetUp.h"
#include "MainFrm.h"

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
	
	for (int i = m_pictureHeight / height; i <= m_pictureHeight; i += m_pictureHeight / height)
	{
		original.y=i;
		for (int j = m_pictureWidth / width; j <= m_pictureWidth; j += m_pictureWidth / width)
		{
			original.x = j;
			Coords.push_back(original);
		}
	}
	
	for each (POINT coord in Coords)
	{
		copyOriginalCoords.push_back(coord);
	}
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
	int sizeOfOriginalVectorCoords = copyOriginalCoords.size();
	
	int j = 0;
	
		for (int i = 0; i < sizeOfOriginalVectorCoords; ++i)
		{
			if (copyOriginalCoords[i].x > gamerClickCoords[j].x && copyOriginalCoords[i].y > gamerClickCoords[j].y)
			{
				swapCoordsToShow.push_back(copyOriginalCoords[i]);
				gamerClickCoords.erase(gamerClickCoords.begin() + j);
				if (gamerClickCoords.empty())
				{
					break;
				}
			}
		}

		int i = 0;
		for each (POINT coords in swapCoordsToShow)
		{
			pieces = swapCoordsToShow.at(i);
			BOOL qRetBlit = ::BitBlt(
				HwINdC,
				i%widthNumber* quantity_x,
				i / heightNumber * quantity_y,
				quantity_x, quantity_y,
				hLocalDC, pieces.x - quantity_x, pieces.y - quantity_y, SRCCOPY);
		}
}


bool CGameSetUp::Shuffle() 
{
	if (Coords.empty())
	{
		return false;
	}
	while (!Coords.empty())
	{
		int index = (rand() % Coords.size()) % widthNumber; 
		second_point = Coords.at(index);
		ShuffledCoords.push_back(second_point);
		Coords.erase(Coords.begin() + index);
	}
	return true;
}


void CGameSetUp::DrawPieces(HDC HwINdC)
{
	int quantity_x = m_pictureWidth / widthNumber;
	int quantity_y = m_pictureHeight / heightNumber;


	for (int i = 0; i < widthNumber*heightNumber; i++)
	{

		pieces = ShuffledCoords.at(i);
		BOOL qRetBlit = ::BitBlt(
			HwINdC,
			i%widthNumber* quantity_x,
			i / heightNumber * quantity_y,
			quantity_x, quantity_y,
			hLocalDC, pieces.x - quantity_x, pieces.y - quantity_y, SRCCOPY);
	}

	::SelectObject(hLocalDC, hOldBmp);
	::DeleteDC(hLocalDC);
	::DeleteObject(hBitmap);
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

