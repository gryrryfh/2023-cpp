// CNewWindow6.cpp : implementation file
//

#include "pch.h"
#include "MFCApplication1.h"
#include "afxdialogex.h"
#include "CNewWindow6.h"
#include "classDefine.h"

void Manager::deleteOrder(Order o) {
	try {
		sql::mysql::MySQL_Driver* driver;
		driver = sql::mysql::get_mysql_driver_instance();
		string server = "tcp://localhost:3306"; // 서버 주소와 포트 번호
		string username = "root"; // 사용자 이름
		string password = "123456"; // 비밀번호
		sql::Connection* conn;
		conn = driver->connect(server, username, password);
		conn->setSchema("my_database");
		string sql = "DELETE FROM 주문 WHERE 고객이름=? AND 제품명=?";
		sql::PreparedStatement* pstmt = conn->prepareStatement(sql);
		pstmt->setString(1, o.getOrderName());
		pstmt->setString(2, o.getOrderProduct());

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


// CNewWindow6 dialog

IMPLEMENT_DYNAMIC(CNewWindow6, CDialogEx)

CNewWindow6::CNewWindow6(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG6, pParent)
{

}

CNewWindow6::~CNewWindow6()
{
}

void CNewWindow6::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT3, customerName);
	DDX_Control(pDX, IDC_EDIT1, productName);
}


BEGIN_MESSAGE_MAP(CNewWindow6, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CNewWindow6::OnBnClickedButton1)
END_MESSAGE_MAP()


// CNewWindow6 message handlers


void CNewWindow6::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	CString customerNameStr;
	customerName.GetWindowText(customerNameStr);

	CString productNametStr;
	productName.GetWindowText(productNametStr);

	// CString 값을 string으로 변환
	std::string name = CT2A(customerNameStr);
	std::string productName = CT2A(productNametStr);

	// Customer 객체 생성
	Order order(name, productName, "d"); 

	// Manager 객체 생성
	Manager manager;

	// MySQL 서버로 고객 정보 전송
	manager.deleteOrder(order);

	EndDialog(IDOK);
}
