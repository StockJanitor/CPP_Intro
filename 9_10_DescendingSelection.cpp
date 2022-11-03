/*
LAB: Descending selection sort with output during execution
Write a void function SelectionSortDescendTrace()
that takes an integer array and sorts the array into
descending order. The function should use nested loops
and output the array after each iteration of the outer loop,
thus outputting the array N-1 times (where N is the size).
Complete main() to read in a list of up to 10 positive integers
(ending in -1) and then call the SelectionSortDescendTrace()
function.

*/

#include <string>
#include <vector>
#include <iostream>

using namespace std;

// TODO: Write the partitioning algorithm - pick the middle element as the
//       pivot, compare the values using two index variables l and h (low and high),
//       initialized to the left and right sides of the current elements being sorted,
//       and determine if a swap is necessary
int Partition(vector<string> &userIDs, int i, int k)
{
    int l = i;
    int h = k;
    int midpoint = i + (k - i) / 2;
    string pivot = userIDs[midpoint];
    string temp;
    bool done = false;

    while (!done)
    {
        while (userIDs[l] < pivot)
        {
            l++;
        }
        while (userIDs[h] > pivot)
        {
            h--;
        }
        if (l >= h)
        {
            done = true;
        }
        else
        {
            temp = userIDs[l];
            userIDs[l] = userIDs[h];
            userIDs[h] = temp;
            l++;
            h--;
        }
    }
    return h;
}

// TODO: Write the quicksort algorithm that recursively sorts the low and
//       high partitions
void Quicksort(vector<string> &userIDs, int i, int k)
{
    if (i >= k)
    {
        return;
    }

    int j = Partition(userIDs, i, k);
    Quicksort(userIDs, i, j);
    Quicksort(userIDs, j + 1, k);
}

int main()
{
    vector<string> userIDList;
    string userID;

    cin >> userID;
    while (userID != "-1")
    {
        userIDList.push_back(userID);
        cin >> userID;
    }

    // Initial call to quicksort
    Quicksort(userIDList, 0, userIDList.size() - 1);

    for (size_t i = 0; i < userIDList.size(); ++i)
    {
        cout << userIDList.at(i) << endl;
        ;
    }

    return 0;
}