#pragma once


// RenderDialog �Ի���

class RenderDialog : public CDialogEx
{
	DECLARE_DYNAMIC(RenderDialog)

public:
	RenderDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~RenderDialog();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_RENDER_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
