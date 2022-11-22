/*

LAB: Output a linked list
Write a recursive function called PrintLinkedList()
that outputs the integer value of each node in a linked list.
Function PrintLinkedList() has one parameter, the head node
of a list. The main program reads the size of the linked list,
followed by the values in the list. Assume the linked list has
at least 1 node.

*/

#include <iostream>
#include "IntNode.h"
using namespace std;

/* TODO: Write recursive PrintLinkedList() function here. */
void PrintLinkedList(IntNode *a)
{
    if (a)
    {
        a->PrintData();
        PrintLinkedList(a->GetNext());
    }
    //  if (a.GetNext() == NULL)
    //  {
    //     return;
    //  }
    //  else
    //  {
    //     PrintLinkedList(IntNode.GetNext());
    //  }
}

int main()
{
    int size;
    int value;

    cin >> size;
    cin >> value;
    IntNode *headNode = new IntNode(value); // Make head node as the first node
    IntNode *lastNode = headNode;           // Node to add after
    IntNode *newNode = NULL;                // Node to create

    // Insert the second and the rest of the nodes
    for (int n = 0; n < size - 1; ++n)
    {
        cin >> value;
        newNode = new IntNode(value);
        lastNode->InsertAfter(newNode);
        lastNode = newNode;
    }

    // Call PrintLinkedList() with the head node
    PrintLinkedList(headNode);

    return 0;
}