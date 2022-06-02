#pragma once
#include "product.h"
#include <vector>

class ProductList{
private:
    Product* product;
    Product *finded_product;
    vector<Product*> all_product_list;
public:
    ProductList();
    void addAllProduct(Product* prod);
    Product *findProduct(string pName);
    Product *purchaseProduct();
};