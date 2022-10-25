#include<iostream>

using namespace std;


bool isPowerOfTwo(int num){
    if(num == 0){
        return false;
    }

    if(num % 2 != 0 and num != 1){
        return false;
    }

    if(num == 2 or num == 1){
        return true;
    }

    return isPowerOfTwo(num / 2);
}

int main(){
    int ans = isPowerOfTwo(5);
    cout << ans << endl;
}