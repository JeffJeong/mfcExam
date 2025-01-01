
// MFCProjectDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "MFCProject.h"
#include "MFCProjectDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
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


// CMFCProjectDlg 대화 상자



CMFCProjectDlg::CMFCProjectDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCPROJECT_DIALOG, pParent)
{	

	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCProjectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_END_X, m_endX);
	DDX_Control(pDX, IDC_EDIT_END_Y, m_endY);
	DDX_Control(pDX, IDC_EDIT_START_X, m_startX);
	DDX_Control(pDX, IDC_EDIT_START_Y, m_startY);
}

BEGIN_MESSAGE_MAP(CMFCProjectDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_ACTION, &CMFCProjectDlg::OnBnClickedBtnAction)
	ON_BN_CLICKED(IDC_BTN_DRAW, &CMFCProjectDlg::OnBnClickedBtnDraw)
	ON_BN_CLICKED(IDC_BTN_OPEN, &CMFCProjectDlg::OnBnClickedBtnOpen)
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CMFCProjectDlg 메시지 처리기

BOOL CMFCProjectDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	m_pDlgImage = new CDlgImage;
	m_pDlgImage->Create(IDD_CDlgImage, this);
	
	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CMFCProjectDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CMFCProjectDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CMFCProjectDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

CString g_strFileImage = _T("C:\\image\\save.bmp");

void CMFCProjectDlg::OnBnClickedBtnDraw()
{
	//m_pDlgImage->ShowWindow(SW_SHOW);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	// Draw 버튼 클릭시 (x1, y1) 좌표를 중심으로하는 랜덤한 크기의 원을 그립니다.
	int nWidth = 640;
	int nHeight = 480;
	int nBpp = 8;
	if (m_image != NULL) {
		m_image.Destroy();
	}
	m_image.Create(nWidth, nHeight, nBpp);
	if (nBpp == 8) {
		static RGBQUAD rgb[256];
		for (int i = 0; i < 256; i++)
			rgb[i].rgbRed = rgb[i].rgbGreen = rgb[i].rgbBlue = i;
		m_image.SetColorTable(0, 256, rgb);
	}
	int nPitch = m_image.GetPitch();
	unsigned char* fm = (unsigned char*)m_image.GetBits();
	//시작좌표값 불러오는코드
	CString mText;
	m_startX.GetWindowText(mText);
	int nCircleX = _wtoi(mText.GetBuffer()); //중점 X좌표
	mText.ReleaseBuffer();
	m_startY.GetWindowText(mText);
	int nCircleY = _wtoi(mText.GetBuffer()); //중점 Y좌표
	mText.ReleaseBuffer();
	int rRange = ((nWidth - nCircleX) > (nHeight - nCircleY)) ? (nCircleX) : (nCircleY);
	int radius = rand() % rRange;
	//drawCircle(fm, nCircleX, nCircleY, radius, 60);

	//for (int j = 0; j < nHeight; j++) {
	//	for (int i = 0; i < nWidth; i++) {
	//		fm[j * nPitch + i] = (i % 0xff/2);
	//	}
	//}
	UpdateDisplay();

}



void CMFCProjectDlg::OnBnClickedBtnAction()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	// Action 버튼 클릭시 (x1, y1) 좌표에서 (x2, y2) 좌표로 일정 픽셀 간격으로 원을 이동시키며,
	// 이동할 때마다 실행파일이 위치한 폴더 내의 image 폴더에 bmp 또는 jpg(jpeg) 포맷으로 저장합니다.
	// 이 때 메인UI가 프리징 상태가 되지 않도록 합니다.
	for (int i = 0; i < 400; i++) {
		moveRect();
		Sleep(10);
	}
	
	//m_image.Save(g_strFileImage);
}


#include "CDlgImage.h"
void CMFCProjectDlg::OnBnClickedBtnOpen()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	// Open 버튼 클릭시 탐색기 창을 통해 이미지를 1개를 선택해서 불러오고 다이얼로그에 출력합니다.
	// 이 때 출력된 원의 중심 좌표에 X 모양을 그리고 좌표값을 같이 표시합니다.
	//if (m_image != NULL) {
	//	m_image.Destroy();
	//}
	//m_image.Load(g_strFileImage);
	//UpdateDisplay();
	CDlgImage dlg;
	dlg.DoModal();
}

void CMFCProjectDlg::UpdateDisplay() {
	CClientDC dc(this);
	m_image.Draw(dc, 0, 0);
}


void CMFCProjectDlg::moveRect() {
	static int nSttX = 0;
	static int nSttY = 0;
	int nGray = 120;
	int nWidth = m_image.GetWidth();
	int nHeight = m_image.GetHeight();
	int nPitch = m_image.GetPitch();
	int nRadius = 20;
	unsigned char* fm = (unsigned char*)m_image.GetBits();
	drawCircle(fm, nSttX, nSttY, nRadius, 0xff);
	drawCircle(fm, ++nSttX, ++nSttY, nRadius, nGray);

	UpdateDisplay();
	//CString strFile;
	//strFile.Format(_T("C:\\image\\image%d.jpg"), nSttX);
	//m_image.Save(strFile);
}

BOOL CMFCProjectDlg::validImgPos(int x, int y) {
	BOOL bRet = false;
	int nWidth = m_image.GetWidth();
	int nHeight = m_image.GetHeight();

	CRect rect(0, 0, nWidth, nHeight);
	return rect.PtInRect(CPoint(x, y));
}

void CMFCProjectDlg::drawCircle(unsigned char* fm, int x, int y, int nRadius, int nGray) {
	int nCenterX = x + nRadius;
	int nCenterY = y + nRadius;
	int nPitch = m_image.GetPitch();

	for (int j = y; j < y + nRadius * 2; j++) {
		for (int i = x; i < x + nRadius * 2; i++) {
			if(isInCircle(i,j, nCenterX, nCenterY, nRadius))
			fm[j * nPitch + i] = nGray;
		}
	}

}

BOOL CMFCProjectDlg::isInCircle(int i, int j, int nCenterX, int nCenterY, int nRadius) {
	bool bRet = false;
	double dX = i - nCenterX;
	double dY = j - nCenterY;
	double dDist = dX * dX + dY * dY;
	if (dDist < nRadius * nRadius) {
		bRet = true;
	}
	return bRet;
}

void CMFCProjectDlg::OnDestroy()
{
	CDialogEx::OnDestroy();
	delete m_pDlgImage;
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}