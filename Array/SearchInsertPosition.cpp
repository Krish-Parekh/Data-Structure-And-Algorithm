/********************************************************************************** 
* Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were 
* inserted in order.
*
* You must write an algorithm with O(log n) runtime complexity.

* Input: nums = [1,3,5,6], target = 5
* Output: 2
*
* Input: nums = [1,3,5,6], target = 2
* Output: 1
*
* Input: nums = [1,3,5,6], target = 7
* Output: 4
**********************************************************************************/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:

    /*
        Solution :
        Time Complexity : O(log N)
        Space Complexity : O(1)

        1. We will use Binary Search Alogrithm to Search Insert Position
        2. As we need to find Insert Position for target 


        3. Lets Draw few Base cases
            a. If target is lesser than start element
               then index of target element is start
            b. If target is greater than end element
               then index of target element is end+1
        
        (BASE CASE) Debug :
        1st case : 
            value -> 1  3  5  6
            index -> 0  1  2  3
            target-> 0

            s = 0
            e = 3
            if(1 > 0) -> condition true
            return s // 0
        
        2nd case : 
            value -> 1  3  5  6
            index -> 0  1  2  3
            target-> 7

            s = 0
            e = 3
            if(6 < 7) -> condition true
            return e+1 // 4


        4. Now for the condition where target is between bounds
            -> Use binary search Algorithm
            -> at the end return s 
        Debug :
            value -> 1  3  5  6
            index -> 0  1  2  3
            target-> 2
            s = 0
            e = 3
        when 0<=3: 
            mid = (0+3)/2  // 1
            if(3 == 2) -> condition false
            else if(3<2) -> condition false
            else -> e = 1 - 1 // 0
        
        when 0<=0:
            mid = (0+0)/2  // 0
            if(1 == 2) -> condition false
            else if(1<2) -> condition true
            s = 0+1 // 1
        
        when 1<=0: -> condition false

        return s // 1
    */


    int searchInsert(vector<int> &nums, int target)
    {
        int s = 0;
        int e = nums.size() - 1;
        int ans;
        if (nums[s] > target)
        {
            return s;
        }
        if (nums[e] < target)
        {
            return e + 1;
        }
        while (s <= e)
        {
            int mid = (s + e) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] < target)
            {
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }
        return s;
    }
};