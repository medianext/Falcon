#pragma once


// OpenMediaDialog �Ի���

class OpenMediaDialog : public CDialogEx
{
	DECLARE_DYNAMIC(OpenMediaDialog)

public:
	OpenMediaDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~OpenMediaDialog();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_OPENMEDIA };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
