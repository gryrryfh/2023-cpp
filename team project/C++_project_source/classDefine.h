#ifndef MANAGER_H
#define MANAGER_H

#include <string>
#include <iostream>
#include "mysql_driver.h"
#include "mysql_connection.h"
#include <cppconn/prepared_statement.h>

using namespace std;

class Customer; // Customer 클래스의 선언 추가
class Product; 
class Order;

class Manager {
private:
    // Manager 클래스의 멤버 변수 및 함수
    sql::Connection* conn;
public:
    Manager();

    void addCustomer(Customer c);
    void addProduct(Product p); 
    void addOrder(Order o); 

    void updateCustomer(Customer c, string a); 
    void updateProduct(Product p, string a); 
    void updateOrder(Order o, string a, string b); 

    void deleteCustomer(Customer c); 
    void deleteProduct(Product p); 
    void deleteOrder(Order o); 

    // 나머지 멤버 함수들
};

class Customer {
private:
    string customerName;
    string address;
    string contact;

public:
    Customer(string _customerName, string _address, string _contact);

    string getCustomerName();

    string getAddress();

    string getContact();
};

class Product {
private:
    string productName;
    string price;

public:
    Product(string _productName, string _price);

    string getProductName();

    string getPrice();
};

class Order {
private:
    string orderCustomerName;
    string orderProductName;
    string quantity;

public:
    Order(string c, string p, string _quantity);
    string getOrderName(); 
    string getOrderProduct(); 
    string getOrderQuantity();
    
};

#endif // MANAGER_H
