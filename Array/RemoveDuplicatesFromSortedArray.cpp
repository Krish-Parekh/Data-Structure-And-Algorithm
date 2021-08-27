/********************************************************************************** 
* 
* Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the    * elements should be kept the same.
* 
* Since it is impossible to change the length of the array in some languages, you must instead have the result be placed in the first part of the array nums. More 
* formally,  if there are k elements after removing the duplicates, then the first k elements of nums should hold the final result. It does not matter what you leave  
* beyond the first  k elements.
* 
* Return k after placing the final result in the first k slots of nums.
* 
* Do not allocate extra space for another array. You must do this by modifying the input array in-place with O(1) extra memory.
* Input: nums = [1,1,2]
* Output: 2, nums = [1,2,_]
* Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
* It does not matter what you leave beyond the returned k (hence they are underscores).
*               
**********************************************************************************/


#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        /*
            Solution:
            Time complexity  : O(N)
            Space complexity : O(1)
            
            Explanation :
            
            (BASE CASE)
            1. First we keep base case if size < 2 -> which means there is only 1 or 0 element present in array so no need to remove anything
            
            (Solution)
            
            (usage of temp variable)
            1. We keep a temp variable which is used to maintain the size of the array after removing duplicates and we use shifting method 
               to remove duplicates from array 
            
            2. We check if both the element are different in sorted array 
                -> if yes : then we shift the element and increment the temp pointer 
                -> if no  : then continue in loop 
            
        */

        if (nums.size() < 2)
        {
            return nums.size();
        }
        int temp = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] != nums[i - 1])
            {
                nums[temp] = nums[i];
                temp++;
            }
        }
        return temp;
    }
};