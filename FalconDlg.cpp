
// FalconDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Falcon.h"
#include "FalconDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի��� 

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

														// ʵ��
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


// CFalconDlg �Ի���



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


// CFalconDlg ��Ϣ�������

BOOL CFalconDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

									// TODO: �ڴ���Ӷ���ĳ�ʼ������

	m_MainMenu.LoadMenu(IDR_FALCON_MENU);
	SetMenu(&m_MainMenu);

	RECT clientRect;
	GetClientRect(&clientRect);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CFalconDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CFalconDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CFalconDlg::OnClose()
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CDialogEx::OnClose();
}


void CFalconDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	// TODO: �ڴ˴������Ϣ����������
}


void CFalconDlg::OnDropFiles(HDROP hDropInfo)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CDialogEx::OnDropFiles(hDropInfo);
}


BOOL CFalconDlg::OnCommand(WPARAM wParam, LPARAM lParam)
{
	// TODO: �ڴ����ר�ô����/����û���

	return CDialogEx::OnCommand(wParam, lParam);
}


void CFalconDlg::OnMenuOpenFile()
{
	// TODO: �ڴ���������������
}


void CFalconDlg::OnMenuOpenStream()
{
	// TODO: �ڴ���������������
}


void CFalconDlg::OnMenuOpenDevice()
{
	// TODO: �ڴ���������������
}


void CFalconDlg::OnMenuExit()
{
	// TODO: �ڴ���������������
}


void CFalconDlg::OnMenuPlay()
{
	// TODO: �ڴ���������������
}


void CFalconDlg::OnMenuPause()
{
	// TODO: �ڴ���������������
}


void CFalconDlg::OnMenuStop()
{
	// TODO: �ڴ���������������
}


void CFalconDlg::OnMenuPreview()
{
	// TODO: �ڴ���������������
}


void CFalconDlg::OnMenuNext()
{
	// TODO: �ڴ���������������
}


void CFalconDlg::ShowAboutDialog()
{
	// TODO: �ڴ���������������
	CAboutDlg dlgAbout;
	dlgAbout.DoModal();
}


void CFalconDlg::OnMenuContainer()
{
	// TODO: �ڴ���������������
}


void CFalconDlg::OnMenuCodec()
{
	// TODO: �ڴ���������������
}


void CFalconDlg::OnViewPlaylist()
{
	// TODO: �ڴ���������������
}


void CFalconDlg::OnViewConsole()
{
	// TODO: �ڴ���������������
}


void CFalconDlg::OnViewControl()
{
	// TODO: �ڴ���������������
}