#include "StringInstrument.h"

// TODO: Define mutator functions -
//      SetNumOfStrings(), SetNumOfFrets()
void StringInstrument::SetNumOfStrings(string a)
{
    numStrings = a;
}

void StringInstrument::SetNumOfFrets(string a)
{
    numFrets = a;
}
// TODO: Define accessor functions -
//      GetNumOfStrings(), GetNumOfFrets()
string StringInstrument::GetNumOfStrings()
{
    return numStrings;
}

string StringInstrument::GetNumOfFrets()
{
    return numFrets;
}
