#include<iostream>
using namespace std;

void print_1_n(int n){
    
    if(n == 1){
        cout << n << " ";
        return;
    }
    print_1_n(n - 1);
    cout << n << " ";
    
    
}

int main()
{
    print_1_n(5);
    return 0;
}