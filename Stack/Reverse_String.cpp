#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
    string str = "Hello World!";
    stack<char>st;
    for(int i = 0; i < str.length() ; i++)
    {
        st.push(str[i]);
    }
    for(int j = 0 ; j < str.length() ; j++)
    {
        str[j] = st.top();
        st.pop();
    }
    cout << str << endl;
    return 0;
}