/*

Class Templates
Make a copy of MyInteger class from PA 8 and rename it to MyNum class.
If you do not have a working version of MyInteger class,
you can ask a classmate for a copy of it and give credit to that person.
Modify it to make it a class template so you can use it for different
numeric data types such as int and double (easier with the version without
pointer and make sure to put both the class and function definitions in
MyNum.h file so no MyNum.cpp file). You should be able to create objects
with different numeric types below and perform some operations in your driver
like the one with MyInteger class. Use the provided driver, testMyNum.cpp,
on Canvas to test your class template. MyNum<int> iValue; MyNum<double> dValue(5.5);

*/
#include <iostream>
#include "MyNum.h"

using namespace std;

int main()
{
    MyNum<int> i1;
    MyNum<int> i2(5);
    MyNum<int> i3 = i2;
    MyNum<int> *pMyInt;
    cout << "i1: " << i1 << endl;
    cout << "i2: " << i2.GetValue() << endl;
    cout << "i3: " << i3 << endl;
    i1.SetValue(-4);
    i3 = i1 + i2;
    cout << "i3: " << i3 << endl;
    cout << "(i2 - i1) / 2: " << (i2 - i1) / 2 << endl;
    cout << "i2 * i1: " << i2 * i1 << endl;
    cout << "Enter an integer: ";
    cin >> i1;
    cout << i1 << " == " << i2 << ": ";
    if (i1 == i2)
        cout << "true" << endl;
    else
        cout << "false" << endl;
    i2 = i1;
    cout << i1 << " != " << i2 << ": ";
    if (i1 != i2)
        cout << "true" << endl;
    else
        cout << "false" << endl;
    i2.SetValue(25);
    cout << "i1: " << i1 << endl;
    cout << "i2: " << i2 << endl;
    pMyInt = new MyNum<int>(i2);
    cout << "*pMyInt: " << *pMyInt << endl;
    *pMyInt = i1;
    cout << "pMyInt->GetValue(): " << pMyInt->GetValue() << endl;
    delete pMyInt;

    
    MyNum<double> dValue(5.5);
    cout << "Double value: " << dValue << endl;
    cout << "End of test cases." << endl;
    return 0;
}
