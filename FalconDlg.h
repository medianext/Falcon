
// FalconDlg.h : 头文件
//

#pragma once

#include "RenderDialog.h"
#include "ControlDialog.h"

#include "MediaPlayer.h"


// CFalconDlg 对话框
class CFalconDlg : public CDialogEx
{
// 构造
public:
	CFalconDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FALCON_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;
	CMenu m_MainMenu;

	RenderDialog renderDlg;
	ControlDialog controlDlg;

	MediaPlayer* player;
	std::vector<std::string> filelist;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

	afx_msg void ShowAboutDialog();
public:
	afx_msg void OnMenuOpenFile();
	afx_msg void OnMenuOpenStream();
	afx_msg void OnMenuOpenDevice();
	afx_msg void OnMenuExit();
	afx_msg void OnMenuPlay();
	afx_msg void OnMenuPause();
	afx_msg void OnMenuStop();
	afx_msg void OnMenuPreview();
	afx_msg void OnMenuNext();
	afx_msg void OnMenuContainer();
	afx_msg void OnMenuCodec();
	afx_msg void OnViewPlaylist();
	afx_msg void OnViewConsole();
	afx_msg void OnViewControl();
	afx_msg void OnClose();
	afx_msg void OnDestroy();
	afx_msg void OnDropFiles(HDROP hDropInfo);
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
};
