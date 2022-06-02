#pragma once
#include "member.h"
#include "productlist.h"

//상품 검색
class SearchProduct
{
private:
    int user_id;
    Member *member;
    string info;
    Product *product;
    Product *finded_product;
    ProductList *all_product_list;

public:
    SearchProduct(Member *mem, ProductList *list);
    string searchProduct(string pName);
};

//상품 구매
class PurchaseProduct
{
private:
    int user_id;
    Member *member;
    Product *product;
    Product *finded_product;
    ProductList *all_product_list;
    string info;

public:
    PurchaseProduct(Member *mem, ProductList *list);
    string purchaseProduct();
};

//상품 구매 내역 조회
class ViewPurchasedProducts
{
private:
    Member *member;
    vector<Product *> purchased_product_list;
    vector<string> infoList;

public:
    ViewPurchasedProducts(Member *mem);
    vector<string> showPurchasedProducts();
};

//상품 구매만족도 평가
class ProductAssessment
{
private:
    Member *member;
    Product *assessedproduct;
    string info;

public:
    ProductAssessment(Member *mem);
    string productAssessment(string productname, int assessment);
};
