// CNewWindow11.cpp: 구현 파일
//

#include "pch.h"
#include "MFCApplication1.h"
#include "afxdialogex.h"
#include "CNewWindow11.h"
#include "classDefine.h"


// CNewWindow11 대화 상자

IMPLEMENT_DYNAMIC(CNewWindow11, CDialogEx)

CNewWindow11::CNewWindow11(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG11, pParent)
{
   

}

CNewWindow11::~CNewWindow11()
{
}

void CNewWindow11::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_LIST1, listCtrl);
}


BEGIN_MESSAGE_MAP(CNewWindow11, CDialogEx)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &CNewWindow11::OnLvnItemchangedList1)
    ON_BN_CLICKED(IDC_BUTTON1, &CNewWindow11::OnBnClickedButton1)
END_MESSAGE_MAP()


// CNewWindow11 메시지 처리기


void CNewWindow11::OnLvnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	*pResult = 0;
}


void CNewWindow11::OnBnClickedButton1()
{
    // TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
    try {
        sql::mysql::MySQL_Driver* driver;
        sql::Connection* con;
        sql::Statement* stmt;
        sql::ResultSet* res;

        // MySQL Connector/C++ 드라이버 로드
        driver = sql::mysql::get_mysql_driver_instance();

        // MySQL 데이터베이스에 연결
        con = driver->connect("tcp://127.0.0.1:3306", "root", "123456");
        con->setSchema("my_database");

        // 쿼리 실행을 위한 Statement 객체 생성
        stmt = con->createStatement();

        // 고객 테이블에서 데이터 가져오는 쿼리
        std::string query = "SELECT * FROM 상품";

        // 쿼리 실행
        res = stmt->executeQuery(query);

        // 리스트 컨트롤 초기화
        listCtrl.DeleteAllItems();
        listCtrl.DeleteColumn(0); // 기존의 열 삭제

        // 열 생성
        listCtrl.InsertColumn(0, _T("상품명"), LVCFMT_LEFT, 100);
        listCtrl.InsertColumn(1, _T("가격"), LVCFMT_LEFT, 150);

        // 고객 데이터를 리스트 컨트롤에 추가합니다.
        int index = 0;
        while (res->next()) {
            std::string name = res->getString("상품명");
            std::string address = res->getString("가격");

            listCtrl.InsertItem(index, CString(name.c_str()));
            listCtrl.SetItemText(index, 1, CString(address.c_str()));
            index++;
        }

        // 리소스 정리
        delete res;
        delete stmt;
        delete con;
    }
    catch (sql::SQLException& e) {
        // 예외 처리
        CString errorMessage;
        errorMessage.Format(_T("MySQL 오류: %s"), CString(e.what()));
        AfxMessageBox(errorMessage, MB_ICONERROR);
    }
}
