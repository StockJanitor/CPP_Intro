/*

Complete the recursive function isRecMember below.  The function returns true if the
key is found in the array or false if the value is not found.  Create a simple driver to test
your recursive function.  Hint:  n is the number of elements (not index) and you should
start your search with the last element of the array and go backward.  Here is the
function prototype
• bool isRecMember(const int a[], int n, int key);

Try the following test cases in your test driver:
• int values[5] = {5, 7, 3, 6, 2};
• try the following values for key: 2, 1, and 5

#include <iostream>

using namespace std;

// function prototype
// that takes a array size and key values
// return true if the element is found
// otherwise returns false
bool isRecMember(const int a[],int n,int key);

//
int main()
{
    // initialize the array
    int values[5] = {5,7,3,6,2};

    // take key value as 2
    int key = 2;

    // check for other values also
    // int key = 1;
    // int key = 5;

    // take the array size as 5
    int n = 5;

    // call the function isRecMember and store the result in result variable
    bool result = isRecMember(values,n,key);

    // check if the result it true then print the message
    if(result){

        // print element is found
        cout<<"Element "<<key<<" is found.";
    }

    // if the element is not found
    else{

        // print the element is not found
        cout<<"Element "<<key<<" is not found.";
    }

}

// function definition
// that takes a array size and key values
// return true if the element is found
// otherwise returns false
bool isRecMember(const int a[],int n,int key){

    // check if the n value is less than zero
    // this is base condition
    if(n<0){

        // return false
        return false;
    }

    // check if the element is found at position
    // then return true
    else if(a[n]==key){

        // return true
        return true;
    }

    // otherwise do the following
    else{

        // call the function isRecMember recursively
        return isRecMember(a,n-1,key);
    }
}



*/

#include <iostream>
using namespace std;

bool isRecMember(const int a[], int n, int key)
{

    if (n < 1)
    {
        return false;
    }
    else if (a[n - 1] == key)
    {
        return true;
    }
    else
    {
        return isRecMember(a, n - 1, key);
    }
};

int main()
{
    int key = 5;
    int values[5] = {5, 7, 3, 6, 2};
    bool include = isRecMember(values, 5, key);

    if (include)
    {
        cout << key << " is found" << endl;
    }
    else
    {
        cout << key << " is not found" << endl;
    }

    return 0;
}