/******************************************************************************************** 
* 
* Find the median
* Given an array arr[] of N integers, calculate the median
*
* Love Babber Sheet (Q-35):
* Link: https://practice.geeksforgeeks.org/problems/find-the-median0527/1#
*
* Example:
* 1. Input: N = 5
*    arr[] = 90 100 78 89 67
*    Output: 89
*    Explanation: After sorting the array middle element is the median 
* 
* 2. Input: N = 4
*    arr[] = 56 67 30 79
*    Output: 61
*    Explanation: In case of even number of elemebts average of two middle elements is the median
*          
********************************************************************************************/

#include <bits/stdc++.h>
#include <iostream>
using namespace std;


/*
    Solution :
    Time Complexity : O(n)
    Space Complexity : O(1)

    Explanation: 
    1.  We will sort the array.

    2.  If size of array is even, then
        We will get median element and its next element.
        We will do addition of both the element and then divide by 2. 
        That is the answer.

    3.  If size of array is odd, then
        We will find middle element and return it.

    Debug:
    1.  v[] = {5, 3, 2, 4 ,1}
        int n = 5
        v[] = {1, 2, 3, 4, 5}     -> After Sorting
        if(5/2 == 0)        -> False
        else                -> Automatically true
            x = 3               -> (x = 5/2 + 5%2)
            return v[2]         -> Since index starts from 0, we have to subtract one from x.

    2.  v[] = {19, 11}
        int n = 2
        v[] = {11, 19}   -> After Sorting
        if(2/2 == 0)     -> True
            min = 1
            max = 2
            return 15    -> ((11 + 19)/2 = 15)    
*/

class Solution
{
public:
    int find_median(vector<int> v)
    {
        int n = v.size();
        int x;
        sort(v.begin(), v.end());
        if(n%2 == 0)
        {
            int min = n/2;
            int max = min+1;
            return (v[min-1] + v[max-1])/2;
        }
        else
        {
            x = n/2 + n%2;
        }
        
        return v[x-1];
    }
};
