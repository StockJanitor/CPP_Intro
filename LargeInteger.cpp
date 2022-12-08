#include <vector>
#include <iostream>
#include <string>
using namespace std;

/*
pesudo code
1. obtain the numbers and operation sign
2. convert to int array
3. add function and output
*/
void getItems(string item, string &first_num, string &second_num, char &sign);
void convertArray(string num, int array[], bool &invalid);
void calculateNum(int array1[], int array2[], int result[], char sign, int first_size, int second_size, bool &overflow, bool &invalid);
void printArray(int array[]);

int main()
{
    // initialize variables
    string item, first_num, second_num;
    char sign;
    int array_one[20] = {}, array_two[20] = {}, result[20] = {};
    bool one, two, invalid = false, overflow = false;

    // obtain input
    cout << "Enter a large integer up to 20 digits --> ";
    getline(cin, item);

    // obtain the variables
    getItems(item, first_num, second_num, sign);

    // check if we can proceed
    convertArray(first_num, array_one, invalid);
    convertArray(second_num, array_two, invalid);

    // if not invalid, proceed to calculate.
    if (!invalid)
    {
        calculateNum(array_one, array_two, result, sign, first_num.size(), second_num.size(), overflow, invalid);
    }

    // if not invalid/overflow, print array
    if (!invalid && !overflow)
    {
        cout << first_num << ' ' << sign << ' ' << second_num << " = ";
        printArray(result);
    }
    if (overflow)
    {
        cout << item << " = "
             << "overflow" << endl;
    }
    else if (invalid)
    {
        cout << "Invalid operand(s)" << endl;
    }
    return 0;
}

// save to variable
void getItems(string item, string &first_num, string &second_num, char &sign)
{
    bool first_int = true;

    for (int i = 0; i < item.size(); i++)
    {
        // obtain the sign
        if (item[i] == '+' || item[i] == '-')
        {
            first_int = false;
            sign = item[i];
        }

        // obtain the first number
        if (first_int)
        {
            if (item[i] != ' ')
            {
                first_num += item[i];
            }
        }
        // obtain the second number
        else
        {
            if (item[i] != ' ' && item[i] != '+' && item[i] != '-')
            {
                second_num += item[i];
            }
        }
    }
}

// saving to array
void convertArray(string num, int array[], bool &invalid)
{
    bool add = false;

    // increment for string-num
    int j = 0;

    // check not above 20 number
    if (num.size() > 20)
    {
        cout << "Invalid operand(s)" << endl;
        invalid = true;
    }
    else
    {
        // loop with 20 zeros
        for (int i = 0; i < 20; i++)
        {
            // if current i is same as num.size, we start adding to array
            if (i == 20 - num.size())
            {
                add = true;
            }

            if (add)
            {
                // start string num = 0, add to current array
                array[i] = static_cast<int>(num[j] - 48);
                j++;
            }
        }
    }
}

void calculateNum(int array1[], int array2[], int result[], char sign, int num1, int num2, bool &overflow, bool &invalid)
{
    // increment variable
    int j = 0;

    switch (sign)
    {
    case '+':
        // start from last variable
        for (int i = 19; i >= 0; i--)
        {
            // if over 10, current set to 0, increase j
            // if (array1[i] + array2[i] + j >= 10)
            // {
            //     result[i] = array1[i] + array2[i] - 10 + j;
            //     j = 1;
            // }
            // else
            // {
            //     result[i] = array1[i] + array2[i] + j;
            //     j = 0;
            // }
            result[i] = (array1[i] + array2[i] + j >= 10) ? (array1[i] + array2[i] + j - 10) : (array1[i] + array2[i] + j);
            j = (array1[i] + array2[i] + j >= 10) ? 1 : 0;
        }
        if (array1[0] + array2[0] + j >= 10)
        {
            // overflow!
            overflow = true;
        }
        break;

    case '-':
        // if num1 < num2, invalid
        if (num1 < num2)
        {
            invalid = true;
            break;
        }
        // if same size, check if larger from index 0
        else if (num1 == num2)
        {
            for (int i = 0; i < 20; i++)
            {
                // if larger, break right away, we know we can subtract
                if (array1[i] > array2[i])
                {
                    break;
                }
                // if not larger, invalid = true
                else if (array1[i] < array2[i])
                {
                    invalid = true;
                    break;
                }
            }
        }

        // if not invalid , we subtract.
        if (invalid == false)
        {

            for (int i = 19; i >= 0; i--)
            {
                result[i] = (array1[i] - array2[i] < 0) ? (array1[i] - array2[i] + 10 - j) : (array1[i] - array2[i] - j);
                j = (array1[i] - array2[i] < 0) ? -1 : 0;
            }
        }
        break;
    }
}

void printArray(int array[])
{
    bool all_zero = true;
    for (int i = 0; i < 20; i++)
    {
        if (array[i] != 0)
        {
            cout << array[i];
            all_zero = false;
        }
    }
    if (all_zero)
    {
        cout << 0;
    }
    cout << endl;
}