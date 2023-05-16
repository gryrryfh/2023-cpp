// CNewWindow2.cpp : implementation file
//

#include "pch.h"
#include "MFCApplication1.h"
#include "afxdialogex.h"
#include "CNewWindow2.h"
#include "classDefine.h"
#include <string>





Product::Product(string _productName, string _price) {
	productName = _productName;
	price = _price;
}

string Product::getProductName() {
	return productName;
}

string Product::getPrice() {
	return price;
}









void Manager::addProduct(Product p) {
	try {
		sql::mysql::MySQL_Driver* driver;
		driver = sql::mysql::get_mysql_driver_instance();
		string server = "tcp://localhost:3306"; // 서버 주소와 포트 번호
		string username = "root"; // 사용자 이름
		string password = "123456"; // 비밀번호
		sql::Connection* conn;
		conn = driver->connect(server, username, password);
		conn->setSchema("my_database");
		string sql = "INSERT INTO 상품 (상품명, 가격) VALUES (?, ?)";
		sql::PreparedStatement* pstmt = conn->prepareStatement(sql);
		pstmt->setString(1, p.getProductName());
		pstmt->setString(2, p.getPrice());


		pstmt->executeUpdate();
		delete pstmt;
		delete conn;
	}
	catch (sql::SQLException& e) {
		CString message;
		message.Format(L"SQLException: %hs", e.what());
		AfxMessageBox(message);
	}
}
// CNewWindow2 dialog

IMPLEMENT_DYNAMIC(CNewWindow2, CDialogEx)

CNewWindow2::CNewWindow2(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG2, pParent)
{

}

CNewWindow2::~CNewWindow2()
{
}

void CNewWindow2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, productName);
	DDX_Control(pDX, IDC_EDIT2, productPrice);
}


BEGIN_MESSAGE_MAP(CNewWindow2, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CNewWindow2::OnBnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT1, &CNewWindow2::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT2, &CNewWindow2::OnEnChangeEdit2)
END_MESSAGE_MAP()


// CNewWindow2 message handlers



void CNewWindow2::OnEnChangeEdit1()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CNewWindow2::OnEnChangeEdit2()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
void CNewWindow2::OnBnClickedButton1()
{

	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString productNameStr;
	productName.GetWindowText(productNameStr);
	CString productPriceStr;
	productPrice.GetWindowText(productPriceStr);
	

	// CString 값을 string으로 변환
	std::string productName = CT2A(productNameStr);
	std::string price = CT2A(productPriceStr);
	

	// Customer 객체 생성
	Product product(productName, price);

	// Manager 객체 생성
	Manager manager;

	// MySQL 서버로 고객 정보 전송
	manager.addProduct(product);

	EndDialog(IDOK);
}

