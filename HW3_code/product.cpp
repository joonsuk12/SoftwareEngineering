#include "product.h"

Product::Product(){}

Product::Product(string id, string productname, string companyname, int price, int stock, double avg){
    this->seller_ID = id;
    this->product_name = productname;
    this->company_name = companyname;
    this->price = price;
    this->stock = stock;
    this->average = avg;
}

void Product::addProductInfo(string id, string productname, string companyname, int price, int stock){
    this->seller_ID = id;
    this->product_name = productname;
    this->company_name = companyname;
    this->price = price;
    this->stock = stock;
    this->now_left = stock;
    this->average = 0;
}

string Product::getProducts(){
    string st_price = to_string(price);
    string st_left = to_string(now_left);
    string info = product_name + " " + company_name + " " + st_price + " " + st_left;
    return info;
}

string Product::getProductsSold()
{
    string st_price = to_string(price);
    string st_stock = to_string(stock);
    string st_avg = to_string(average);
    string info = product_name + " " + company_name + " " + st_price + " " + st_stock + " " + st_avg;
    return info;
}

string Product::getProductsSearch(){
    string st_price = to_string(price);
    string st_left = to_string(now_left);
    string st_average = to_string(average);
    string info = seller_ID + " " + product_name + " " + company_name + " " + st_price + " " + st_left+" "+st_average;
    return info;
}

string Product::getProductsPurchased(){
    string st_price = to_string(price);
    string st_left = to_string(now_left);
    string st_average = to_string(average);
    string info = seller_ID + " " + product_name + " " + company_name + " " + st_price + " " + st_left + " " + st_average;
    return info;
}

string Product::getProductsPurchase(){
    string info = seller_ID + " " + product_name;
    return info;
}

string Product::getProductsAssess(){
    string st_average= to_string(average);
    string info = seller_ID + " " + product_name+" "+st_average;
    return info;
}

string Product::getProductsStatistics(){
    int total = price * (stock - now_left);
        string totalSale = to_string(total);
        string avg = to_string(average);
        string info = product_name + " " + totalSale + " " + avg;
        return info;
}

void Product::purchaseProduct(){
    this->now_left--;
}

void Product::assessProduct(int assessment){
    this->total_assessment+=assessment;
    this->assess_count++;
    average=double(total_assessment)/double((this->assess_count));
}

int Product::compareName(string productname){
    if(productname.compare(this->product_name)==0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
} 

bool Product::isSoldOut(){
    if (this->now_left == 0) //판매 완료
        return true;
    else                    //하나도 안 팔림
        return false;
}

int Product::totalSold(){
    return stock - now_left;
}

string Product::getName(){
    return product_name;
}
