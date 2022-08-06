#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/*
leetCode : https://leetcode.com/problems/count-items-matching-a-rule/
*/

int ruleKeyMap(string ruleKey)
{
    if (ruleKey == "type")
    {
        return 0;
    }
    else if (ruleKey == "color")
    {
        return 1;
    }
    else
    {
        return 2;
    }
}
// Solution 1
int countMatches(vector<vector<string>> &items, string ruleKey, string ruleValue)
{
    int idx = ruleKeyMap(ruleKey);
    int count = 0;
    for (int i = 0; i < items.size(); i++)
    {
        for(int j = 0 ; j < items[i].size() ; j++){
            if(items[i][j] == ruleValue and j == idx){
                count++;
            }
        }
    }
    return count;
}

// Solution 2
int countMatches2(vector<vector<string>> &items, string ruleKey, string ruleValue)
{
    int count = 0;
    for(int i = 0 ; i < items.size() ; i++){
        if(ruleKey == "type" and items[i][0] == ruleValue){
            count++;
        }
        else if(ruleKey == "color" and items[i][1] == ruleValue){
            count++;
        }
        else if(ruleKey == "size" and items[i][2] == ruleValue){
            count++;
        }
    }
    return count;
}