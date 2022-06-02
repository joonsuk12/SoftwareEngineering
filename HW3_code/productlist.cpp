#include "productlist.h"

ProductList::ProductList(){}

void ProductList::addAllProduct(Product* prod){
    product = prod;
    all_product_list.push_back(product);
}

Product* ProductList::findProduct(string pName){
    for (int i = 0; i < all_product_list.size(); i++)
    {
        if (all_product_list[i]->compareName(pName) == 1)
        {
            finded_product = all_product_list[i];
            return finded_product;
        }
    }
    return NULL;
}

Product* ProductList::purchaseProduct(){
    finded_product->purchaseProduct();
    return finded_product;
}