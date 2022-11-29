#ifndef MYNUM_H
#define MYNUM_H

#include <ostream>

using namespace std;

template <typename T>
class MyNum
{
public:
    // Default
    MyNum<T>(T v = T());

    // mutator
    void SetValue(T v);

    // accessor
    T GetValue() const;

    MyNum<T> operator+(const MyNum<T> &r) const;
    MyNum<T> operator-(const MyNum<T> &r) const;
    MyNum<T> operator*(const MyNum<T> &r) const;
    MyNum<T> operator/(const MyNum<T> &r) const;
    bool operator==(const MyNum<T> &r) const;
    bool operator!=(const MyNum<T> &r) const;

    template <typename A>
    friend ostream &operator<<(ostream &out, const MyNum<A> &r);
    template <typename A>
    friend istream &operator>>(istream &in, MyNum<A> &r);

private:
    T value;
};

template <typename T>
MyNum<T>::MyNum(T v)
{
    value = v;
}

template <typename T>
void MyNum<T>::SetValue(T v)
{
    value = v;
}

template <typename T>
T MyNum<T>::GetValue() const
{
    return value;
}

template <typename T>
MyNum<T> MyNum<T>::operator+(const MyNum<T> &r) const
{
    return MyNum<T>(value + r.GetValue());
}

template <typename T>
MyNum<T> MyNum<T>::operator-(const MyNum<T> &r) const
{
    return MyNum<T>(value - r.GetValue());
}

template <typename T>
MyNum<T> MyNum<T>::operator*(const MyNum<T> &r) const
{
    return MyNum<T>(value * r.GetValue());
}

template <typename T>
MyNum<T> MyNum<T>::operator/(const MyNum<T> &r) const
{
    return MyNum<T>(value / r.GetValue());
}

template <typename T>
bool MyNum<T>::operator==(const MyNum<T> &r) const
{
    return value == r.value;
}

template <typename T>
bool MyNum<T>::operator!=(const MyNum<T> &r) const
{
    return value != r.value;
}

template <typename T>
ostream &operator<<(ostream &out, const MyNum<T> &r)
{
    out << r.GetValue();
    return out;
}

template <typename T>
istream &operator>>(istream &in, MyNum<T> &r)
{
    in >> r.value;
    return in;
}

#endif
