
/*
LAB*: Program: Online shopping cart (Part 1)
(1) Create three files to submit:

ItemToPurchase.h - Class declaration
ItemToPurchase.cpp - Class definition
main.cpp - main() function
Build the ItemToPurchase class with the following specifications:

Default constructor
Public class functions (mutators & accessors)
SetName() & GetName() (2 pts)
SetPrice() & GetPrice() (2 pts)
SetQuantity() & GetQuantity() (2 pts)
Private data members
string itemName - Initialized in default constructor to "none"
int itemPrice - Initialized in default constructor to 0
int itemQuantity - Initialized in default constructor to 0
(2) In main(), prompt the user for two items and create two objects of the ItemToPurchase class. Before prompting for the second item, call cin.ignore() to allow the user to input a new string. (2 pts)


*/
#include <iostream>
using namespace std;

#include "ItemToPurchase.h"

int main()
{
   string name;
   int price;
   int quantity;
   int totalCost = 0;
   ItemToPurchase item;
   cout << "Item 1" << endl
        << "Enter the item name:" << endl;
   getline(cin, name);
   cout << "Enter the item price:" << endl;
   cin >> price;
   cout << "Enter the item quantity:" << endl;
   cin >> quantity;

   item.SetName(name);
   item.SetPrice(price);
   item.SetQuantity(quantity);

   cout << endl;
   cin.ignore();

   ItemToPurchase item2;
   cout << "Item 2" << endl
        << "Enter the item name:" << endl;
   getline(cin, name);
   cout << "Enter the item price:" << endl;
   cin >> price;
   cout << "Enter the item quantity:" << endl;
   cin >> quantity;

   item2.SetName(name);
   item2.SetPrice(price);
   item2.SetQuantity(quantity);
   cout << endl;

   // cout << item.GetQuantity();


   cout << "TOTAL COST" << endl;
   cout << item.GetName() << " " << item.GetQuantity() << " @ $" << item.GetPrice() << " = $" << item.GetQuantity() * item.GetPrice() << endl;
   cout << item2.GetName() << " " << item2.GetQuantity() << " @ $" << item2.GetPrice() << " = $" << item2.GetQuantity() * item2.GetPrice() << endl;
   cout << endl;
   cout << "Total: $" << item2.GetQuantity() * item2.GetPrice() + item.GetQuantity() * item.GetPrice() << endl;
   return 0;
}