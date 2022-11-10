#ifndef STR_INSTRUMENTH
#define STR_INSTRUMENTH

#include "Instrument.h"

class StringInstrument : public Instrument
{
    // TODO: Declare private data members: numStrings, numFrets
    private:
        string numStrings;
        string numFrets;

    // TODO: Declare mutator functions -
    //      SetNumOfStrings(), SetNumOfFrets()
    public:
        void SetNumOfStrings(string a);

        void SetNumOfFrets(string a);
    // TODO: Declare accessor functions -
    //      GetNumOfStrings(), GetNumOfFrets()
        string GetNumOfStrings();
        string GetNumOfFrets();

};

#endif
