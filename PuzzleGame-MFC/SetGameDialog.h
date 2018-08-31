#pragma once
#include "GameConfiguration.h"
#include "PuzzleDetails.h"

#include <iterator>

// CSetGameDialog dialog

class CSetGameDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CSetGameDialog)

public:
	CSetGameDialog(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CSetGameDialog();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SELECT_PUZZLE };
#endif
private:
	HBITMAP EntityImage;
	void DeleteBitmap();
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();

public:
	void ShowPicture(int picture_index);

protected:
	CGameConfiguration m_gameConfiguration;
	;
public:
	int indexOfPicture;
	int numberOfPictures;

	CStatic*  m_picture;
	std::wstring GetPictureForGame();
	void setPuzzleDetails(CGameConfiguration gameConfiguration);

	UINT X;
	UINT Y;
protected:
	afx_msg void OnBnClickedButtonPrevious();
	afx_msg void OnClickedButtonNext();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();


};
