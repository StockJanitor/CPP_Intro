/*
LAB: Grocery shopping list (list)
Given a ListItem class, complete main() using the built-in list type to create a linked list called shoppingList.
The program should read items from input (ending with -1), adding each item to shoppingList, and output each item
in shoppingList using the PrintNodeData() function.


*/

#include "ListItem.h"
#include <string>
#include <list>
#include <iostream>

using namespace std;

int main()
{
    // TODO: Declare a list called shoppingList of type ListItem
    list<ListItem> shoppingList;
    string item;

    // TODO: Read inputs (items) and add them to the shoppingList list
    //       Read inputs until a -1 is input
    getline(cin, item);
    while (item != "-1")
    {
        shoppingList.push_back(ListItem(item));
        cin.clear();
        getline(cin, item);
    }

    // TODO: Print the shoppingList list using the PrintNodeData() function

    // create iter pointer object
    list<ListItem>::iterator iter;

    // loop from beginning to end, and output it

    // for (iter = shoppingList.begin(); iter != shoppingList.end(); iter++)        // all works
    // for (ListItem thing : shoppingList)                                          // all works

    for (ListItem &thing : shoppingList)
    {
        thing.PrintNodeData();
    }
    return 0;
}