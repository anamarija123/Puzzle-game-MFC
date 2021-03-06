#pragma once
#include "GameSetUp.h"
#include "PuzzlePicturePreview.h"

// CPuzzlePicturePreview dialog

class CPuzzlePicturePreview : public CDialogEx
{
	DECLARE_DYNAMIC(CPuzzlePicturePreview)

public:
	CPuzzlePicturePreview(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CPuzzlePicturePreview();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PICTURE_PREVIEW};
#endif
private:

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	tstring m_picturePath;
	int m_widthOfPicture;
	int m_heightOfPicture;
	
	DECLARE_MESSAGE_MAP()

public:
	void SetPicturePreview(tstring pictureInfo, int width, int height);
	afx_msg void OnPaint();
	virtual BOOL OnInitDialog();
};
