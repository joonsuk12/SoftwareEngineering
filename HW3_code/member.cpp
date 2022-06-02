#include "member.h"

Member::Member(){}
Member::Member(string name, string resident_number, string id, string password){
    this->name = name;
    this->resident_number = resident_number;
    this->id = id;
    this->password = password;
}

vector<Product*> Member::listSaleProduct(){
    return sell_product_list;
}

vector<Product*> Member::listPurchasedProduct(){
    return purchased_roduct_list;
}

void Member::addSellProduct(Product* prod){
    sell_product_list.push_back(prod);
}

void Member::addPurchasedProduct(Product* prod){
    purchased_roduct_list.push_back(prod);
}

Product* Member::purchaseProduct(){
    finded_product->purchaseProduct();
    return finded_product;
}

Product* Member::findProduct(string productname){
    for (int i = 0; i < sell_product_list.size(); i++)
    {
        if (sell_product_list[i]->compareName(productname)==1)
        {
            finded_product=sell_product_list[i];
            return sell_product_list[i];
        }
    }
    return NULL;
}

Product* Member::putAssessment(string productname, int assessment){
    for(int i=0;i<purchased_roduct_list.size();i++)
    {
        if(purchased_roduct_list[i]->compareName(productname))
        {
            assessed_product=purchased_roduct_list[i];
            assessed_product->assessProduct(assessment);
            return assessed_product;
        }
    }
    return NULL;
}

string Member::getID(){
    return id;
}

string Member::getPW(){
    return password;
}