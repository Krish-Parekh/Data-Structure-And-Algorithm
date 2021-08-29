/********************************************************************************** 
* Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The relative order of the elements may be changed.
*
* Since it is impossible to change the length of the array in some languages, you must instead have the result be placed in the first part of the array nums. More formally, if there are k elements after removing the * duplicates, then the first k elements of nums should hold the final result. It does not matter what you leave beyond the first k elements.
* 
* Return k after placing the final result in the first k slots of nums.
*
* Do not allocate extra space for another array. You must do this by modifying the input array in-place with O(1) extra memory.
* Input: nums = [3,2,2,3], val = 3
* Output: 2, nums = [2,2,_,_]
* Explanation: Your function should return k = 2, with the first two elements of nums being 2.
* It does not matter what you leave beyond the returned k (hence they are underscores).
**********************************************************************************/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    /*
        Solution (1):
        Time Complexity : O(N)
        Space Complexity : O(1)

        Explanation :
        1. We have to modify this array in-place
        2. So we can keep a count variable 
        3. Then we loop through array and in-place we replace it

        Debug :
        value -> 3  2  2  3
        index -> 0  1  2  3
        
        When i = 0
            count = 0
            if (3!=3) -> condition false
        
        When i = 1
            count = 0
            if (2!=3) -> condition true
                nums[count] = nums[1] // 2 2 2 3
                count++ // count = 1

        When i = 2
            count = 1
            if (2!=3) -> condition true
                nums[count] = nums[2] // 2 2 2 3
                count++ // count = 2

        When i = 3
            count = 2
            if(3!=3) -> condition false


        retrun count // 2

    */
    int removeElement(vector<int>& nums, int val) {
        int count = 0;
        for(int i =  0 ; i < nums.size() ; i++)
        {
            if(nums[i] != val)
            {
                nums[count] = nums[i];
                count++;
            }
        }
        return count;
    }
    
};