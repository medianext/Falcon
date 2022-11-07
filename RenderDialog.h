#pragma once


// RenderDialog 对话框

class RenderDialog : public CDialogEx
{
	DECLARE_DYNAMIC(RenderDialog)

public:
	RenderDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~RenderDialog();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_RENDER_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
