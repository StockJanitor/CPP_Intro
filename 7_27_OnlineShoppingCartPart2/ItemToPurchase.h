#ifndef ITEM_TO_PURCHASE_H
#define ITEM_TO_PURCHASE_H

#include <string>
using namespace std;

class ItemToPurchase
{
private:
    string itemName;
    int itemPrice;
    int itemQuantity;
    string itemDescription;

public:
    ItemToPurchase();
    ItemToPurchase(string name, string description, int price, int quantity);
    void SetName(string userName);
    void SetPrice(int userPrice);
    void SetQuantity(int userQuantity);
    void SetDescription(string userDescription);
    string GetName() const;
    int GetPrice() const;
    string GetDescription() const;
    int GetQuantity() const;
    void PrintItemCost() const;
    void PrintItemDescription() const;
};

#endif