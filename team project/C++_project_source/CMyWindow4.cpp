// CMyWindow4.cpp : implementation file
//

#include "pch.h"
#include "MFCApplication1.h"
#include "afxdialogex.h"
#include "CMyWindow4.h"


// CMyWindow4 dialog

IMPLEMENT_DYNAMIC(CMyWindow4, CDialogEx)

CMyWindow4::CMyWindow4(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG4, pParent)
{

}

CMyWindow4::~CMyWindow4()
{
}

void CMyWindow4::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CMyWindow4, CDialogEx)
END_MESSAGE_MAP()


// CMyWindow4 message handlers
