#pragma once
class CGridDetails
{
private:
	int m_XSize;
	int m_YSize;
public:
	CGridDetails(const int xSize, const int ySize);
	~CGridDetails();

	const int GetXSize(void) { return m_XSize; }
	const int GetYSize(void) { return m_YSize; }
};

