
// 2dTo3d_testDlg.h : ��� ����
//

#pragma once
#include "afxwin.h"


// CMy2dTo3d_testDlg ��ȭ ����
class CMy2dTo3d_testDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CMy2dTo3d_testDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY2DTO3D_TEST_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOpen();
	CStatic picture2D;
	CStatic picture3D;
};
