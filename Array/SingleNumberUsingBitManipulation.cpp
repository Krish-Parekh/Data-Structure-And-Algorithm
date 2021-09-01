/******************************************************************************************** 
* 
* Single Number
* Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
*
* Link: https://leetcode.com/problems/single-number/
*
* Input:  nums = [2,2,1]
* Output: 1
*          
********************************************************************************************/


#include <bits/stdc++.h>
#include <iostream>
using namespace std;

/*

Debug:





*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int unique = 0;
        for(int i = 0 ; i < nums.size() ; i++)
        {
            unique^=nums[i];
        }
        return unique;
    }
};