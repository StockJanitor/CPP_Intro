/*
LAB*: Program: Data visualization

Prompt the user for a title for data. Output the title.

Prompt the user for the headers of two columns of a table.
Output the column headers.

Prompt the user for data points. Data points must be in
this format: string, int. Store the information before
the comma into a string variable and the information after
the comma into an integer. The user will enter -1 when they
have finished entering data points. Output the data points.
Store the string components of the data points in a vector
of strings. Store the integer components of the data points
in a vector of integers.

Perform error checking for the data point entries.
If any of the following errors occurs, output
the appropriate error message and prompt again for a
valid data point.
If entry has no comma
Output: Error: No comma in string.
If entry has more than one comma
Output: Error: Too many commas in input.
If entry after the comma is not an integer
Output: Error: Comma not followed by an integer.

Output the information in a formatted table.
The title is right justified with a setw() value of 33.
Column 1 has a setw() value of 20. Column 2 has a setw()
value of 23.

Output the information as a formatted histogram.
Each name is right justified with a setw() value of 20.
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