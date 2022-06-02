#include "sellerUI.h"
#include "seller.h"
#include "member.h"
#include "product.h"
#include <string>

/*
판매 상품 등록 UI
*/
AddProductUI::AddProductUI(AddProduct* addproduct)
{
    this->addproduct = addproduct;
}
void AddProductUI::addProduct(Member* mem, istream& readFile, ostream& writeFile)
{
    readFile >> product_name >> company_name >> price >> stock;
    addproduct->addProduct(mem->getID(), product_name, company_name, price, stock, avg);
    startInterface(writeFile);
}
void AddProductUI::startInterface(ostream& writeFile)
{
    writeFile << "3.1. 판매 의류 등록" << endl;
    writeFile << "> " << product_name << " " << company_name <<
        " " << price << " " << stock << endl << endl;
}


/*
판매 상품 조회 UI
*/
MyProductsUI::MyProductsUI(MyProducts* myproducts)
{
    this->myproducts = myproducts;
}
void MyProductsUI::showMyProducts(ostream& writeFile)
{
    sell_product_list = myproducts->showMyProducts();
    info = myproducts->getInfo();
    startInterface(writeFile);
}
void MyProductsUI::startInterface(ostream& writeFile)
{
    writeFile << "3.2. 등록 상품 조회" << endl;
    for(int i=0; i<info.size(); i++){
        writeFile << "> " << info[i] << endl;
    }
    writeFile << endl;
}


/*
판매 완료 상품 조회 UI
*/
SoldProductsUI::SoldProductsUI(SoldProducts* soldproducts)
{
    this->soldproducts = soldproducts;
}
void SoldProductsUI::showSoldProducts(ostream& writeFile)
{
    sold_product_list = soldproducts->showSoldProducts();
    info = soldproducts->getInfo();
    startInterface(writeFile);
}
void SoldProductsUI::startInterface(ostream& writeFile)
{
    writeFile << "3.3 판매 완료 상품 조회" << endl;
    for(int i=0; i<info.size(); i++){
        writeFile << "> " << info[i] << endl;
    }
}


/*
상품 판매 통계 UI
*/
SaleStatisticsUI::SaleStatisticsUI(SaleStatistics* stat)
{
    this->salestatistics = stat;
}
void SaleStatisticsUI::showSaleStatistics(ostream& writeFile)
{
    productList = salestatistics->showSaleStatistics();
    info = salestatistics->getInfo();
    startInterface(writeFile);
}
void SaleStatisticsUI::startInterface(ostream& writeFile)
{
    writeFile << "5.1. 판매 상품 통계" << endl;
    for(int i=0; i<info.size(); i++){
            writeFile << "> " << info[i] << endl;
        }
    writeFile << endl;
}