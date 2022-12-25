/*
LAB: Mileage tracker for a runner
Given the MileageTrackerNode class, complete main() to insert nodes 
into a linked list (using the InsertAfter() function). 
The first user-input value is the number of nodes in the linked list. 
Use the PrintNodeData() function to print the entire linked list. DO NOT print the dummy head node.
*/
#include "MileageTrackerNode.h"
#include <string>
#include <iostream>
using namespace std;

int main () {
   // References for MileageTrackerNode objects
   MileageTrackerNode* headNode;
   MileageTrackerNode* currNode;
   MileageTrackerNode* lastNode;

   double miles;
   string date;
   int i;

   // Front of nodes list
   headNode = new MileageTrackerNode();
   lastNode = headNode;
   int num_nodes;
   cin >> num_nodes;
   // TODO: Read in the number of nodes
   for (i =0; i<num_nodes;i++)
   {
      cin >> miles;
      cin.ignore();
      getline(cin,date);
      currNode = new MileageTrackerNode(miles,date);
      lastNode->InsertAfter(currNode); // last node point to currNode, currNode = empty
      lastNode = currNode;
   }
   // TODO: Call the PrintNodeData() method
   //       to print the entire linked list
   currNode=headNode->GetNext();
   while (currNode != nullptr)
   {
      
      currNode->PrintNodeData();
      currNode = currNode->GetNext();
   }
   // TODO: For the read in number of nodes, read
   //       in data and insert into the linked list

   // TODO: Call the PrintNodeData() method
   //       to print the entire linked list

   // MileageTrackerNode Destructor deletes all
   //       following nodes
   delete headNode;
}