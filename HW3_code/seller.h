#pragma once
#include "member.h"
#include "productlist.h"

bool compareSeller(Product* x, Product* y);

//판매 의류 등록 
class AddProduct{
private:
    Member* member;
    Product* product;
    ProductList* all_product_list;
public:
    AddProduct(Member* mem, ProductList* list);
    void addProduct(string sellerid, string pName, string cName, int price, int stock, double avg);
};

//판매 의류 조회
class MyProducts{
private:
    Member* member;
    vector<Product*> sell_product_list;
    vector<string> info;
public:
    MyProducts(Member* mem);
    vector<Product*> showMyProducts();
    vector<string> getInfo();
};

//판매 완료 상품 조회
class SoldProducts{
private:
    Member* member;
    vector<Product*> sell_product_list;
    vector<Product*> sold_product_list;
    vector<string> info;
public:
    SoldProducts(Member* mem);
    vector<Product*> showSoldProducts();
    vector<string> getInfo();
};

//상품 판매 통계
class SaleStatistics{
private:
    Member* member;
    vector<Product*> product_list;
    vector<string> info;
public:
    SaleStatistics(Member* mem);
    vector<Product*> showSaleStatistics();
    vector<string> getInfo();
};
