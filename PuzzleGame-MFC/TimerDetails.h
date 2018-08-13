#pragma once
class CTimerDetails
{
private:
	int m_intEasyGameTime;
	int m_intMediumGameTime;
	int m_intHardGameTime;
public:
	CTimerDetails(const int easyGameTime, const int mediumGameTime, const int hardGameTime);
	~CTimerDetails();

	const int GetEasyGameTime(void) { return m_intEasyGameTime; }
	const int GetMediumGameTime(void) { return m_intMediumGameTime; }
	const int GetHardGameTime(void) { return m_intHardGameTime; }
};
