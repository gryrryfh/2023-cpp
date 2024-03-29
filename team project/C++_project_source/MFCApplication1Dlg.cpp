
// MFCApplication1Dlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"
#include "CNewWindow1.h"
#include "CNewWindow2.h"
#include "CNewWindow3.h"
#include "CNewWindow4.h"
#include "CNewWindow5.h"
#include "CNewWindow6.h"
#include "CNewWindow7.h"
#include "CNewWindow8.h"
#include "CNewWindow9.h"
#include "CNewWindow10.h"
#include "Seach.h"
#include "CNewWindow11.h"
#include "CNewWindow12.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
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


// CMFCApplication1Dlg dialog



CMFCApplication1Dlg::CMFCApplication1Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION1_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, combo1);
	DDX_Control(pDX, IDC_COMBO2, combo2);
}

BEGIN_MESSAGE_MAP(CMFCApplication1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_CBN_SELCHANGE(IDC_COMBO1, &CMFCApplication1Dlg::OnCbnSelchangeCombo1)
	ON_CBN_SELCHANGE(IDC_COMBO2, &CMFCApplication1Dlg::OnCbnSelchangeCombo2)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication1Dlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CMFCApplication1Dlg message handlers

BOOL CMFCApplication1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	combo1.AddString(_T("고객"));
	combo1.AddString(_T("주문"));
	combo1.AddString(_T("상품"));

	combo2.AddString(_T("추가"));
	combo2.AddString(_T("수정"));
	combo2.AddString(_T("삭제"));
	combo2.AddString(_T("조회"));


	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFCApplication1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCApplication1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication1Dlg::OnCbnSelchangeCombo1()
{
	// TODO: Add your control notification handler code here
	
	

}


void CMFCApplication1Dlg::OnCbnSelchangeCombo2()
{
	// TODO: Add your control notification handler code here
	
	

}


void CMFCApplication1Dlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here

	int selectedIndex1 = combo1.GetCurSel();
	int selectedIndex2 = combo2.GetCurSel();
	if (selectedIndex1 == 0 && selectedIndex2 == 0) {
		
		CNewWindow4* newWindow4 = new CNewWindow4();
		newWindow4->Create(IDD_DIALOG4, this);
		newWindow4->ShowWindow(SW_SHOW);
	}
	if (selectedIndex1 == 0 && selectedIndex2 == 1) {
		
		CNewWindow8* newWindow8 = new CNewWindow8();
		newWindow8->Create(IDD_DIALOG8, this);
		newWindow8->ShowWindow(SW_SHOW);
	}

	if (selectedIndex1 == 0 && selectedIndex2 == 2) {
		Seach* newWindow7 = new Seach();
		newWindow7->Create(IDD_DIALOG7, this);
		newWindow7->ShowWindow(SW_SHOW);
	}
	if (selectedIndex1 == 0 && selectedIndex2 == 3) {
		CNewWindow1* newWindow1 = new CNewWindow1();
		newWindow1->Create(IDD_DIALOG1, this);
		newWindow1->ShowWindow(SW_SHOW);

	}
	if (selectedIndex1 == 1 && selectedIndex2 == 0) {
		CNewWindow5* newWindow5 = new CNewWindow5();
		newWindow5->Create(IDD_DIALOG5, this);
		newWindow5->ShowWindow(SW_SHOW);
	}
	if (selectedIndex1 == 1 && selectedIndex2 == 1) {
		CNewWindow9* newWindow9 = new CNewWindow9();
		newWindow9->Create(IDD_DIALOG9, this);
		newWindow9->ShowWindow(SW_SHOW);
	}
	if (selectedIndex1 == 1 && selectedIndex2 == 2) {
		CNewWindow11* newWindow11 = new CNewWindow11();
		newWindow11->Create(IDD_DIALOG11, this);
		newWindow11->ShowWindow(SW_SHOW);
	}
	if (selectedIndex1 == 1 && selectedIndex2 == 3) {
		CNewWindow2* newWindow2 = new CNewWindow2();
		newWindow2->Create(IDD_DIALOG2, this);
		newWindow2->ShowWindow(SW_SHOW);
	}

	if (selectedIndex1 == 2 && selectedIndex2 == 0) {
		CNewWindow6* newWindow6 = new CNewWindow6();
		newWindow6->Create(IDD_DIALOG6, this);
		newWindow6->ShowWindow(SW_SHOW);
	}
	if (selectedIndex1 == 2 && selectedIndex2 == 1) {
		CNewWindow10* newWindow10 = new CNewWindow10();
		newWindow10->Create(IDD_DIALOG10, this);
		newWindow10->ShowWindow(SW_SHOW);
	}
	if (selectedIndex1 == 2 && selectedIndex2 == 2) {
		CNewWindow12* newWindow12 = new CNewWindow12();
		newWindow12->Create(IDD_DIALOG12, this);
		newWindow12->ShowWindow(SW_SHOW);
	}
	if (selectedIndex1 == 2 && selectedIndex2 == 3) {
		CNewWindow3* newWindow3 = new CNewWindow3();
		newWindow3->Create(IDD_DIALOG3, this);
		newWindow3->ShowWindow(SW_SHOW);
	}

}
