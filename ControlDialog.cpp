// ControlDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Falcon.h"
#include "ControlDialog.h"
#include "afxdialogex.h"


// ControlDialog �Ի���

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


// ControlDialog ��Ϣ�������


BOOL ControlDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_SeekSlider.SetRange(0, 100);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}


void ControlDialog::OnPlay()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	OutputDebugString(TEXT(__FUNCTION__"\n"));
}


void ControlDialog::OnPause()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	OutputDebugString(TEXT(__FUNCTION__"\n"));
}


void ControlDialog::OnStop()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	OutputDebugString(TEXT(__FUNCTION__"\n"));
}


void ControlDialog::OnPreview()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	OutputDebugString(TEXT(__FUNCTION__"\n"));
}


void ControlDialog::OnNext()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	OutputDebugString(TEXT(__FUNCTION__"\n"));
}


void ControlDialog::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (&m_SeekSlider == (CSliderCtrl *)pScrollBar)
	{
		OutputDebugString(TEXT(__FUNCTION__"\n"));
	}

	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}
