/**************************************************************************************** 
* 
* Subarray with 0 sum
* Given an array of positive and negative numbers. 
* Find if there is a subarray (of size at-least one) with 0 sum.
*
* Love Babber Sheet (Q-21):
* Link: https://practice.geeksforgeeks.org/problems/subarray-with-0-sum-1587115621/1
*
* Input:
* 5
* 4 2 -3 1 6
* 
* Output: 
* Yes
* 
* Explanation: 
* 2, -3, 1 is the subarray with sum 0.
*          
****************************************************************************************/

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

/*
1.  Brute Force Approch:
    Time Complexity : O(N^N)
    Space Complexity : O(1)

    Explanation: 
    1) We will use nested for loop to do sum of all possible sub array.

    2) If we find sum == 0 inside a loop, we will return true.

    3) If we dont find any sum == 0, even after coming out of the loop, then we will return false.

    Debug:
    arr[] = {4, 2, -3, 1, 6}

    1)  1st Iteration of outer loop

        i = 0, j = 0
        sum = 0 + 4 = 4
            sum == 0?   ->False

        i = 0, j = 1
        sum = 4 + 2 = 6
            sum == 0?   ->False

        i = 0, j = 2
        sum = 6 + (-3) = 3
            sum == 0?   ->False

        i = 0, j = 3
        sum = 3 + 1 = 4
            sum == 0?   ->False

        i = 0, j = 4
        sum = 4 + 6 = 10
            sum == 0?   ->False

    2)  2nd Iteration of outer loop
    
        i = 1, j = 1
        sum = 0 + 2 = 2
            sum == 0?   ->False

        i = 1, j = 2
        sum = 2 + (-3) = -1
            sum == 0?   ->False

        i = 1, j = 3
        sum = (-1) + 1 = 6
            sum == 0?   ->True
            return true;

*/

class Solution{
    public:
    bool subArrayExists(int arr[], int n)
    {
        for(int i=0; i<n; i++)
        {
            int sum = 0;
            for(int j=i; j<n; j++) 
            {
                sum = sum + arr[j];
                if(sum == 0)
                {
                    return true;
                }
            }
        }
        return false;
    }
};

/*
2.  Optimized Approch:
    Time Complexity : O(N)
    Space Complexity : O(N)

    Explanation: 
    1) We will be going to use unordered_map. We will traverse array using for loop.

    2) We will store sum of continuos all elements.

    3) Then we will check whether current sum is 0 or that sum is already stored in map?.
       If sum is already stored in map, that means once sum was same as current sum.
       That proves that, there is some subtraction happend. 
       That is the only reason sum is repeating.

    4) If above condition becomes false, then we will store sum into map.

    Debug:
    arr[] = {4, 2, -3, 1, 6}

    1)  1st Iteration
        sum = 0 + 4 = 4
        if(4 is already in map?)    ->False

        map:
        4->1

    2)  2st Iteration
        sum = 4 + 2 = 6
        if(6 is already in map?)    ->False

        map:
        4->1
        6->1

    3)  3st Iteration
        sum = 6 + -3 = 3
        if(3 is already in map?)    ->False

        map:
        4->1
        6->1
        3->1

    4)  4st Iteration
        sum = 3 + 1 = 4
        if(4 is already in map?)    ->True
            return true

        [Map will not get updated after returning of program, Writing down map just for understanding]
        map:  
        4->2
        6->1
        3->1
*/

class Solution{
    public:
    bool subArrayExists(int arr[], int n)
    {
        int sum = 0;
        unordered_map<int, int> mp;
        for(int i=0; i<n; i++)
        {
            sum = sum +arr[i];
            if(mp[sum] == 1 || sum == 0)
            {
                return true;
            }
            mp[sum]++;
        }
        return false;
    }
};