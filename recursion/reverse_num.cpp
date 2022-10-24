#include <iostream>
#include <bits/stdc++.h>
using namespace std;

static int rev = 0;
void reverse_num(int num){
    if (num == 0){
        return;
    }
    int rem = num % 10;
    rev = rev * 10 + rem;
    return reverse_num(num / 10);
}

int main(){
    reverse_num(123);
    cout << "Reverse of 123 : " << rev;
    return 0;
}