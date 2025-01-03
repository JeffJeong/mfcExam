﻿
// MFCProjectDlg.h: 헤더 파일
//

#include "CDlgImage.h"
#pragma once


// CMFCProjectDlg 대화 상자
class CMFCProjectDlg : public CDialogEx
{
// 생성입니다.
private:
	CImage m_image;
	BOOL validImgPos(int x, int y);
public:
	CDlgImage* m_pDlgImage;

	CMFCProjectDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCPROJECT_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnAction();
	afx_msg void OnBnClickedBtnDraw();
	afx_msg void OnBnClickedBtnOpen();
	void UpdateDisplay();
	void moveRect();
	void drawCircle(unsigned char* fm, int x, int y, int nRadius, int nGray);
	BOOL isInCircle(int i, int j, int nCenterX, int nCenterY, int nRadius);
	afx_msg void OnDestroy();
	CEdit m_endX;
	CEdit m_endY;
	CEdit m_startX;
	CEdit m_startY;
	int radius;
};
