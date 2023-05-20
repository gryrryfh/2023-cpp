// CNewWindow3.cpp : implementation file
//

#include "pch.h"
#include "MFCApplication1.h"
#include "afxdialogex.h"
#include "CNewWindow3.h"
#include "classDefine.h"
#include <string>

Order::Order(string c, string p, string _quantity) {
	orderCustomerName = c; 
	orderProductName = p;
	quantity = _quantity;
}

string Order::getOrderName() {
	return orderCustomerName; 
}

string Order::getOrderProduct() {
	return orderProductName; 
}

string Order::getOrderQuantity() {
	return quantity; 
}

void Manager::addOrder(Order o) {
	try {
		sql::mysql::MySQL_Driver* driver;
		driver = sql::mysql::get_mysql_driver_instance();
		string server = "tcp://localhost:3306"; // 서버 주소와 포트 번호
		string username = "root"; // 사용자 이름
		string password = "123456"; // 비밀번호
		sql::Connection* conn;
		conn = driver->connect(server, username, password);
		conn->setSchema("my_database");
		string sql = "INSERT INTO 주문 (고객이름, 제품명, 수량) VALUES (?, ?, ?)";
		sql::PreparedStatement* pstmt = conn->prepareStatement(sql);
		pstmt->setString(1, o.getOrderName());
		pstmt->setString(2, o.getOrderProduct());
		pstmt->setString(3, o.getOrderQuantity());

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


// CNewWindow3 dialog

IMPLEMENT_DYNAMIC(CNewWindow3, CDialogEx)

CNewWindow3::CNewWindow3(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG3, pParent)
{

}

CNewWindow3::~CNewWindow3()
{
}

void CNewWindow3::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT4, orderName);
	DDX_Control(pDX, IDC_EDIT5, orderProductName);
	DDX_Control(pDX, IDC_EDIT2, quantity);
}


BEGIN_MESSAGE_MAP(CNewWindow3, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CNewWindow3::OnBnClickedButton1)
END_MESSAGE_MAP()


// CNewWindow3 message handlers


void CNewWindow3::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	CString orderNameStr;
	orderName.GetWindowText(orderNameStr);
	CString orderProductNameStr;
	orderProductName.GetWindowText(orderProductNameStr);
	CString quantityStr;
	quantity.GetWindowText(quantityStr);

	// CString 값을 string으로 변환
	std::string orderName = CT2A(orderNameStr);
	std::string orderProduct = CT2A(orderProductNameStr);
	std::string quantity = CT2A(quantityStr);

	// Customer 객체 생성
	Order order(orderName, orderProduct, quantity);

	// Manager 객체 생성
	Manager manager;

	// MySQL 서버로 고객 정보 전송
	manager.addOrder(order);

	EndDialog(IDOK);
}
