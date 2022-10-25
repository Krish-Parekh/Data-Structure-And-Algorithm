#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void swap(vector<char> &s, int first, int second)
{

    int temp = s[first];
    s[first] = s[second];
    s[second] = temp;
}

void helper(vector<char> &s, int start, int end){
    if(start > end){
        return;
    }
    swap(s, start, end);
    helper(s, start + 1, end - 1);
}

int main()
{
    vector<char> s = {'h', 'e', 'l', 'l', 'o'};
    for(char c : s){
        cout << c << " ";   
    }

    cout<< endl;
    helper(s , 0, s.size() - 1);
    for(char c : s){
        cout << c << " ";   
    }

}