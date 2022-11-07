#pragma once


// OpenMediaDialog 对话框

class OpenMediaDialog : public CDialogEx
{
	DECLARE_DYNAMIC(OpenMediaDialog)

public:
	OpenMediaDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~OpenMediaDialog();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_OPENMEDIA };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
