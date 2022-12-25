/*

LAB: Playlist (output linked list)
Given main(), complete the SongNode class to include the function PrintSongInfo().
Then write the PrintPlaylist() function in main.cpp to print all songs in the playlist.
DO NOT print the dummy head node.

*/

#include <iostream>
#include "SongNode.h"

// TODO: Write PrintPlaylist() function
void PrintPlaylist(SongNode *item)
{
    //  item = item->GetNext();
    while (item->GetNext() != nullptr)
    {

        item = item->GetNext();
        item->PrintSongInfo();
        //  item = item->GetNext();
        if (item->GetNext() != nullptr)
        {
            cout << endl;
        }
    }
}

int main()
{
    SongNode *headNode;
    SongNode *currNode;
    SongNode *lastNode;

    string songTitle;
    string songLength;
    string songArtist;

    // Front of nodes list
    headNode = new SongNode();
    lastNode = headNode;

    // Read user input until -1  entered
    getline(cin, songTitle);
    while (songTitle != "-1")
    {
        getline(cin, songLength);
        getline(cin, songArtist);

        currNode = new SongNode(songTitle, songLength, songArtist);
        lastNode->InsertAfter(currNode);
        lastNode = currNode;

        getline(cin, songTitle);
    }

    // Print linked list
    cout << "LIST OF SONGS" << endl;
    cout << "-------------" << endl;
    PrintPlaylist(headNode);

    return 0;
}