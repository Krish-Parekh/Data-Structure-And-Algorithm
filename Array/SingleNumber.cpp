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
    Solution : 
    Time Complexity : O(N)
    Space Complexity : O(1)

    Explanation :
    1. We use logical operator to solve this question
    2. As we have to find one unique element between duplicate element
    3. When we xor number with itself it outputs zero
        -> 1^1 = 0 , 0^0 = 0
        -> 1^0 = 1 , 0^1 = 0
    
    Debug: 
    nums = [2,2,1]
    unique = 0
    when i = 0:
        unique = 0 ^ 2 // 2
    
    when i = 1:
        unique = 2 ^ 2 // 0

    when i = 2:
        unique = 0 ^ 1 // 1

    So our unique element is 1
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