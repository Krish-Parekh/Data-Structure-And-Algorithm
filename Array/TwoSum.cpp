/********************************************************************************** 
* 
* Given an array of integers, find two numbers such that they add up to a specific target number.
* 
* The function twoSum should return indices of the two numbers such that they add up to the target, 
* where index1 must be less than index2. Please note that your returned answers (both index1 and index2) 
* are not zero-based.
* 
* You may assume that each input would have exactly one solution.
* 
* Input: numbers={2, 7, 11, 15}, target=9
* Output: index1=1, index2=2
* 
*               
**********************************************************************************/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    /*
    Brute-Force-Approach 
    Time Complexity  : O(N^2)
    Space Complexity : O(1)

    Explanation:
    1. We will subtract ith element with target and store it in temp
    2. Then search temp in whole array from i+1 till n-1
    3. if we find that element we return i and j index

    Debug:
    value -> 2  7  11  15
    index -> 0  1  2   3
    
    When i = 0
        temp = 9 - 2 = 7
        search 7 in list
        if found return i and j index 
            
    */
    vector<int> twoSum(vector<int> &nums, int target)
    {

        vector<int> res;
        for (int i = 0; i < nums.size(); i++)
        {
            int cmp = target - nums[i];
            for (int j = i + 1; j < nums.size() - 1; j++)
            {
                if (nums[j] == cmp)
                {
                    res = {i, j};
                    return res;
                }
            }
        }
        return res;
    
        /*
        Optimized-Approach 
        Time Complexity  : O(N)
        Space Complexity : O(N)

        Explanation:
        1. We use to hashmap to optimize our time complexity
        2. In hashmap we are going to store element and its index {element,index}
        3. we subtract ith element from target and check
        4. if the given element is present in hashmap 
                -> if yes then from hashmap({element,index}) we return the index and ith index
                -> if no then we pair ith element present in array and its index



        Debug:
        value -> 2  7  11  15
        index -> 0  1  2   3
        
        When i = 0   
            temp = 9 - 2 = 7                    HASHMAP 
                search 7 in hashmap             {2 , 0}
            pair(nums[0]) = 0
        
        When i = 1 
            temp = 9 - 7 = 2
                search 2 in hashmap
                    return (value which is paired with 2 and i th index) 
                   
    */
        unordered_map<int, int> ans;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++)
        {
            int temp = target - nums[i];
            if (ans.find(temp) != ans.end())
            {
                res = {ans[temp], i};
                return res;
            }
            ans[nums[i]] = i;
        }
        return res;
    }
};