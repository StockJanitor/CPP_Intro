/*
LAB: Number pattern
Write a recursive function called PrintNumPattern() to output
the following number pattern.

Given a positive integer as input (Ex: 12), subtract another
positive integer (Ex: 3) continually until a negative value
is reached, and then continually add the second integer until
the first integer is again reached. For this lab, do not end
output with a newline.

*/

#include <iostream>

using namespace std;

// TODO: Write recursive PrintNumPattern() function
void PrintNumPattern(int a, int b)
{
    if (a < 0)
    {
        cout << a << " ";
        return;
    }
    cout << a << " ";
    PrintNumPattern(a - b, b);
    cout << a << " ";
}

int main()
{
    int num1;
    int num2;

    cin >> num1;
    cin >> num2;
    PrintNumPattern(num1, num2);

    return 0;
}