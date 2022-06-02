#include "buyercontrol.h"

/*
상품 정보 검색 
*/
SearchProduct::SearchProduct(Member *mem, ProductList *list)
{
    this->member = mem;
    this->all_product_list = list;
    product = new Product();
}
string SearchProduct::searchProduct(string pName)
{
    finded_product = all_product_list->findProduct(pName);
    info = finded_product->getProductsSearch();
    return info;
}

/*
상품 구매
*/
PurchaseProduct::PurchaseProduct(Member *mem, ProductList *list)
{
    this->member = mem;
    this->all_product_list = list;
    product = new Product();
}
string PurchaseProduct::purchaseProduct()
{
    finded_product = all_product_list->purchaseProduct();
    member->addPurchasedProduct(finded_product);
    info = finded_product->getProductsPurchase();
    return info;
}

/*
상품 구매 내역 조회
*/
ViewPurchasedProducts::ViewPurchasedProducts(Member *mem)
{
    this->member = mem;
}
vector<string> ViewPurchasedProducts::showPurchasedProducts()
{
    for (int i = 0; i < member->listPurchasedProduct().size(); i++)
    {
        purchased_product_list.push_back(member->listPurchasedProduct()[i]);
    }
    for (int i = 0; i < purchased_product_list.size(); i++)
    {
        infoList.push_back(purchased_product_list[i]->getProductsPurchased());
    }
    return infoList;
}

/*
상품 구매만족도 평가
*/
ProductAssessment::ProductAssessment(Member *mem)
{
    this->member = mem;
}
string ProductAssessment::productAssessment(string productname, int assessment)
{
    assessedproduct = member->putAssessment(productname, assessment);
    info = assessedproduct->getProductsAssess();
    return info;
}