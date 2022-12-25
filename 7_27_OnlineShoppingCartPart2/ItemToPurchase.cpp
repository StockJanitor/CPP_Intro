#include <iostream>
using namespace std;

#include "ItemToPurchase.h"

// default constructor
ItemToPurchase::ItemToPurchase()
{
    itemName = "none";
    itemPrice = 0;
    itemQuantity = 0;
    itemDescription = "none";
}
ItemToPurchase::ItemToPurchase(string name, string description, int price, int quantity)
{
    itemName = name;
    itemPrice = price;
    itemQuantity = quantity;
    itemDescription = description;
}
// mutators
void ItemToPurchase::SetName(string itemName)
{
    this->itemName = itemName;
}
void ItemToPurchase::SetPrice(int itemPrice)
{
    this->itemPrice = itemPrice;
}
void ItemToPurchase::SetQuantity(int itemQuantity)
{
    this->itemQuantity = itemQuantity;
}

void ItemToPurchase::SetDescription(string itemDescription)
{
    this->itemDescription = itemDescription;
}

// accessors
// get name
string ItemToPurchase::GetName() const
{
    return itemName;
}

// get price
int ItemToPurchase::GetPrice() const
{
    return itemPrice;
}

// get quantity
int ItemToPurchase::GetQuantity() const
{
    return itemQuantity;
}

// get description
string ItemToPurchase::GetDescription() const
{
    return itemDescription;
}

// print outs
void ItemToPurchase::PrintItemCost() const
{
    cout << GetName() << GetQuantity() << " @ $" << GetPrice() << " = $" << GetPrice() * GetQuantity() << endl;
}

void ItemToPurchase::PrintItemDescription() const
{
    cout << GetName() << GetDescription() << '.' << endl;
}