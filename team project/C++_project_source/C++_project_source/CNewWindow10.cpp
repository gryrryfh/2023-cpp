// CNewWindow10.cpp : implementation file
//

#include "pch.h"
#include "MFCApplication1.h"
#include "afxdialogex.h"
#include "CNewWindow10.h"
#include "classDefine.h"

void Manager::updateOrder(Order o, string a, string b) {
	try {
		sql::mysql::MySQL_Driver* driver;
		sql::Connection* con;

		driver = sql::mysql::get_mysql_driver_instance();
		con = driver->connect("tcp://localhost:3306", "root", "123456");

		con->setSchema("my_database");

		string sql = "UPDATE 주문 SET 고객이름=?, 제품명=?, 수량=? WHERE 고객이름=? AND 제품명=?";
		sql::PreparedStatement* pstmt = con->prepareStatement(sql);
		pstmt->setString(1, o.getOrderName());
		pstmt->setString(2, o.getOrderProduct());
		pstmt->setString(3, o.getOrderQuantity());
		pstmt->setString(4, a);
		pstmt->setString(5, b); 

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




// CNewWindow10 dialog

IMPLEMENT_DYNAMIC(CNewWindow10, CDialogEx)

CNewWindow10::CNewWindow10(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG10, pParent)
{

}

CNewWindow10::~CNewWindow10()
{
}

void CNewWindow10::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT3, modifyCustomerName);
	DDX_Control(pDX, IDC_EDIT4, modifyProduct);
	DDX_Control(pDX, IDC_EDIT1, customerName);
	DDX_Control(pDX, IDC_EDIT2, productName);
	DDX_Control(pDX, IDC_EDIT5, quantity);
}


BEGIN_MESSAGE_MAP(CNewWindow10, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &CNewWindow10::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON1, &CNewWindow10::OnBnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT3, &CNewWindow10::OnEnChangeEdit3)
	ON_EN_CHANGE(IDC_EDIT4, &CNewWindow10::OnEnChangeEdit4)
	ON_EN_CHANGE(IDC_EDIT2, &CNewWindow10::OnEnChangeEdit2)
END_MESSAGE_MAP()


// CNewWindow10 message handlers


void CNewWindow10::OnEnChangeEdit1()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CNewWindow10::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	CString customerNameStr;
	customerName.GetWindowText(customerNameStr);
	CString productStr;
	productName.GetWindowText(productStr);
	CString quantityStr;
	quantity.GetWindowText(quantityStr);

	CString modifyName;
	modifyCustomerName.GetWindowText(modifyName);
	CString modifyProduct2;
	modifyProduct.GetWindowText(modifyProduct2);

	// CString 값을 string으로 변환
	std::string name = CT2A(customerNameStr);
	std::string address = CT2A(productStr);
	std::string contact = CT2A(quantityStr);
	std::string modify = CT2A(modifyName);
	std::string modifyProduct = CT2A(modifyProduct2); 

	// Customer 객체 생성
	Order order(name, address, contact);

	// Manager 객체 생성
	Manager manager;

	// MySQL 서버로 고객 정보 전송
	manager.updateOrder(order, modify, modifyProduct);

	EndDialog(IDOK);
}


void CNewWindow10::OnEnChangeEdit3()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CNewWindow10::OnEnChangeEdit4()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CNewWindow10::OnEnChangeEdit2()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
