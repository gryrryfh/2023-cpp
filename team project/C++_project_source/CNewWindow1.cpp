	// CNewWindow1.cpp : implementation file
	//

	#include "pch.h"
	#include "MFCApplication1.h"
	#include "afxdialogex.h"
	#include "CNewWindow1.h"
	#include "classDefine.h"
	#include <iostream>
	#include <string>
	#include "mysql_driver.h" // MySQL Connector/C++ 관련 헤더 파일 추가
	#include "mysql_connection.h"
	#include <cppconn/prepared_statement.h>






	Manager::Manager() {}

	Customer::Customer(string _customerName, string _address, string _contact) {
		customerName = _customerName;
		address = _address;
		contact = _contact;
	}


	
	

	



	string Customer::getCustomerName() {
		return customerName;
	}
	string Customer::getAddress() {
		return address;
	}
	string Customer::getContact() {
		return contact;
	}

	


	void Manager::addCustomer(Customer c) {
		try {
			sql::mysql::MySQL_Driver* driver;
			driver = sql::mysql::get_mysql_driver_instance();
			string server = "tcp://localhost:3306"; // 서버 주소와 포트 번호
			string username = "root"; // 사용자 이름
			string password = "123456"; // 비밀번호
			sql::Connection* conn;
			conn = driver->connect(server, username, password);
			conn->setSchema("my_database");
			string sql = "INSERT INTO 고객 (이름, 주소, 연락처) VALUES (?, ?, ?)";
			sql::PreparedStatement* pstmt = conn->prepareStatement(sql);
			pstmt->setString(1, c.getCustomerName());
			pstmt->setString(2, c.getAddress());
			pstmt->setString(3, c.getContact());

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


	

	// CNewWindow1 dialog



	IMPLEMENT_DYNAMIC(CNewWindow1, CDialogEx)

	CNewWindow1::CNewWindow1(CWnd* pParent /*=nullptr*/)
		: CDialogEx(IDD_DIALOG1, pParent)
	{

	}

	CNewWindow1::~CNewWindow1()
	{
	}

	void CNewWindow1::DoDataExchange(CDataExchange* pDX)
	{
		CDialogEx::DoDataExchange(pDX);
		DDX_Control(pDX, IDC_BUTTON1, customerInsertButton);
		DDX_Control(pDX, IDC_EDIT2, customerName);
		DDX_Control(pDX, IDC_EDIT1, customerAddress);
		DDX_Control(pDX, IDC_EDIT3, customerContact);
	}


	BEGIN_MESSAGE_MAP(CNewWindow1, CDialogEx)
		ON_EN_CHANGE(IDC_EDIT1, &CNewWindow1::OnEnChangeEdit1)
		ON_EN_CHANGE(IDC_EDIT2, &CNewWindow1::OnEnChangeEdit2)
		ON_EN_CHANGE(IDC_EDIT3, &CNewWindow1::OnEnChangeEdit3)
		ON_BN_CLICKED(IDC_BUTTON1, &CNewWindow1::OnBnClickedButton1)
	END_MESSAGE_MAP()



	// CNewWindow1 message handlers


	void CNewWindow1::OnEnChangeEdit1()
	{
		// TODO:  If this is a RICHEDIT control, the control will not
		// send this notification unless you override the CDialogEx::OnInitDialog()
		// function and call CRichEditCtrl().SetEventMask()
		// with the ENM_CHANGE flag ORed into the mask.

		// TODO:  Add your control notification handler code here
	}


	void CNewWindow1::OnEnChangeEdit2()
	{
		// TODO:  If this is a RICHEDIT control, the control will not
		// send this notification unless you override the CDialogEx::OnInitDialog()
		// function and call CRichEditCtrl().SetEventMask()
		// with the ENM_CHANGE flag ORed into the mask.

		// TODO:  Add your control notification handler code here




	}


	void CNewWindow1::OnEnChangeEdit3()
	{
		// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
		// CDialogEx::OnInitDialog() 함수를 재지정 
		//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
		// 이 알림 메시지를 보내지 않습니다.

		// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
	}
	void insertCustomer(Customer c) {
		try {
			sql::mysql::MySQL_Driver* driver;
			sql::Connection* con;

			driver = sql::mysql::get_mysql_driver_instance();
			con = driver->connect("tcp://localhost:3306", "root", "123456");

			con->setSchema("my_database");

			string sql = "INSERT INTO 고객 (이름, 주소, 연락처) VALUES (?, ?, ?)";
			sql::PreparedStatement* pstmt = con->prepareStatement(sql);
			pstmt->setString(1, c.getCustomerName());
			pstmt->setString(2, c.getAddress());
			pstmt->setString(3, c.getContact());

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



	void CNewWindow1::OnBnClickedButton1()
	{
	
		// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

			// Edit Control에서 입력된 값을 가져옴
			
		CString customerNameStr;
			customerName.GetWindowText(customerNameStr);
			CString customerAddressStr;
			customerAddress.GetWindowText(customerAddressStr);
			CString customerContactStr;
			customerContact.GetWindowText(customerContactStr);

			// CString 값을 string으로 변환
			std::string name = CT2A(customerNameStr);
			std::string address = CT2A(customerAddressStr);
			std::string contact = CT2A(customerContactStr);

			// Customer 객체 생성
			Customer customer(name, address, contact);

			// Manager 객체 생성
			Manager manager;

			// MySQL 서버로 고객 정보 전송
			manager.addCustomer(customer);
			
			EndDialog(IDOK);
		
		}




		// 이후에 realCustomerName 등 변수를 사용하여 원하는 작업을 수행합니다.
	