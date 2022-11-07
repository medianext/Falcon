// ControlDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "Falcon.h"
#include "ControlDialog.h"
#include "afxdialogex.h"


// ControlDialog 对话框

IMPLEMENT_DYNAMIC(ControlDialog, CDialogEx)

ControlDialog::ControlDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_CONTROL_DIALOG, pParent)
{

}

ControlDialog::~ControlDialog()
{
}

void ControlDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SLIDER_SEEK, m_SeekSlider);
}


BEGIN_MESSAGE_MAP(ControlDialog, CDialogEx)
	ON_BN_CLICKED(IDC_BTN_PLAY, &ControlDialog::OnPlay)
	ON_BN_CLICKED(IDC_BTN_PAUSE, &ControlDialog::OnPause)
	ON_BN_CLICKED(IDC_BTN_STOP, &ControlDialog::OnStop)
	ON_BN_CLICKED(IDC_BTN_PREVIEW, &ControlDialog::OnPreview)
	ON_BN_CLICKED(IDC_BTN_NEXT, &ControlDialog::OnNext)
	ON_WM_HSCROLL()
END_MESSAGE_MAP()


// ControlDialog 消息处理程序


BOOL ControlDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_SeekSlider.SetRange(0, 100);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void ControlDialog::OnPlay()
{
	// TODO: 在此添加控件通知处理程序代码
	OutputDebugString(TEXT(__FUNCTION__"\n"));
}


void ControlDialog::OnPause()
{
	// TODO: 在此添加控件通知处理程序代码
	OutputDebugString(TEXT(__FUNCTION__"\n"));
}


void ControlDialog::OnStop()
{
	// TODO: 在此添加控件通知处理程序代码
	OutputDebugString(TEXT(__FUNCTION__"\n"));
}


void ControlDialog::OnPreview()
{
	// TODO: 在此添加控件通知处理程序代码
	OutputDebugString(TEXT(__FUNCTION__"\n"));
}


void ControlDialog::OnNext()
{
	// TODO: 在此添加控件通知处理程序代码
	OutputDebugString(TEXT(__FUNCTION__"\n"));
}


void ControlDialog::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (&m_SeekSlider == (CSliderCtrl *)pScrollBar)
	{
		OutputDebugString(TEXT(__FUNCTION__"\n"));
	}

	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}
