#include <iostream>
using namespace std;

#include "ShoppingCart.h"

// default constructor
ShoppingCart::ShoppingCart()
{
    this->customerName = "none";
    this->currentDate = "January 1, 2016";
}

ShoppingCart::ShoppingCart(string name, string date)
{
    this->customerName = name;
    this->currentDate = date;
}

// accessors
string ShoppingCart::GetCustomerName() const
{
    return customerName;
}
string ShoppingCart::GetDate() const
{
    return currentDate;
}

int ShoppingCart::GetNumItemsInCart() const
{
    return cartItems.size();
}

int ShoppingCart::GetCostOfCart()
{
    int cost_of_cart = 0;
    for (int i = 0; i < cartItems.size(); i++)
    {
        cost_of_cart += cartItems.at(i).GetPrice() * cartItems.at(i).GetQuantity();
    }
    return cost_of_cart;
}

// mutator
void ShoppingCart::AddItem(ItemToPurchase item)
{
    cartItems.push_back(item);
}

void ShoppingCart::RemoveItem(string item_name)
{
    bool in_cart = false;
    int cart_position = -1;
    for (int i = 0; i < cartItems.size(); i++)
    {
        if (cartItems.at(i).GetName() == item_name)
        {
            in_cart = true;
            cart_position = i;
        }
    }
    if (in_cart)
    {
        cartItems.erase(cartItems.begin() + cart_position);
    }
    else
    {
        cout << "Item not found in cart. Nothing removed." << endl;
    }
}

// Modifies an item's description, price, and/or quantity.
// Has a parameter of type ItemToPurchase. Does not return anything.

// If item can be found (by name) in cart,
// check if parameter has default values for description, price, and quantity.
// If not, modify item in cart.

// If item cannot be found (by name) in cart,
// output this message: Item not found in cart. Nothing modified.

void ShoppingCart::ModifyItem(ItemToPurchase item)
{
    bool in_cart = false;
    int cart_position = -1;
    for (int i = 0; i < cartItems.size(); i++)
    {
        if (cartItems.at(i).GetName() == item.GetName())
        {
            in_cart = true;
            cart_position = i;
        }
    }
    if (in_cart)
    {
        if (item.GetQuantity() != 0)
        {
            cartItems.at(cart_position).SetQuantity(item.GetQuantity());
        }
        if (item.GetPrice() != 0)
        {
            cartItems.at(cart_position).SetPrice(item.GetPrice());
        }
        if (item.GetDescription() != "none")
        {
            cartItems.at(cart_position).SetDescription(item.GetDescription());
        }
    }
    else
    {
        cout << "Item not found in cart. Nothing modified." << endl;
    }
}

// prints
void ShoppingCart::PrintTotal()
{
    cout << customerName << "\'s Shopping Cart - " << currentDate << endl;
    int items = 0;

    for (ItemToPurchase i : cartItems)
    {
        items += i.GetQuantity();
    }
    cout << "Number of Items: " << items << endl
         << endl;

    if (cartItems.size() == 0)
    {
        cout << "SHOPPING CART IS EMPTY" << endl;
    }

    for (int i = 0; i < cartItems.size(); i++)
    {
        cout << cartItems.at(i).GetName() << " " << cartItems.at(i).GetQuantity() << " @ $"
             << cartItems.at(i).GetPrice() << " = $"
             << cartItems.at(i).GetQuantity() * cartItems.at(i).GetPrice() << endl;
    }
    cout << endl;
    cout << "Total: $" << GetCostOfCart() << endl
         << endl;
}

void ShoppingCart::PrintDescriptions()
{
    cout << customerName << "\'s Shopping Cart - " << currentDate << endl
         << endl;
    cout << "Item Descriptions" << endl;
    for (int i = 0; i < cartItems.size(); i++)
    {
        cout << cartItems.at(i).GetName() << ": " << cartItems.at(i).GetDescription() << endl;
    }
}

// private:
// string customerName; //"none"
// string currentDate;  //"January 1, 2016"
// vector<ItemToPurchase> cartItems;