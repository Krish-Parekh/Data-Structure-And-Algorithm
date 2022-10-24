#include<iostream>
using namespace std;

void print_n_1(int n){
    
    if(n == 1){
        cout << n << " ";
        return;
    }
    cout << n << " ";
    print_n_1(n - 1);
    
    
}

int main()
{
    print_n_1(5);
    return 0;
}