#pragma once


// CSetGameDialog dialog

class CSetGameDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CSetGameDialog)

public:
	CSetGameDialog(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CSetGameDialog();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
