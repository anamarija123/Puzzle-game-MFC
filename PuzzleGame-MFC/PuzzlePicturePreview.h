#pragma once
#include <string>
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
	void DeleteBitmap();
	HBITMAP EntityImage;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	HICON m_hIcon;
	std::wstring m_picturePath;
	int m_widthOfPicture;
	int m_heightOfPicture;
	CStatic*  m_picture;
	DECLARE_MESSAGE_MAP()
public:
	void ShowPicture();
	void SetPicturePreview(std::wstring pictureInfo, int width, int height);
	afx_msg void OnPaint();
	virtual BOOL OnInitDialog();
	CGameSetUp m_pictureInfo;
	CBitmap m_bmp;
	CButton ShowPictureButton;
};
