/*
LAB*: Program: Income tax form - functions
Program Specifications Write a program to calculate U.S. income tax owed given wages,
taxable interest, unemployment compensation, status (dependent, single, or married),
and taxes withheld. Dollar amounts are displayed as integers without comma separators.
For example, cout << "Deduction: $" << deduction << endl;

Note: this program is designed for incremental development. Complete each step and
submit for grading before starting the next step. Only a portion of tests pass after each step but confirm progress.

Step 1. Within main() input wages, taxable interest, unemployment compensation, status
(0=dependent, 1=single, and 2=married), and taxes withheld as integers.

Step 2 (2 pts). Complete the CalcAGI() function. Calculate the adjusted gross income
(AGI) that is the sum of wages, interest, and unemployment. Convert any negative values
to positive before summing to correct potential input errors. Return the AGI. Note the
provided code in main() calls CalcAGI() and outputs the returned value. Submit for grading to confirm two tests pass.
Ex: If the input is:

*/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// Calculate AGI and repair any negative values
int CalcAGI(int wages, int interest, int unemployment)
{
    /* Complete the function and update the return statement */

    return (wages + interest + unemployment < 0) ? (wages + interest + unemployment) * -1 : wages + interest + unemployment;
}

// Calculate deduction depending on single, dependent or married
int GetDeduction(int status)
{
    /* Complete the function and update the return statement */
    switch (status)
    {
    case 2:
        return 24000;
        break;
    case 1:
        return 12000;
        break;
    default:
        return 6000;
        break;
    }
}

// Calculate taxable but not allow negative results
int CalcTaxable(int agi, int deduction)
{
    /* Complete the function and update the return statement */

    return (agi - deduction < 0) ? 0 : agi - deduction;
}

// Calculate tax for single or dependent
int CalcTax(int status, int taxable)
{
    if (status == 2)
    {
        if (taxable > 80000)
        {
            return 9200 + (taxable - 80000) * .22;
        }
        else if (taxable > 20000 && taxable <= 80000)
        {
            return 2000 + (taxable - 20000) * .12;
        }
        else
        {
            return taxable * .1;
        }
    }
    else
    {
        if (taxable >85000)
        {
            return 14500 + (taxable - 85000)*.24;
        }
        else if (taxable > 40000 && taxable <= 85000)
        {
            return 4600 + (taxable - 40000)*.22;
        }
        else if (taxable > 10000 && taxable <= 40000)
        {
            return 1000 + (taxable - 10000)*.12;
        }
        else
        {
            return taxable * .1;
        }
    }
}

// Calculate tax due and check for negative withheld
int CalcTaxDue(int tax, int withheld)
{
    /* Complete the function and update the return statement */

    return -1;
}

int main()
{
    int wages, interest, unemployment, status, withheld;
    int tax, agi, due, deduction, taxable;

    // Step #1: Input information
    cin >> wages >> interest >> unemployment >> status >> withheld;
    // Step #2: Calculate AGI
    agi = CalcAGI(wages, interest, unemployment);
    cout << "AGI: $" << agi << endl;
    deduction = GetDeduction(status);
    cout << "Deduction: $" << deduction << endl;
    taxable = CalcTaxable(agi, deduction);
    cout << "Taxable income: $" << taxable << endl;
    tax =  CalcTax(status,taxable);
    cout << "Federal tax: $" << tax<< endl;
    due = tax - withheld;
    cout << "Tax due: $" << due << endl;

    return 0;
}
