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
	for (int i = pictureHeight / height; i < pictureHeight; i += pictureHeight / height)
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

void CPictureSetUp::DrawGrid(CPaintDC* dc, RECT rect, HWND hwnd)
{
	GetClientRect(hwnd, &rect);
	dc->LineTo(rect.right, rect.bottom);

	for(int i=0;i<rect.right;i=i+rect.right/widthNumber)
		dc->MoveTo(i,0), dc->LineTo(i, rect.bottom);
}

bool CPictureSetUp::DrawPicture(HDC HwINdC, CRect rect)
{
	int X;
	int Y;
	for (int i = 0; i < widthNumber; i++)
	{
		for (int j = 0; j < heightNumber; j++)
		{
			X=indexX.at(rand()%indexX.size())%widthNumber;
			Y=indexY.at(rand() % indexY.size())%heightNumber;
			BOOL qRetBlit = ::BitBlt(
				HwINdC,
				0,
				0,
				pictureWidth/ widthNumber,
				pictureHeight/heightNumber
				, hLocalDC,X*pictureWidth/widthNumber, Y*pictureHeight/heightNumber, SRCCOPY);
			if (!qRetBlit)
			{
				::MessageBox(NULL, _T("BItBlt failed"), _T("Error"), MB_OK);
				return false;
			}
		}

	}
	return true;
}
bool CPictureSetUp::LoadBitmapPicture(LPCWSTR szFileName)
{
	hBitmap = (HBITMAP)LoadImage(NULL, szFileName, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	
	if (hBitmap == NULL)
	{
		::MessageBox(NULL, _T("FAILED"), _T("ERROR"), MB_OK);
	}
	GetClientRect((HWND)hBitmap, &rect);


	BITMAP qBitmap;
	int lReturn = GetObject(reinterpret_cast<HGDIOBJ>(hBitmap), sizeof(BITMAP), reinterpret_cast<LPVOID>(&qBitmap));
	if (!lReturn)
	{
		::MessageBox(NULL, _T("GetObj failed"), _T("Error"), MB_OK);
		return false;
	}
	pictureHeight = qBitmap.bmHeight;
	pictureWidth = qBitmap.bmWidth;


	return true;
}


bool CPictureSetUp::ShowPicture (HDC HwINdC)
{
	HBITMAP hOldBmp = (HBITMAP)::SelectObject(hLocalDC, hBitmap);
	if (hOldBmp == NULL)
	{
		::MessageBox(NULL, _T("SelectObj failed"), _T("Error"), MB_OK);
		return false;
	}

	hLocalDC = ::CreateCompatibleDC(HwINdC);
	if (hLocalDC == NULL)
	{
		::MessageBox(NULL, _T("CreateCompatibileDc failed"), _T("Error"), MB_OK);
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
