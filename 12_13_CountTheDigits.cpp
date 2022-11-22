/*
LAB: Count the digits
Write a recursive function called DigitCount() that takes
a positive integer as a parameter and returns the number
of digits in the integer. Hint: The digit count increases
by 1 whenever the input number is divided by 10.
*/

#include <iostream>
using namespace std;

/* TODO: Write recursive DigitCount() function here. */
int DigitCount(int a)
{
    return (a / 10 == 0) ? 1 : 1 + DigitCount(a / 10);
}

int main()
{
    int num;
    int digits;

    cin >> num;
    digits = DigitCount(num);
    cout << digits << endl;

    return 0;
}
