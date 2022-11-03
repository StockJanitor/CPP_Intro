/*
LAB: Insertion sort
The program has four steps:

Read the size of an integer array, followed by the elements of the array (no duplicates).
Output the array.
Perform an insertion sort on the array.
Output the number of comparisons and swaps performed.
main() performs steps 1 and 2.

Implement step 3 based on the insertion sort algorithm in the book. Modify InsertionSort() to:

Count the number of comparisons performed.
Count the number of swaps performed.
Output the array during each iteration of the outside loop.
Complete main() to perform step 4, according to the format shown in the example below.

Hints: In order to count comparisons and swaps, modify the while loop in InsertionSort(). Use global variables for comparisons and swaps.

The program provides three helper functions:
*/
#include <iostream>
using namespace std;

// Read size numbers from cin into a new array and return the array.
int *ReadNums(int size)
{
    int *nums = new int[size]; // Create array
    for (int i = 0; i < size; ++i)
    { // Read the numbers
        cin >> nums[i];
    }
    return nums;
}

// Print the numbers in the array, separated by spaces
// (No space or newline before the first number or after the last.)
void PrintNums(int nums[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << nums[i];
        if (i < size - 1)
        {
            cout << " ";
        }
    }
    cout << endl;
}

// Exchange nums[j] and nums[k].
void Swap(int nums[], int j, int k)
{
    int temp;
    temp = nums[j];
    nums[j] = nums[k];
    nums[k] = temp;
}

// Sort numbers
/* TODO: Count comparisons and swaps.
         Output the array at the end of each iteration. */
void InsertionSort(int numbers[], int size, int &swaps, int &compare)
{
    int i;
    int j;

    for (i = 1; i < size; ++i)
    {
        j = i;

        // if j smaller swap, swap j with j-1
        while (j > 0)
        {
            compare++;
            if (j > 0 && numbers[j] < numbers[j - 1])
            {
                Swap(numbers, j, j - 1);
                swaps += 1;

                --j;
            }
            else
            {
                break;
            }
        }
        for (int m = 0; m < size; ++m)
        {
            if (m != size - 1)
            {
                cout << numbers[m] << ' ';
            }
            else
            {
                cout << numbers[m];
            }
        }
        cout << endl;
    }
}

int main()
{
    int swaps = 0;
    int compare = 0;

    // Step 1: Read numbers into an array
    int size;
    cin >> size;                   // Read array size
    int *numbers = ReadNums(size); // Read numbers

    // Step 2: Output the numbers array
    PrintNums(numbers, size);
    cout << endl;

    // Step 3: Sort the numbers array
    InsertionSort(numbers, size, swaps, compare);
    cout << endl;

    // Step 4: Output the number of comparisons and swaps
    /* TODO: Output the number of comparisons and swaps performed */
    cout << "comparisons: " << compare << endl;
    cout << "swaps: " << swaps << endl;
    return 0;
}
