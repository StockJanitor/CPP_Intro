
/*
LAB: Ticketing service (queue)
Given main(), complete the program to add people to a queue.
The program should read in a list of people's names including "You" (ending with -1),
adding each person to the peopleInQueue queue. Then, remove each person from the queue
until "You" is at the head of the queue. Include print statements as shown in the example below.

*/

#include <queue>
#include <iostream>

using namespace std;

int main()
{
    string personName = "";
    int counter = 0;
    int youPosition;

    queue<string> peopleInQueue;

    getline(cin, personName);
    while (personName != "-1")
    {
        // TODO: Add personName to peopleInQueue
        peopleInQueue.push(personName);
        counter++;
        if (personName == "You")
        {
            youPosition = counter;
        }

        //       determine position of "You" (youPosition)

        getline(cin, personName);
    }

    cout << "Welcome to the ticketing service... " << endl;
    cout << "You are number " << youPosition << " in the queue." << endl;

    // TODO: In a loop, remove head person from peopleInQueue,
    //       output their name and that they have purchased a ticket,
    //       then output your position in the queue. When you are at
    //       the head, output that you can purchase your ticket.
    for (int i = youPosition - 1; i > 0; i--)
    {
        // returns 1st element in the Queue
        cout << peopleInQueue.front() << " has purchased a ticket." << endl;

        // removes 1st element in the Queue
        peopleInQueue.pop();
        cout << "You are now number " << i << endl;
    }
    cout << "You can now purchase your ticket!" << endl;
    return 0;
}