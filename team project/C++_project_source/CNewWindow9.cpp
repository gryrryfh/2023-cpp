// CNewWindow9.cpp : implementation file
//

#include "pch.h"
#include "MFCApplication1.h"
#include "afxdialogex.h"
#include "CNewWindow9.h"
#include "classDefine.h"

void Manager::updateProduct(Product p, string a) {
	try {
		sql::mysql::MySQL_Driver* driver;
		sql::Connection* con;

		driver = sql::mysql::get_mysql_driver_instance();
		con = driver->connect("tcp://localhost:3306", "root", "123456");

		con->setSchema("my_database");

		string sql = "UPDATE 상품 SET 상품명=?, 가격=?  WHERE 상품명=?";
		sql::PreparedStatement* pstmt = con->prepareStatement(sql);
		pstmt->setString(1, p.getProductName());
		pstmt->setString(2, p.getPrice());
		pstmt->setString(3, a);
		

		pstmt->executeUpdate();

		delete pstmt;
		delete con;

		cout << "고객 정보가 성공적으로 삽입되었습니다." << endl;
	}
	catch (sql::SQLException& e) {
		CString message;
		message.Format(L"SQLException: %hs", e.what());
		AfxMessageBox(message);
	}
}

// CNewWindow9 dialog

IMPLEMENT_DYNAMIC(CNewWindow9, CDialogEx)

CNewWindow9::CNewWindow9(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG9, pParent)
{

}

CNewWindow9::~CNewWindow9()
{
}

void CNewWindow9::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT3, modifyProduct);
	DDX_Control(pDX, IDC_EDIT1, productName);
	DDX_Control(pDX, IDC_EDIT2, price);
}


BEGIN_MESSAGE_MAP(CNewWindow9, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT3, &CNewWindow9::OnEnChangeEdit3)
	ON_EN_CHANGE(IDC_EDIT1, &CNewWindow9::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT2, &CNewWindow9::OnEnChangeEdit2)
	ON_BN_CLICKED(IDC_BUTTON1, &CNewWindow9::OnBnClickedButton1)
END_MESSAGE_MAP()


// CNewWindow9 message handlers


void CNewWindow9::OnEnChangeEdit3()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CNewWindow9::OnEnChangeEdit1()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CNewWindow9::OnEnChangeEdit2()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CNewWindow9::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	CString productNameStr;
	productName.GetWindowText(productNameStr);
	CString priceStr;
	price.GetWindowText(priceStr);
	CString modifyProductStr;
	modifyProduct.GetWindowText(modifyProductStr);

	

	// CString 값을 string으로 변환
	std::string name1 = CT2A(productNameStr);
	std::string price1 = CT2A(priceStr);
	std::string modify1 = CT2A(modifyProductStr);
	

	// Customer 객체 생성
	Product product(name1, price1); 

	// Manager 객체 생성
	Manager manager;

	// MySQL 서버로 고객 정보 전송
	manager.updateProduct(product, modify1);

	EndDialog(IDOK);
}
