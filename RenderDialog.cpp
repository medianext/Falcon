// RenderDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Falcon.h"
#include "RenderDialog.h"
#include "afxdialogex.h"


// RenderDialog �Ի���

IMPLEMENT_DYNAMIC(RenderDialog, CDialogEx)

RenderDialog::RenderDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_RENDER_DIALOG, pParent)
{

}

RenderDialog::~RenderDialog()
{
}

void RenderDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(RenderDialog, CDialogEx)
END_MESSAGE_MAP()


// RenderDialog ��Ϣ�������
