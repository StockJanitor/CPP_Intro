#ifndef INSTRUMENTH
#define INSTRUMENTH

#include <iostream>
#include <string>

using namespace std;

class Instrument
{
protected:
    string instrumentName;
    string instrumentManufacturer;
    string yearBuilt;
    string cost;

public:
    void SetName(string userName);

    string GetName();

    void SetManufacturer(string userManufacturer);

    string GetManufacturer();

    void SetYearBuilt(string userYearBuilt);

    string GetYearBuilt();

    void SetCost(string userCost);

    string GetCost();

    void PrintInfo();
};

#endif