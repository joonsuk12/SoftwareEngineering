#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Product
{
private:
    string seller_ID;
    int total_assessment=0;
    int assess_count=0;
    double average=0;
    string product_name;
    string company_name;
    int price;
    int stock;
    int now_left;

public:
    Product();
    Product(string id, string productname, string companyname, int price, int stock, double avg);
    void addProductInfo(string id, string productname, string companyname, int price, int stock);
    string getProducts();    //등록상품조회 출력함수
    string getProductsSold();    //판매완료상품조회 출력함수
    string getProductsSearch();  //서치를 위한 출력함수
    string getProductsPurchased();   //상품구매내역조회 출력함수
    string getProductsPurchase();    //구매 출력 함수
    string getProductsAssess();  //평가 출력 함수
    string getProductsStatistics(); //판매통계 출력 함수
    void purchaseProduct();
    void assessProduct(int assessment);
    int compareName(string productname);
    bool isSoldOut();
    int totalSold();
    string getName();
};