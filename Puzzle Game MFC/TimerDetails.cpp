#include "stdafx.h"
#include "TimerDetails.h"


CTimerDetails::CTimerDetails(const int easyGameTime, const int mediumGameTime, const int hardGameTime)
{
	if (easyGameTime < 0 || easyGameTime == 0)
	{
		throw "Time is not set.";
	}
	this->m_intEasyGameTime = easyGameTime;

	if (easyGameTime < 0 || easyGameTime == 0)
	{
		throw "Time is not set.";
	}
	this->m_intMediumGameTime = mediumGameTime;

	if (easyGameTime < 0 || easyGameTime == 0)
	{
		throw "Time is not set.";
	}
	this->m_intHardGameTime = hardGameTime;
}

CTimerDetails::~CTimerDetails()
{
}
