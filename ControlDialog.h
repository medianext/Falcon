#pragma once
#include "afxcmn.h"


// ControlDialog 对话框

class ControlDialog : public CDialogEx
{
	DECLARE_DYNAMIC(ControlDialog)

public:
	ControlDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~ControlDialog();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CONTROL_DIALOG };
#endif

	CSliderCtrl m_SeekSlider;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPlay();
	afx_msg void OnPause();
	afx_msg void OnStop();
	afx_msg void OnPreview();
	afx_msg void OnNext();
	virtual BOOL OnInitDialog();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
};
