/*************************************************************************************** 
* Given an integer array nums, return true if any value appears at least twice in the 
* array, and return false if every element is distinct.
***************************************************************************************/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {    
        /*
            Optimized Solution:
            Time Complexity  : O(N)
            Space Complexity : O(N)

            Explanation:
            1. We use unordered map to store key and value pair of <element,frequency>
            2. Then we traverse map and find if any element has frequency greater than 1
        */
        unordered_map<int,int>m;
        for(int i = 0 ; i < nums.size() ; i++)
        {
            m[nums[i]]++;
        }
        for(auto x : m)
        {
            if(x.second > 1)
            {
                return true;
            }
        }
        return false;
        
        
        /*
            Optimized Solution 2:
            Time Complexity  : O(N*LogN)
            Space Complexity : O(1)

            Explanation:
            1. We sort whole array 
            2. If duplicated exist then after sorting they will be beside eachother
            3. Loop and check nums[i+1] == nums[i] 
        */
        sort(nums.begin() , nums.end());
        for(int i = 0 ; i < nums.size()-1 ; i++)
        {
            if(nums[i+1] == nums[i])
            {
                return true;
            }
        }
        return false;
        
    }
};