#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/*
leetCode : https://leetcode.com/problems/find-the-highest-altitude/
*/

int largestAltitude(vector<int>& gain) {
    int prev = 0;
    int highestPeak = 0;
    for(int i = 0 ; i < gain.size() ; i++){
        highestPeak = max(prev, highestPeak);
        prev = prev + gain[i];
    }
    return highestPeak;
}
int main(){
    vector<int> gain = {44,32,-9,52,23,-50,50,33,-84,47,-14,84,36,-62,37,81,-36,-85,-39,67,-63,64,-47,95,91,-40,65,67,92,-28,97,100,81};
    int ans = largestAltitude(gain);
    cout << "Ans : " << ans << endl;
    return 0;
}