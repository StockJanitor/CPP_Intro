/*
LAB: Warm up: Parsing strings
(1) Prompt the user for a string that contains two strings separated by a comma. (1 pt)

Examples of strings that can be accepted:
Jill, Allen
Jill , Allen
Jill,Allen


*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{

    string firstName;
    string lastName;

    cout << "Enter input string:" << endl;
    string name;
    getline(cin, name);

    while (name != "q")
    {
        if (name.find(',') == string::npos)
        {
            cout << "Error: No comma in string." << endl
                 << endl;
        }
        else
        {
            int space;

            string::iterator end_pos = remove(name.begin(), name.end(), ' ');
            name.erase(end_pos, name.end());

            firstName = name.substr(0, name.find(','));
            lastName = name.substr(name.find(',') + 1, (name.size()));

            cout << "First word: " << firstName << endl;
            cout << "Second word: " << lastName << endl
                 << endl;
        }

        cout << "Enter input string:" << endl;
        getline(cin, name);
    }
    return 0;
}