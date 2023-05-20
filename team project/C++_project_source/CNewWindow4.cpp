// CNewWindow4.cpp : implementation file
//

#include "pch.h"
#include "MFCApplication1.h"
#include "afxdialogex.h"
#include "CNewWindow4.h"
#include "classDefine.h"

void Manager::deleteCustomer(Customer c) {
	try {
		sql::mysql::MySQL_Driver* driver;
		driver = sql::mysql::get_mysql_driver_instance();
		string server = "tcp://localhost:3306"; // 서버 주소와 포트 번호
		string username = "root"; // 사용자 이름
		string password = "123456"; // 비밀번호
		sql::Connection* conn;
		conn = driver->connect(server, username, password);
		conn->setSchema("my_database");
		string sql = "DELETE FROM 고객 WHERE 이름=? AND 연락처=?";
		sql::PreparedStatement* pstmt = conn->prepareStatement(sql);
		pstmt->setString(1, c.getCustomerName());
		pstmt->setString(2, c.getContact());

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



// CNewWindow4 dialog

IMPLEMENT_DYNAMIC(CNewWindow4, CDialogEx)

CNewWindow4::CNewWindow4(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG4, pParent)
{

}

CNewWindow4::~CNewWindow4()
{
}

void CNewWindow4::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, customerName);
	DDX_Control(pDX, IDC_EDIT2, contact);
}


BEGIN_MESSAGE_MAP(CNewWindow4, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CNewWindow4::OnBnClickedButton1)
END_MESSAGE_MAP()


// CNewWindow4 message handlers


void CNewWindow4::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString customerNameStr;
	customerName.GetWindowText(customerNameStr);
	
	CString customerContactStr;
	contact.GetWindowText(customerContactStr);

	// CString 값을 string으로 변환
	std::string name = CT2A(customerNameStr);
	std::string contact = CT2A(customerContactStr);

	// Customer 객체 생성
	Customer customer(name, "a", contact);

	// Manager 객체 생성
	Manager manager;

	// MySQL 서버로 고객 정보 전송
	manager.deleteCustomer(customer);

	EndDialog(IDOK);


}
