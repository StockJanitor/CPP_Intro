/*
LAB: Student info not found
Given a program that searches for a student’s ID or name in a text file, complete the FindID() and FindName() functions. Then, insert a try/catch statement in main() to catch any exceptions thrown by FindID() or FindName(), and output the exception message. Each line in the text file contains a name and ID separated by a space.

Function FindID() has two parameters: a student's name (string) and the text file's contents (ifstream). The function FindID() returns the ID associated with the student's name if the name is in the file, otherwise the function throws a runtime_error with the message "Student ID not found for studentName", where studentName is the name of the student.

Function FindName() has two parameters: a student's ID (string) and the text file's contents (ifstream). The function FindName() returns the name associated with the student's ID if the ID is in the file, otherwise the function throws a runtime_error with the message "Student name not found for studentID", where studentID is the ID of the student.

The main program takes three inputs from a user: the name of a text file (string), the search option for finding the ID or name of a student (int), and the ID or name of a student (string). If the search option is 0, FindID() is invoked with the student's name as an argument. If the search option is 1, FindName() is invoked with the student's ID as an argument. The main program outputs the search result or the caught exception message.


*/

#include <string>
#include <iostream>
#include <stdexcept>
#include <fstream>
using namespace std;

string FindID(string name, ifstream &infoFS)
{

    bool foundID = false;
    string input;

    // read text to input
    infoFS >> input;

    // if has input
    while (infoFS)
    {
        // if found, print next (id), else look for next
        if (input == name)
        {
            foundID = true;
            // read next input, ID
            infoFS >> input;
            return input;
            break;
        }
        else
        {
            // look for next
            infoFS >> input;
        }
    }
    // if not found
    if (foundID == false)
    {
        string notFoundMsg = "Student ID not found for " + name;
        throw runtime_error(notFoundMsg);
    }
    return "";
}

string FindName(string ID, ifstream &infoFS)
{

    bool foundName = false;
    // save previous input
    string previous;
    // current input
    string input;
    infoFS >> previous;
    infoFS >> input;

    while (infoFS)
    {
        if (input == ID)
        {
            foundName = true;
            // return the name
            return previous;
            break;
        }
        else
        {
            // current assign to previous
            previous = input;
            // read next
            infoFS >> input;
        }
    }
    if (foundName == false)
    {
        string noIDMsg = "Student name not found for " + ID;
        throw runtime_error(noIDMsg);
    }
    return "";
}

int main()
{
    int userChoice;
    string studentName;
    string studentID;

    string studentInfoFileName;
    ifstream studentInfoFS;

    // Read the text file name from user
    cin >> studentInfoFileName;

    // Open the text file
    studentInfoFS.open(studentInfoFileName);

    // Read search option from user. 0: FindID(), 1: FindName()
    cin >> userChoice;

    // FIXME: FindID() and FindName() may throw an Exception.
    //        Insert a try/catch statement to catch the exception and output the exception message.
    try
    {
        if (userChoice == 0)
        {
            cin >> studentName;
            studentID = FindID(studentName, studentInfoFS);
            cout << studentID << endl;
        }
        else
        {
            cin >> studentID;
            studentName = FindName(studentID, studentInfoFS);
            cout << studentName << endl;
        }
    }
    catch (runtime_error &e)
    {
        cout << e.what() << endl;
    }

    studentInfoFS.close();
    return 0;
}
