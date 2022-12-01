#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int NUM_VALUES = 5;

template <typename TheType>
void Read(vector<TheType> &list)
{
    for (int j = 0; j < NUM_VALUES; ++j)
    {
        cin >> list.at(j);
    }
}

template <typename TheType>
void Write(vector<TheType> &list)
{
    long unsigned int j;
    for (j = 0; j < list.size(); ++j)
    {
        cout << list.at(j) << " ";
    }
}

template <typename TheType>
vector<TheType> GetStatistics(vector<TheType> &list)
{
    vector<TheType> ans;
    ans.push_back(list.at(0));               // minimum element will be at 0th index(as the list is sorted)
    ans.push_back(list.at(list.size() / 2)); // list size is odd so median will be mid index element(as the list is sorted)
    ans.push_back(list.at(list.size() - 1)); // maximum element will be at last index(as the list is sorted)
    return ans;
}

template <typename TheType>
void Run(vector<TheType> &list)
{
    Read(list);
    sort(list.begin(), list.end());
    Write(list);
    cout << endl;
    vector<TheType> output = GetStatistics(list);
    Write(output);
    cout << endl;
}

int main()
{
    vector<int> integers(NUM_VALUES);
    Run(integers);
    cout << endl;

    vector<double> doubles(NUM_VALUES);
    Run(doubles);
    cout << endl;

    vector<string> strings(NUM_VALUES);
    Run(strings);

    return 0;
}