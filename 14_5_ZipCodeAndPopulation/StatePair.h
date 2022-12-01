#ifndef STATEPAIR_H
#define STATEPAIR_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <typename T1, typename T2>
class StatePair
{
public:
    // TODO: Define constructors
    StatePair(){};

    StatePair(T1 userKey, T2 userValue)
    {
        key = userKey;
        value = userValue;
    };

    // TODO: Define mutators, and accessors for StatePair
    void SetKey(T1 newKey)
    {
        key = newKey;
    };
    void SetValue(T2 newVal)
    {
        value = newVal;
    };

    T1 GetKey()
    {
        return key;
    };
    T2 GetValue()
    {
        return value;
    };

    // TODO: Define PrintInfo() method

    void PrintInfo()
    {
        cout << key << ": " << value << endl;
    };

private:
    T1 key;
    T2 value;
};

#endif /* STATEPAIR_H */