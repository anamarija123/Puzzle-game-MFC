#include "stdafx.h"
#include "GridDetails.h"

/*
CGridDetails setting grid info
@param xSize number of rows
@param ySize number of columns
*/
CGridDetails::CGridDetails(const int xSize, const int ySize) : m_XSize(xSize), m_YSize(ySize)
{
	if (m_XSize == 0)
	{
		throw "width is not defined";
	}

	if (m_YSize == 0)
	{
		throw "width is not defined";
	}
}

CGridDetails::~CGridDetails()
{
}
