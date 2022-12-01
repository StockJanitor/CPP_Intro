/*

Array Reverser
Write a recursive function that accepts an int array and reverse it.  You can test it with the
array from Exercise 3; print the reverse array after the function call in main to confirm it
is working correctly.  Hint: you might want to set up two more parameters in addition to
the array for the recursive function.

*/

#include <iostream>
using namespace std;

void reverseArray(int arr[], int c, int b)
{
    if (c >= b)
        return;

    int temp = arr[c];
    arr[c] = arr[b];
    arr[b] = temp;

    // Recursive Function calling
    reverseArray(arr, c + 1, b - 1);
}




void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";

    cout << endl;
}

int main()
{

    int values[5] = {5, 7, 3, 6, 2};
    reverseArray(values, 0, 4);
    printArray(values, 5);
    return 0;
}