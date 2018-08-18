#include "stdafx.h"
#include "CPictureSetUp.h"


PictureSetUp::PictureSetUp()
{
}


PictureSetUp::~PictureSetUp()
{
}

void PictureSetUp::init(int height, int width, string picturePath )
{

	height = height;
	width = width;
	for (int i = 0; i < pictureHeight; i += pictureHeight / height)
	{
		yCoords.push_back(i);
	}

	for (int i = 0; i < pictureWidth; i += pictureWidth / width)
	{
		xCoords.push_back(i);
	}

	for (int i = 0; i < height*width; i ++)
	{	
		indexY.push_back(i);
		indexX.push_back(i);
	}
}

void PictureSetUp::DrawGrid(CPaintDC* dc, CRect rect)
{
	for (int i = 0; i < rect.right; i += rect.right%widthNumber)
	{
		dc->MoveTo(0, i);
		dc->LineTo(rect.bottom, i);
	}

	for (int i = 0; i < rect.bottom; i += rect.bottom%heightNumber)
	{
		dc->MoveTo(i, 0);
		dc->LineTo(i, rect.right);
	}
}

void PictureSetUp::DrawPicture(CPaintDC* dc, CRect rect)
{
	for (int i = 0; i < widthNumber; i++)
	{
		for (int j = 0; j < heightNumber; j++)
		{
			indexX.at(rand()%indexX.size())%widthNumber;
			indexY.at(rand() % indexY.size())%heightNumber;
		}

	}
}
bool PictureSetUp::LoadBitmapPicture(LPCWSTR szFileName)
{
	hBitmap = (HBITMAP)LoadImage(NULL, szFileName, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	
	if (hBitmap == NULL)
	{
		::MessageBox(NULL, _T("FAILED"), _T("ERROR"), MB_OK);
	}
	GetClientRect((HWND)hBitmap, &rect);

	return true;
}


bool PictureSetUp::ShowPicture (HDC HwINdC)
{
	HDC hLocalDC;
	hLocalDC = ::CreateCompatibleDC(HwINdC);
	if (hLocalDC == NULL)
	{
		::MessageBox(NULL, _T("CreateCompatibileDc failed"), _T("Error"), MB_OK);
		return false;
	}

	BITMAP qBitmap;
	int lReturn = GetObject(reinterpret_cast<HGDIOBJ>(hBitmap), sizeof(BITMAP), reinterpret_cast<LPVOID>(&qBitmap));
	if (!lReturn)
	{
		::MessageBox(NULL, _T("GetObj failed"), _T("Error"), MB_OK);
		return false;
	}

	HBITMAP hOldBmp = (HBITMAP)::SelectObject(hLocalDC, hBitmap);
	if (hOldBmp == NULL)
	{
		::MessageBox(NULL, _T("SelectObj failed"), _T("Error"), MB_OK);
		return false;
	}

	BOOL qRetBlit = ::BitBlt(HwINdC, 0, 0, rect.right, rect.bottom, hLocalDC, 0, 0, SRCCOPY);
	if (!qRetBlit)
	{
		::MessageBox(NULL, _T("BItBlt failed"), _T("Error"), MB_OK);
		return false;
	}

	::SelectObject(hLocalDC, hOldBmp);
	::DeleteDC(hLocalDC);
	::DeleteObject(hBitmap);
	return true;
}
