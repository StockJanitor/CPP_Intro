/*
LAB: Drawing a right side up triangle
Write a recursive function called DrawTriangle() that outputs
lines of '*' to form a right side up isosceles triangle.
Function DrawTriangle() has one parameter, an integer
representing the base length of the triangle. Assume the base
length is always odd and less than 20. Output 9 spaces before
the first '*' on the first line for correct formatting.

Hint: The number of '*' increases by 2 for every line drawn.

*/

#include <iostream>
using namespace std;

/* TODO: Write recursive DrawTriangle() function here. */
void DrawTriangle(int a)
{
    static int count = 9;

    if (a <= 0)
    {

        return;
    }
    else
    {

        DrawTriangle(a - 2);
        for (int j = 0; j < count; j++)
        {
            cout << " ";
        }

        for (int i = 0; i < a; i++)
        {
            cout << "*";
        }
        cout << endl;
        count--;
    }
}

int main()
{
    int baseLength;

    cin >> baseLength;
    DrawTriangle(baseLength);
    return 0;
}

// #include <iostream>

// using namespace std;

// void DrawTriangle(int n){
//     int count = 0 ;
//     while(n >= 1){

//         for(int i = 1; i <= count; i++)
//             cout << " " ;
//         for(int j = 1; j <= n; j++){
//             cout << "*" ;
//         }
//         cout << "" << endl ;
//         count += 1 ;
//         n = n - 2 ;
//     }
// }
// int main()
// {

//     int n ;
//     cout << "Enter a positive odd number less than 20: " ;
//     cin >> n ;
//     DrawTriangle(n);
//     return 0;
// }