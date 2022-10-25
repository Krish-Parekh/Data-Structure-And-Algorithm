#include<iostream>

using namespace std;


bool isPowerOfThree(int num){
    if(num == 0){
        return false;
    }

    if(num % 3 != 0 and num != 1){
        return false;
    }

    if(num == 3 or num == 1){
        return true;
    }

    return isPowerOfThree(num / 4);
}

int main(){
    int ans = isPowerOfThree(5);
    cout << ans << endl;
}