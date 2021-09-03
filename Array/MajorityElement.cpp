/*************************************************************************************** 
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.  

Example 1:

Input: nums = [3,2,3]
Output: 3
***************************************************************************************/




#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    /*
        Brute-force Solution : 
        Time Complexity : O(N^2)
        Space Complexity : O(1)

        Explanation :
        1. For every element we will count the number of occurence 
        2. we will use 2 for loop to keep count of each occurenece
        3. If count > n/2
            then we store that element in majorEle and break loop
    */
    int majortiyElement(vector<int> &nums)
    {
        int n = nums.size();
        int majorEle = 0;
        for (int i = 0; i < n; i++)
        {
            int count = 0;
            for (int j = 0; j < n; j++)
            {
                if (nums[i] == nums[j])
                {
                    count++;
                }
            }
            if (count > n / 2)
            {
                majorEle = nums[i];
                break;
            }
        }
        return majorEle;
    }
    /*
    
        Optimal-Solution:
        Time Complexity : O(N)
        Space Complexity : O(N)

        Explanation : 
        1. Create a hashmap which store < elements , frequency > 
        2. Now traverse the array and keep inserting inside our map
        3. Then traverse element in hashmap if frequency is greater then n/2 times
        4. Then store it inside variable majorEle and break from loop
        5. return that element
    */
    int majortiyElement(vector<int> &nums)
    {
        unordered_map<int, int> m;
        int n = nums.size();
        int majorEle = 0;
        for (int i = 0; i < n; i++)
        {
            m[nums[i]]++;
        }
        for (auto x : m)
        {
            if (x.second > n / 2)
            {
                majorEle = x.first;
                break;
            }
        }
        return majorEle;
    }


    /*
        Solution :
        Time complexity : O(N)
        Space complexity : O(1)

        Explanation :
        1. Use Boyer Moore Majority Vote Algorithm
        2. We use count variable to keep the 
            ->count to keep the count the number of occurence of element inside array 
            ->majorEle will hold the major element which is presenet inside the array
        3. We are taking an element and saying it as majorEle 
            -> if that element is encountered again then we increase the count
            -> else we decrease the count

        nums = [3,2,3]
        
        count = 0
        majorEle = 0
        
        Debug :
        when i = 0
            if(count == 0) -> true
                majorEle = 3
            if(3 == 3) -> true
                count++     // count = 1
        
        when i = 1
            if(count == 0) -> false
            if(2 == 3) -> false
                count-- // count = 0
                
        when i = 2
            if(count == 0) -> true
                majorEle = 1
    */

    int majorityElement(vector<int> &nums)
    {
        int count = 0;
        int majorEle = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if(count == 0)
            {
                majorEle = nums[i];
            }
            if(nums[i] == majorEle)
            {
                count++;
            }
            else
            {
                count--;
            }
        }
        return majorEle;
    }
};