#include <iostream>
#include "Calculator.h"
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