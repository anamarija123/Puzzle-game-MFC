#include "stdafx.h"
#include "PictureSetUp.h"


CPictureSetUp::CPictureSetUp()
{
}


CPictureSetUp::~CPictureSetUp()
{
}

void CPictureSetUp::init(int height, int width, wstring picturePath )
{
	heightNumber = height;
	widthNumber = width;
	
	for (int i = pictureHeight / height; i <= pictureHeight; i += pictureHeight / height)
	{
		point.y=i;
		for (int j = pictureWidth / width; j <= pictureWidth; j += pictureWidth / width)
		{
			point.x = j;
			Coords.push_back(point);
		}
	}	
}

void CPictureSetUp::DrawGrid(CPaintDC* dc, RECT rect, HWND hwnd, HDC HwINdC)
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

	int count = ShuffledCoords.size();

	BOOL qRetBlit = ::BitBlt(HwINdC, 0, 0, qBitmap.bmWidth, qBitmap.bmHeight, hLocalDC, 0, 0, SRCCOPY);

	int quantity_x = pictureWidth/widthNumber;
	int quantity_y = pictureHeight/heightNumber;

	for (int i = 0; i < widthNumber*heightNumber; i++)
	{
		POINT a;
		a = ShuffledCoords.at(i);
		BOOL qRetBlit = ::BitBlt(
			HwINdC,
			i%5* quantity_x,
			i/5* quantity_y,
			quantity_x, quantity_y,
			hLocalDC, a.x - quantity_x, a.y - quantity_y, SRCCOPY);
	}

	::SelectObject(hLocalDC, hOldBmp);
	::DeleteDC(hLocalDC);
	::DeleteObject(hBitmap);	
}

bool CPictureSetUp::Shuffle() //HDC HwINdC, CRect rect
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


void CPictureSetUp::DrawPieces(HWND hwnd,HDC HwINdC)
{
	GetClientRect(hwnd, &rect);
	for each (POINT points in ShuffledCoords)
	{
		BOOL qRetBlit = ::BitBlt(
			HwINdC,
			0,
			0,
			qBitmap.bmWidth,
			qBitmap.bmHeight,
			hLocalDC, points.x , points.y, SRCCOPY);
		
		if (!qRetBlit)
		{
			::MessageBox(NULL, _T("BItBlt failed"), _T("Error"), MB_OK);
			//return false;
		}
	}
}


bool CPictureSetUp::LoadBitmapPicture(HDC HwINdC, LPCWSTR szFileName)
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

	/*
	
	*/
	pictureHeight = qBitmap.bmHeight;
	pictureWidth = qBitmap.bmWidth;

	
	return true;
}

bool CPictureSetUp::ShowPicture(HDC HwINdC)
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