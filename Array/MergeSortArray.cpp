/********************************************************************************** 
* You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and 
* n, representing the number of elements in nums1 and nums2 respectively.
*
* Merge nums1 and nums2 into a single array sorted in non-decreasing order.
*
* The final sorted array should not be returned by the function, but instead be stored inside the array 
* nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements 
* that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.
*
* Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
* Output: [1,2,2,3,5,6]
* Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
* The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.

**********************************************************************************/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/*
    Solution :
    Time Complexity : O(N)
    Space Complexity : O(1)

    Explanation: 
    1. The logic for this question is to traverse from last index 
        as we have to return the array of size m+n

    2. You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and  n, representing the number of elements in nums1 and nums2 respectively.

    3. which means m is the number of sorted element in array nums1 and n in nums2

    4. So why we traverse from back ?
        1. Because we have to return array of size m+n "Sorted"
        2. And we dont know how many elements we will encouter within a array 

    5. So here we use Two pointer alogirthm to traverse both the array 

    6. And we insert all the small element in nums1

    7. last while loop is for if any element is left in nums2 then we push that too inside our nums array


    Debug :
    Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
    Output: [1,2,2,3,5,6]
    
    i = 2
    j = 2
    k = 5

    when 2>= 0 and 2>=0
        if(3 > 6) -> false
        else -> 
        nums1[5] = nums2[2]  // [1,2,3,0,0,6] and k = 4 , j =1 

    When 2>=0 and 1>=0
        if(3 > 5) -> false
        else ->
        nums1[4] = nums2[1] // [1,2,3,0,5,6] and k = 3 , j = 0

    when 2>=0 and 0>=0
        if(3 > 2) 
        nums1[3] = nums[3]  // [1,2,3,3,5,6] and k = 2 , i = 2
    
    when 1 >= 0 and 0>=0
        if(2 > 2) -> false
        else ->
        nums1[2] = nums2[0] // [1,2,2,3,5,6] and k = 1 , j = -1

*/


void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int i = m-1;
    int j = n-1;
    int k = m+n-1;
    while(i>=0 and j>=0)
    {
        if(nums1[i] > nums2[j])
        {
            nums1[k--] = nums1[i--];
        }
        else{
            nums1[k--] = nums2[j--];
        }
    }
    while(j >= 0)
    {
        nums1[k--] = nums2[j--];
    }
}
int main()
{
    vector<int>nums1 = {1,2,3};
    vector<int>nums2 = {2,5,6};
    merge(nums1, 3 , nums2 ,3);
    for(int i = 0 ; i < nums1.size() ; i++)
    {
        cout << nums1[i] << " ";
    }
    return 0;
}