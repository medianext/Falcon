
// FalconDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Falcon.h"
#include "FalconDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框 

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

														// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CFalconDlg 对话框



CFalconDlg::CFalconDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_FALCON_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFalconDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CFalconDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CLOSE()
	ON_WM_DESTROY()
	ON_WM_DROPFILES()
	ON_COMMAND(ID_FILE_OPENFILE, &CFalconDlg::OnMenuOpenFile)
	ON_COMMAND(ID_FILE_OPENSTREAM, &CFalconDlg::OnMenuOpenStream)
	ON_COMMAND(ID_FILE_OPENDEVICE, &CFalconDlg::OnMenuOpenDevice)
	ON_COMMAND(ID_FILE_EXIT, &CFalconDlg::OnMenuExit)
	ON_COMMAND(ID_PLAY_PLAY, &CFalconDlg::OnMenuPlay)
	ON_COMMAND(ID_PLAY_PAUSE, &CFalconDlg::OnMenuPause)
	ON_COMMAND(ID_PLAY_STOP, &CFalconDlg::OnMenuStop)
	ON_COMMAND(ID_PLAY_PREVIEW, &CFalconDlg::OnMenuPreview)
	ON_COMMAND(ID_PLAY_NEXT, &CFalconDlg::OnMenuNext)
	ON_COMMAND(ID_HELP_ABOUT, &CFalconDlg::ShowAboutDialog)
	ON_COMMAND(ID_TOOL_CONTAINER, &CFalconDlg::OnMenuContainer)
	ON_COMMAND(ID_TOOL_CODEC, &CFalconDlg::OnMenuCodec)
	ON_COMMAND(ID_VIEW_PLAYLIST, &CFalconDlg::OnViewPlaylist)
	ON_COMMAND(ID_VIEW_CONSOLE, &CFalconDlg::OnViewConsole)
	ON_COMMAND(ID_VIEW_CONTROL, &CFalconDlg::OnViewControl)
END_MESSAGE_MAP()


// CFalconDlg 消息处理程序

BOOL CFalconDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

									// TODO: 在此添加额外的初始化代码

	m_MainMenu.LoadMenu(IDR_FALCON_MENU);
	SetMenu(&m_MainMenu);

	RECT clientRect;
	GetClientRect(&clientRect);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CFalconDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CFalconDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CFalconDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CFalconDlg::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CDialogEx::OnClose();
}


void CFalconDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	// TODO: 在此处添加消息处理程序代码
}


void CFalconDlg::OnDropFiles(HDROP hDropInfo)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CDialogEx::OnDropFiles(hDropInfo);
}


BOOL CFalconDlg::OnCommand(WPARAM wParam, LPARAM lParam)
{
	// TODO: 在此添加专用代码和/或调用基类

	return CDialogEx::OnCommand(wParam, lParam);
}


void CFalconDlg::OnMenuOpenFile()
{
	// TODO: 在此添加命令处理程序代码
}


void CFalconDlg::OnMenuOpenStream()
{
	// TODO: 在此添加命令处理程序代码
}


void CFalconDlg::OnMenuOpenDevice()
{
	// TODO: 在此添加命令处理程序代码
}


void CFalconDlg::OnMenuExit()
{
	// TODO: 在此添加命令处理程序代码
}


void CFalconDlg::OnMenuPlay()
{
	// TODO: 在此添加命令处理程序代码
}


void CFalconDlg::OnMenuPause()
{
	// TODO: 在此添加命令处理程序代码
}


void CFalconDlg::OnMenuStop()
{
	// TODO: 在此添加命令处理程序代码
}


void CFalconDlg::OnMenuPreview()
{
	// TODO: 在此添加命令处理程序代码
}


void CFalconDlg::OnMenuNext()
{
	// TODO: 在此添加命令处理程序代码
}


void CFalconDlg::ShowAboutDialog()
{
	// TODO: 在此添加命令处理程序代码
	CAboutDlg dlgAbout;
	dlgAbout.DoModal();
}


void CFalconDlg::OnMenuContainer()
{
	// TODO: 在此添加命令处理程序代码
}


void CFalconDlg::OnMenuCodec()
{
	// TODO: 在此添加命令处理程序代码
}


void CFalconDlg::OnViewPlaylist()
{
	// TODO: 在此添加命令处理程序代码
}


void CFalconDlg::OnViewConsole()
{
	// TODO: 在此添加命令处理程序代码
}


void CFalconDlg::OnViewControl()
{
	// TODO: 在此添加命令处理程序代码
}