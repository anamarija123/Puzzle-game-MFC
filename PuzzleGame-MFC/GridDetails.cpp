#include "stdafx.h"
#include "GridDetails.h"

/*
CGridDetails setting grid info
@param xSize number of rows
@param ySize number of columns
*/
CGridDetails::CGridDetails(const int xSize, const int ySize)
{
	if (xSize == 0)
	{
		throw "width is not defined";
	}
	this->m_XSize = xSize;
	if (ySize == 0)
	{
		throw "width is not defined";
	}
	this->m_YSize = ySize;
}

CGridDetails::~CGridDetails()
{
}
