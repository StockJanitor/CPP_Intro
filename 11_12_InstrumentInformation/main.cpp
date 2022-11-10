#include "StringInstrument.h"

int main()
{
    Instrument myInstrument;
    StringInstrument myStringInstrument;

    string instrumentName, manufacturerName, stringInstrumentName, stringManufacturer, yearBuilt,
        cost, stringYearBuilt, stringCost, numStrings, numFrets;

    getline(cin, instrumentName);
    getline(cin, manufacturerName);
    getline(cin, yearBuilt);
    getline(cin, cost);

    getline(cin, stringInstrumentName);
    getline(cin, stringManufacturer);
    getline(cin, stringYearBuilt);
    getline(cin, stringCost);
    getline(cin, numStrings);
    getline(cin, numFrets);

    myInstrument.SetName(instrumentName);
    myInstrument.SetManufacturer(manufacturerName);
    myInstrument.SetYearBuilt(yearBuilt);
    myInstrument.SetCost(cost);
    myInstrument.PrintInfo();

    myStringInstrument.SetName(stringInstrumentName);
    myStringInstrument.SetManufacturer(stringManufacturer);
    myStringInstrument.SetYearBuilt(stringYearBuilt);
    myStringInstrument.SetCost(stringCost);
    myStringInstrument.SetNumOfStrings(numStrings);
    myStringInstrument.SetNumOfFrets(numFrets);
    myStringInstrument.PrintInfo();

    cout << "   Number of strings: " << myStringInstrument.GetNumOfStrings() << endl;
    cout << "   Number of frets: " << myStringInstrument.GetNumOfFrets() << endl;
}