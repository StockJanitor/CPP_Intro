/*
LAB: Drawing an upside down triangle
Write a recursive function called DrawTriangle() that outputs lines of
'*' to form an upside down isosceles triangle. Function DrawTriangle()
has one parameter, an integer representing the base length of the triangle.
Assume the base length is always odd and less than 20. Output 9 spaces
before the first '*' on the last line for correct formatting.

Hint: The number of '*' decreases by 2 for every line drawn.

*/

#include <iostream>
using namespace std;

/* TODO: Write recursive DrawTriangle() function here. */
void DrawTriangle(int a)
{
    static int count = 9;

    // save initial count
    static int star = a;
    if (a <= 0)
    {
        return;
    }
    else
    { // deduct space for next call until 0
        count--;
        DrawTriangle(a - 2);

        // must include the 9
        for (int j = 0; j <= count; j++)
        {
            cout << " ";
        }

        // fron 0 add 1 space for previous call
        count++;

        // using initial count then reduce for previous calls.
        for (int i = 0; i < star; i++)
        {
            cout << "*";
        }
        cout << endl;

        star -= 2;
    }
}

int main()
{
    int baseLength;

    cin >> baseLength;
    DrawTriangle(baseLength);
    return 0;
}