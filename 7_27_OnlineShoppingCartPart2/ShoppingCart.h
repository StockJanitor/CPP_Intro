#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include <vector>
#include <string>
#include "ItemToPurchase.h"
using namespace std;

class ShoppingCart
{
private:
    string customerName;
    string currentDate;
    vector<ItemToPurchase> cartItems;

public:
    ShoppingCart();
    ShoppingCart(string userName, string userDate);

    // mutators
    void AddItem(ItemToPurchase item);
    void RemoveItem(string s);
    void ModifyItem(ItemToPurchase item);

    // accessors
    int GetCostOfCart();
    int GetNumItemsInCart() const;
    string GetCustomerName() const;
    string GetDate() const;

    // services
    void PrintTotal();
    void PrintDescriptions();
};

#endif