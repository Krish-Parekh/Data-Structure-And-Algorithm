/*************************************************************************************** 
* Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array 
* such that nums[i] == nums[j] and abs(i - j) <= k. 
* Input: nums = [1,2,3,1], k = 3
* Output: true
***************************************************************************************/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    /*
        Solution :
        Time Complexity : O(N)
        Space Complexity : O(1)

        Explanation : 
        1. We will use hashMap to solve this
        2. In hashmap we storing pair of <element,index> 
        3. So the logic is simple
            -> we check one condition
            -> m.find(nums[i]) != m.end() -> this is to check if element is present in map
            -> So as we are checking duplicates that element would encounter 
            second time inside array and after that we check
            -> i - m[nums[i]] <= k 
                -> current index - previously when element was encountered
            -> if true then return;
            -> else 
                -> push element inside map
        Debug :
        Input: nums = [1,2,3,1], k = 3
        when i = 0 
            if(m.find(1)!=m.end() and 0-m[1] <= k) -> return false
            m[1] = 0
            
            <--map--> 
            1,0
        
        when i = 1
           if(m.find(2)!=m.end() and 1-m[2] <= k) -> false
           m[2] = 1

           <--map--> 
            1,0
            2,1

        when i = 2
            if(m.find(3)!=m.end() and 2-m[3] <= k) -> false
            m[3] = 2

            <--map--> 
            1,0
            2,1
            3,2

        when i = 3
            if(m.find(1)!=m.end() and 3-m[1] <= k)
                ->  m.find(1)!=m.end() -> true 
                -> 3-0 <= 3 -> true
                -> return true

    */
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        int n = nums.size();
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++)
        {
            if (m.find(nums[i]) != m.end() and i - m[nums[i]] <= k)
            {
                return true;
            }
            m[nums[i]] = i;
        }
        return false;
    }
};
