#pragma once
#include <fstream>
#include "member.h"
#include "seller.h"

//판매 상품 등록 UI
class AddProductUI{
private:
    AddProduct* addproduct;
    string product_name;
    string company_name;
    int price;
    int stock;
    int avg;

public:
    AddProductUI(AddProduct* addproduct);
    void addProduct(Member* mem,istream& readFile, ostream& writeFile);
    void startInterface(ostream& writeFile);
};

//판매 상품 조회 UI
class MyProductsUI{
private:
    MyProducts* myproducts;
    vector<Product*> sell_product_list;
    vector<string> info;
public:
    MyProductsUI(MyProducts* myproducts);
    void showMyProducts(ostream& writeFile);
    void startInterface(ostream& writeFile);
};

//판매 완료 상품 조회 UI
class SoldProductsUI{
private:
    SoldProducts* soldproducts;
    vector<Product*> sold_product_list;
    vector<string> info;
public:
    SoldProductsUI(SoldProducts* soldproducts);
    void showSoldProducts(ostream& writeFile);
    void startInterface(ostream& writeFile);

};

//상품 판매 통계 UI
class SaleStatisticsUI{
private:
    SaleStatistics* salestatistics;
    vector<Product*> productList;
    vector<string> info;
public:
    SaleStatisticsUI(SaleStatistics* stat);
    void showSaleStatistics(ostream& writeFile);
    void startInterface(ostream& writeFile);
};