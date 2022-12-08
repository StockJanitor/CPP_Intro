#include <iostream>
#include "Calculator.h"
#include <cmath>
using namespace std;

// TODO: Define default constructor
Calculator::Calculator()
{
    a = 0.0;
}
// TODO: Define member functions - 
//       Add(), Subtract(), Multiply(), Divide(), Clear(), GetValue()

void Calculator::Add(double a)
{
    this->a += a;
}
void Calculator::Subtract(double a)
{
    this->a -=a;
}

void Calculator::Multiply(double a)
{
    this->a *= a;
}
void Calculator::Divide(double a)
{
    this->a /=a;
}

void Calculator::Clear()
{
    this->a=0;
}

double Calculator::GetValue()
{
    return this->a;
}

// final part
void Calculator::Power(double a)
{
    double multiply = this->a;

    // start from 1 because the 1st operation has 2 already.
    for (int i = 1; i<a;i++)
    {
        this->a *= multiply;
    }
}


void Calculator::SquareRoot()
{
    // estimate of squareroot
    double estimate_num = this->a/2;

    // precision of result
    double precision = 0.01;

    // iterate untill desired precision
    while (abs(estimate_num * estimate_num - this->a) > precision)
    {
        // using babylonian method proceed approximation.
        estimate_num = (estimate_num + this->a / estimate_num)/2;
    }

    this->a = estimate_num;

}

// void Calculator::SquareRoot()
// {

//     this->a = sqrt(this->a);

// }