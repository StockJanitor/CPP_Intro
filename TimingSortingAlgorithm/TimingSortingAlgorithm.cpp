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

    // doesnt really work with the miliseconds.
    // time_t a,b;
    // cout << time(&a)<<endl;
    // cout << time(&b) << endl;
    // cout << difftime(a,b) << endl;

    // // i think this is the epoch of cpu
    // clock_t startTime, endTime;
    // int size = 500000;
    // int arr[size];
    // for (int i = 0; i < size; i++)
    // {
    //     arr[i] = rand() % 100;
    // }

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
