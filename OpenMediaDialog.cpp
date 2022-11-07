// OpenMediaDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "Falcon.h"
#include "OpenMediaDialog.h"
#include "afxdialogex.h"


// OpenMediaDialog 对话框

IMPLEMENT_DYNAMIC(OpenMediaDialog, CDialogEx)

OpenMediaDialog::OpenMediaDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DLG_OPENMEDIA, pParent)
{

}

OpenMediaDialog::~OpenMediaDialog()
{
}

void OpenMediaDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(OpenMediaDialog, CDialogEx)
END_MESSAGE_MAP()


// OpenMediaDialog 消息处理程序
