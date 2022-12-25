/*
LAB: Vending machine
Given two integers as user inputs that represent the number of drinks to buy and the number of bottles to restock, create a VendingMachine object that performs the following operations:

Purchases input number of drinks
Restocks input number of bottles
Reports inventory
Review the definition of "VendingMachine.cpp" by clicking on the orange arrow. A VendingMachine's initial inventory is 20 drinks.

Ex: If the input is:


*/

#include <iostream>

#include "VendingMachine.h"
using namespace std;

int main()
{
	int purchase_count;
	int restock_count;
	VendingMachine item;
	cin >> purchase_count >> restock_count;
	item.Purchase(purchase_count);
	item.Restock(restock_count);
	item.Report();
}