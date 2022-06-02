#include "buyerUI.h"

/*
상품 정보 검색 UI
*/
SearchProductUI::SearchProductUI(SearchProduct *search_product) : search_product(search_product) {}
void SearchProductUI::startInterface(ostream &writeFile)
{
    writeFile << "4.1. 상품 정보 검색" << endl;
    if (finded_product != NULL)
    {
        writeFile << "> " << info << endl
                  << endl;
    }
}
void SearchProductUI::searchProduct(istream &readFile, ostream &writeFile)
{
    readFile >> product_name;
    info = search_product->searchProduct(product_name);
    startInterface(writeFile);
    return;
}

/*
상품 구매 UI
*/
PurchaseProductUI::PurchaseProductUI(PurchaseProduct *purchase_product) : purchase_product(purchase_product) {}
void PurchaseProductUI::startInterface(ostream &writeFile)
{
    writeFile << "4.2. 상품 구매" << endl;
    if (finded_product != 0)
    {
        writeFile << "> " << info << endl
                  << endl;
    }
}
void PurchaseProductUI::purchaseProduct(istream &readFile, ostream &writeFile)
{
    info = purchase_product->purchaseProduct();
    startInterface(writeFile);
}

/*
상품 구매 내역 조회 UI
*/
ViewPurchasedProductsUI::ViewPurchasedProductsUI(ViewPurchasedProducts *purchased_product) : purchased_product(purchased_product) {}
void ViewPurchasedProductsUI::startInterface(ostream &writeFile)
{
    writeFile << "4.3 상품 구매 내역 조회" << endl;
    for (int i = 0; i < info_list.size(); i++)
    {
        writeFile << "> " << info_list[i] << endl;
    }
    writeFile << endl;
}
void ViewPurchasedProductsUI::purchasedProducts(ostream &writeFile)
{
    info_list = purchased_product->showPurchasedProducts();
    startInterface(writeFile);
}

/*
상품 구매만족도 평가 UI
*/
ProductAssessmentUI::ProductAssessmentUI(ProductAssessment *product_assessment) : product_assessment(product_assessment) {}
void ProductAssessmentUI:: startInterface(ostream &writeFile)
{
    writeFile << "4.4 상품 구매만족도 평가" << endl;
    writeFile << "> " << info << endl
              << endl;
}
void ProductAssessmentUI::productAssessment(istream &readFile, ostream &writeFile)
{
    readFile >> product_name >> assessment;
    info = product_assessment->productAssessment(product_name, assessment);
    startInterface(writeFile);
}