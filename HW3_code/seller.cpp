#include "seller.h"
#include "sellerUI.h"
#include "member.h"
#include "product.h"
#include <algorithm>

bool compareSeller(Product* x, Product* y){
    return x->getName() < y->getName();
}

/*
판매 의류 등록
*/
AddProduct::AddProduct(Member* mem, ProductList* list)
{
    this->member = mem;
    this->all_product_list = list;
    product = new Product();
}
void AddProduct::addProduct(string sellerid, string pName, string cName, int price, int stock, double avg)
{
    product->addProductInfo(sellerid, pName, cName, price, stock);
    member->addSellProduct(product);
    all_product_list->addAllProduct(product);
}


/*
판매 의류 조회
*/
MyProducts::MyProducts(Member* mem)
{
    this->member = mem;
}
vector<Product*> MyProducts::showMyProducts()
{
    sell_product_list = member->listSaleProduct();
    return sell_product_list;
}
vector<string> MyProducts::getInfo()
{
    for(int i=0; i<sell_product_list.size(); i++){
        info.push_back(sell_product_list[i]->getProducts());
    }
    return info;
}


/*
판매 완료 상품 조회
*/
SoldProducts::SoldProducts(Member* mem)
{
    this->member = mem;
}
vector<Product*> SoldProducts::showSoldProducts()
{
    sell_product_list = member->listSaleProduct();
    for(int i=0; i<sell_product_list.size(); i++){
        if(sell_product_list[i]->isSoldOut())
            sold_product_list.push_back(sell_product_list[i]);
    }
    sort(sold_product_list.begin(), sold_product_list.end(), compareSeller);
    return sold_product_list;
}
vector<string> SoldProducts::getInfo()
{
    for(int i = 0; i<sold_product_list.size(); i++){
        info.push_back(sold_product_list[i]->getProductsSold());
    }
    return info;
}


/*
판매 상품 통계
*/
SaleStatistics::SaleStatistics(Member* mem)
{
    this->member = mem;
}
vector<Product*> SaleStatistics::showSaleStatistics()
{
    product_list = member->listSaleProduct();
    return product_list;
}
vector<string> SaleStatistics::getInfo()
{
    for(int i=0; i<product_list.size(); i++){
        if(product_list[i]->totalSold() != 0){
            info.push_back(product_list[i]->getProductsStatistics());
        }
    }
    return info;
}