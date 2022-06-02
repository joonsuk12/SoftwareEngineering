#pragma once
#include "product.h"
#include <vector>
#include <string>

using namespace std;

class Member
{
private:
    string id;
    string password;
    string resident_number;
    string name;
    Product* finded_product;
    Product* assessed_product;
    vector<Product *> sell_product_list;
    vector<Product *> purchased_roduct_list;

public:
    Member();
    Member(string name, string resident_number, string id, string password);
    vector<Product *> listSaleProduct();
    vector<Product *> listPurchasedProduct();
    void addSellProduct(Product *prod);
    void addPurchasedProduct(Product *prod);
    Product* purchaseProduct();
    Product *findProduct(string productname);
    Product *putAssessment(string productname, int assessment);
    string getID();
    string getPW();
};