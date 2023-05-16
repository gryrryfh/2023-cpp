// CNewWindow8.cpp : implementation file
//

#include "pch.h"
#include "MFCApplication1.h"
#include "afxdialogex.h"
#include "CNewWindow8.h"
#include  "classDefine.h"


void Manager::updateCustomer(Customer c, string a) {
	try {
		sql::mysql::MySQL_Driver* driver;
		sql::Connection* con;

		driver = sql::mysql::get_mysql_driver_instance();
		con = driver->connect("tcp://localhost:3306", "root", "123456");

		con->setSchema("my_database");

		string sql = "UPDATE 고객 SET 이름=?, 주소=?, 연락처=? WHERE 이름=?";
		sql::PreparedStatement* pstmt = con->prepareStatement(sql);
		pstmt->setString(1, c.getCustomerName());
		pstmt->setString(2, c.getAddress());
		pstmt->setString(3, c.getContact());
		pstmt->setString(4, a);
		
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

// CNewWindow8 dialog

IMPLEMENT_DYNAMIC(CNewWindow8, CDialogEx)

CNewWindow8::CNewWindow8(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG8, pParent)
{

}

CNewWindow8::~CNewWindow8()
{
}

void CNewWindow8::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT4, targetName);
	DDX_Control(pDX, IDC_EDIT2, customerName);
	DDX_Control(pDX, IDC_EDIT3, customerAddress);
	DDX_Control(pDX, IDC_EDIT1, contact);
}


BEGIN_MESSAGE_MAP(CNewWindow8, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CNewWindow8::OnBnClickedButton1)
END_MESSAGE_MAP()


// CNewWindow8 message handlers


void CNewWindow8::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString customerNameStr;
	customerName.GetWindowText(customerNameStr);
	CString customerAddressStr;
	customerAddress.GetWindowText(customerAddressStr);
	CString customerContactStr;
	contact.GetWindowText(customerContactStr);
	
	CString modifyName; 
	targetName.GetWindowText(modifyName);

	// CString 값을 string으로 변환
	std::string name = CT2A(customerNameStr);
	std::string address = CT2A(customerAddressStr);
	std::string contact = CT2A(customerContactStr);
	std::string modify = CT2A(modifyName); 

	// Customer 객체 생성
	Customer customer(name, address, contact);

	// Manager 객체 생성
	Manager manager;

	// MySQL 서버로 고객 정보 전송
	manager.updateCustomer(customer,modify);

	EndDialog(IDOK);
}
