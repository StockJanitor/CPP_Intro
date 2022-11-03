/*
Exercise 4 – Timing Sorting Algorithm Collect the run times for either selection sort or insertion sort
(use random values for an array and sorted values; sorted the list twice and collect run time each time)
for the following array sizes: 10000, 20000, and 50000. You should be able to confirm that the runtime
is n^2 for unsorted list (i.e., going from 10000 to 20000 should be about 4 times slower and going
from 10000 to 50000 should be about 25 times slower).

Extra Credit (2 points): Collect run times for {either selection sort or insertion sort from the book}
and {either quick sort or merge sort from the book}.
Input data from data file, large1k.txt, and output the first 5 values and last 5 values from the
sorted list to confirm that the sorting algorithm is working correctly. Make sure to sort original
data using one slower sorting algorithm and then sort original data again using one faster sorting algorithm.
You should confirm the collected run times are reasonable.
*/
#include <iostream>
#include <ctime>
#include <vector>
#include <fstream>

using namespace std;

// function declarations
int partition(int numbers[], int i, int k);
void quicksort(int numbers[], int i, int k);
void selection_sort(int a[], int size);

int main()
{
    // declare variables
    ifstream inFS;
    int fileNum;
    vector<int> vector_num;

    // open file
    inFS.open("large100k.txt");
    if (!inFS.is_open())
    {
        cout << "Could not open file myfile.txt." << endl;
        return 1;
    }

    // read number
    inFS >> fileNum;
    while (!inFS.fail())
    {
        // append to array
        vector_num.push_back(fileNum);
        // read next number
        inFS >> fileNum;
    }

    // close file
    inFS.close();
    int array_num[vector_num.size()];

    // append to array
    for (int i = 0; i < vector_num.size(); i++)
    {
        array_num[i] = vector_num[i];
    }
    // *********** ABOVE is read file, load into vector, and copy to array ***********

    // doesnt really work with the miliseconds.
    // time_t a,b;
    // cout << time(&a)<<endl;
    // cout << time(&b) << endl;
    // cout << difftime(a,b) << endl;

    // // i think this is the epoch of cpu
    clock_t startTime, endTime;
    // int size = 500000;
    // int arr[size];
    // for (int i = 0; i < size; i++)
    // {
    //     arr[i] = rand() % 100;
    // }

    startTime = clock();
    selection_sort(array_num, vector_num.size() - 1);
    // quicksort(array_num, 0, vector_num.size()-1);
    endTime = clock();

    cout << "This is " << vector_num.size() << ": ";
    cout << endTime - startTime << " clocks." << endl
         << endl;

    return 0;
}

// Algo definitions
void selection_sort(int a[], int size)
{
    int pos, i, swap;
    for (i = 0; i < size - 1; i++)
    {
        pos = i;
        for (int j = i + 1; j < size; j++)
        {
            if (a[pos] > a[j])
                pos = j;
        }
        if (pos != i)
        {
            swap = a[i];
            a[i] = a[pos];
            a[pos] = swap;
        }
    }
}

int partition(int numbers[], int i, int k)
{
    int l, h, midpoint, pivot, temp;
    bool done;

    // get midpoint
    midpoint = i + (k - i) / 2;
    pivot = numbers[midpoint];

    done = false;
    l = i;
    h = k;

    // swap nums < pivot to front, nums > pivot to back
    while (!done)
    {

        // finding the num thats larger than pivot
        while (numbers[l] < pivot)
        {
            l++;
        }

        // finding the num thats smaller than pivot
        while (pivot < numbers[h])
        {
            h--;
        }

        // if index larger or equal to h
        if (l >= h)
        {
            // sorting is done
            done = true;
        }
        else
        {
            // swap the numbers at l with h
            temp = numbers[l];
            numbers[l] = numbers[h];
            numbers[h] = temp;
            l++;
            h--;
        }
    }
    // return the last index, so we can specify partitions
    return h;
}

void quicksort(int numbers[], int i, int k)
{
    // i is start index, k is last index

    // if 1 element or less just return;
    if (i >= k)
    {
        return;
    }
    // get the middle index
    int j = partition(numbers, i, k);

    // partition front part
    quicksort(numbers, i, j);

    // partition backpart
    quicksort(numbers, j + 1, k);
}
