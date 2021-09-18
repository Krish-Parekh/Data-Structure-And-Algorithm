/**************************************************************************************** 
* 
* Max Consecutive Ones    
* Given a binary array nums, return the maximum number of consecutive 1's in the array.
*
* Link: https://leetcode.com/problems/max-consecutive-ones/
* 
* Input: nums = [1,1,0,1,1,1]
* Output: 3
* Explanation: The first two digits or the last three digits are consecutive 1s. 
*              The maximum number of consecutive 1s is 3.
*
*****************************************************************************************/

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

/*
    Solution :
    Time Complexity : O(N)
    Space Complexity : O(1)

    Explanation: 
    1.  We will traverse entire array.
    2.  If we find 1, then we will increase count by 1.
    3.  If we find 0, then check which is greater mx or count. and intilize it to mx.
    4.  After coming out of the loop we will again check above condition.
    4.  At the end, we will return mx.
    
*/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums)
    {
        int count=0, mx = INT_MIN;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]==1)
            {
                count++;
            }
            else
            {
                mx = max(mx, count);
                count = 0;
            }
        }
        mx = max(mx, count);
        return mx;
    }
};