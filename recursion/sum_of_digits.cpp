#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int sumOfDigits(int num)
{
    if(num == 0){
        return num;
    }
    return (num % 10) + sumOfDigits(num / 10);
}
int main()
{
    cout << "Ans : " << sumOfDigits(123);
    return 0;
}