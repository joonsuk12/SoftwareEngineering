#pragma once
#include "buyercontrol.h"
#include <fstream>
#include <string>

//상품 검색 UI
class SearchProductUI
{
private:
    SearchProduct *search_product;
    Product *finded_product;
    string info;
    string product_name;

public:
    SearchProductUI(SearchProduct *search_product);
    void startInterface(ostream &writeFile);
    void searchProduct(istream &readFile, ostream &writeFile);
};

//상품 구매 UI
class PurchaseProductUI
{
private:
    PurchaseProduct *purchase_product;
    Product *finded_product;
    string info;

public:
    PurchaseProductUI(PurchaseProduct *purchase_product);
    void startInterface(ostream &writeFile);
    void purchaseProduct(istream &readFile, ostream &writeFile);
};

//상품 구매 내역 조회 UI
class ViewPurchasedProductsUI
{
private:
    ViewPurchasedProducts *purchased_product;
    vector<Product *> purchased_product_list;
    vector<string> info_list;

public:
    ViewPurchasedProductsUI(ViewPurchasedProducts *purchased_product);
    void startInterface(ostream &writeFile);
    void purchasedProducts(ostream &writeFile);
};

//상품 구매만족도 평가 UI
class ProductAssessmentUI
{
private:
    ProductAssessment *product_assessment;
    Product *finded_product;
    Product *assessed_product;
    string product_name;
    string info;
    int assessment;

public:
    ProductAssessmentUI(ProductAssessment *product_assessment);
    void startInterface(ostream &writeFile);
    void productAssessment(istream &readFile, ostream &writeFile);
};
