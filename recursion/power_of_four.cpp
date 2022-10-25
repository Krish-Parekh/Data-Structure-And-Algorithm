#include<iostream>

using namespace std;


bool isPowerOfFour(int num){
    if(num == 0){
        return false;
    }

    if(num % 4 != 0 and num != 1){
        return false;
    }

    if(num == 4 or num == 1){
        return true;
    }

    return isPowerOfFour(num / 4);
}

int main(){
    int ans = isPowerOfFour(5);
    cout << ans << endl;
}