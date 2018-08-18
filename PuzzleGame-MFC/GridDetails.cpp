#include "stdafx.h"
#include "GridDetails.h"

CGridDetails::CGridDetails()
{

}
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
