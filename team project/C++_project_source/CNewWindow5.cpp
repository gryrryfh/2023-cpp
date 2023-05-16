// CNewWindow5.cpp : implementation file
//

#include "pch.h"
#include "MFCApplication1.h"
#include "afxdialogex.h"
#include "CNewWindow5.h"
#include "classDefine.h"


void Manager::deleteProduct(Product p) {
	try {
		sql::mysql::MySQL_Driver* driver;
		driver = sql::mysql::get_mysql_driver_instance();
		string server = "tcp://localhost:3306"; // 서버 주소와 포트 번호
		string username = "root"; // 사용자 이름
		string password = "123456"; // 비밀번호
		sql::Connection* conn;
		conn = driver->connect(server, username, password);
		conn->setSchema("my_database");
		string sql = "DELETE FROM 상품 WHERE 상품명=?";
		sql::PreparedStatement* pstmt = conn->prepareStatement(sql);
		pstmt->setString(1, p.getProductName());
		

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




// CNewWindow5 dialog
IMPLEMENT_DYNAMIC(CNewWindow5, CDialogEx)

CNewWindow5::CNewWindow5(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG5, pParent)
{

}

CNewWindow5::~CNewWindow5()
{
}

void CNewWindow5::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, productName);
}


BEGIN_MESSAGE_MAP(CNewWindow5, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CNewWindow5::OnBnClickedButton1)
END_MESSAGE_MAP()


// CNewWindow5 message handlers


void CNewWindow5::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	CString productNameStr;
	productName.GetWindowText(productNameStr);

	

	// CString 값을 string으로 변환
	std::string name = CT2A(productNameStr);
	

	// Customer 객체 생성
	Product product(name, "a");

	// Manager 객체 생성
	Manager manager;

	// MySQL 서버로 고객 정보 전송
	manager.deleteProduct(product);

	EndDialog(IDOK);


}
