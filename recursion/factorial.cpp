#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int fact(int n)
{
    if (n == 1)
    {
        return 1;
    }

    return n * fact(n - 1);
}

int main()
{
    cout << "Factorial of 5 : " << fact(5) << endl;
    return 0;
}