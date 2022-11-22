#include <vector>
#include <string>
#include <iostream>

using namespace std;

// TODO: Write method to create and output all permutations of the list of names.
void PrintAllPermutations(vector<string> &permList, vector<string> &nameList)
{
    vector<string> tempVec;

    if (nameList.size() == 0)
    {
        for (int i = 0; i < permList.size(); i++)
        {
            cout << permList.at(i);
            if (i != permList.size() - 1)
            {
                cout << ", ";
            }
        }
        cout << endl;
    }
    else
    {
        for (int i = 0; i < nameList.size(); i++)
        {
            tempVec = nameList;
            permList.push_back(tempVec[i]);
            tempVec.erase(tempVec.begin() + i);
            PrintAllPermutations(permList, tempVec);
            permList.pop_back();
        }
    }
}

int main()
{
    vector<string> nameList;
    vector<string> permList;
    string name;
    cin >> name;
    while (name != "-1")
    {
        nameList.push_back(name);
        cin >> name;
    }
    PrintAllPermutations(permList, nameList);

    return 0;
}