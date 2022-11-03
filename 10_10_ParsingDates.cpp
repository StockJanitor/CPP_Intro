/*
Parsing dates
Complete main() to read dates from input,
one date per line. Each date's format must be as follows:
March 1, 1990. Any date not following that format is incorrect
and should be ignored. Use the substr() function to parse the
string and extract the date. The input ends with -1 on a line
alone. Output each correct date as: 3/1/1990.
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int DateParser(string month)
{
    int monthInt = 0;

    if (month == "January")
        monthInt = 1;
    else if (month == "February")
        monthInt = 2;
    else if (month == "March")
        monthInt = 3;
    else if (month == "April")
        monthInt = 4;
    else if (month == "May")
        monthInt = 5;
    else if (month == "June")
        monthInt = 6;
    else if (month == "July")
        monthInt = 7;
    else if (month == "August")
        monthInt = 8;
    else if (month == "September")
        monthInt = 9;
    else if (month == "October")
        monthInt = 10;
    else if (month == "November")
        monthInt = 11;
    else if (month == "December")
        monthInt = 12;
    return monthInt;
}

int main()
{

    string date;
    getline(cin, date);

    while (date != "-1")
    {
        // should have 2 spaces and 1 comma
        if (count(date.begin(), date.end(), ' ') == 2 && count(date.begin(), date.end(), ',') == 1)
        {
            int month;
            int day;
            int year;
            int curr_index = date.find(' ');
            month = DateParser(date.substr(0, curr_index));

            day = stoi(date.substr(curr_index + 1, curr_index + 2));

            year = stoi(date.substr(date.find(',') + 2, date.length()));

            cout << month << '/' << day << '/' << year << endl;
        }

        getline(cin, date);
    }
    return 0;
}
