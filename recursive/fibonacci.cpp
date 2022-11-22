#include <iostream>

using namespace std;

// loop method
int fib(int n)
{

    // first num, second num, s next num
    int t0 = 0, t1 = 1, s, i;
    if (n <= 1)
        return n;
    for (i = 2; i <= n; i++)
    {
        s = t0 + t1;
        t0 = t1;
        t1 = s;
    }
    return s;
}
// amore function call
int rfib(int n)
{
    if (n <= 1)
        return n;
    return rfib(n - 2) + rfib(n - 1);
}

// less function call
int F[10];

int mfib(int n)
{
    if (n <= 1)
        F[n] = n;
    else
    {
        if (F[n - 2] == -1)
        {
            F[n - 2] = mfib(n - 2);
        }
        if (F[n - 1] == -1)
        {
            F[n - 1] = mfib(n - 1);
        }

        return F[n - 2] + F[n - 1];
    }
}

int main()
{

    for (int i = 0; i < 10; i++)
    {
        F[i] = -1;
    }
    cout << mfib(6);
    return 0;
}