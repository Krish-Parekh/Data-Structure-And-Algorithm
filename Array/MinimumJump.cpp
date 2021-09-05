/******************************************************************************************** 
* 
* Minimum number of jumps
* Given an array of N integers arr[] where each element represents the max number of steps that can be made forward from that element. 
* Find the minimum number of jumps to reach the end of the array (starting from the first element). 
* If an element is 0, then you cannot move through that element.
* Note: Return -1 if you can't reach the end of the array.
*
* Love Babber Sheet (Q-10):
* Link: https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1#
*
* Input:
* N = 11 
* arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9} 
* Output: 3 
*          
********************************************************************************************/

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

/*
    Solution :
    Time Complexity : O(N)
    Space Complexity : O(1)

    Explanation: 
    1.  We need three pointers to track, jump and store maximum value.
        i) jumps-> It will count total number of jumps.
        ii) maxValue-> It will store max "value" within a range for the purpose of jump.
        iii) nextStop-> It will store a range, which will indicates till where we have to check.
                       After reaching at nextStop, we have to jump by maxValue.

    2.  If first element is 0, We will return -1. Because 0 will never lead to end of an array.

    3.  We will use for loop to traverse entire array.
            in maxValue, We will store maximum value between previous max value and i+arr[i].

            Why i + arr[i]?
            Because, we have to count from 0th index + total steps from current elements(value).
            i shows previos steps + arr[i] is next steps.

            Suppose, arr[] = {1,2,3}
            i = 0, arr[i] = 1, 
                maxValue = max(0, 0+1) = 1
                maximum possible next stop can be 1(index) from 0(index)..

            i = 1, arr[i] = 2
                maxValue = max(1, 1+2) = 3
                maximum possible next stop can be 3(index) from 0(index).
            
        We will find max value till nextStop becomes equal to i.
        When nextStop and i becomes equal, 
            That means we are suppose to jump from that index with maximum possible value (Which was stored in maxValue).
            After that, we will store maxValue into nextStop and increase jumps by one (Because one jump made at this point).
            if nextStop becomes equal or more than size of array, then we will return jumps(which was counting jums)
        
    4. Return -1, if jumps never reach end of an array.
    
    Debug:
    Input: arr[] = {2,3,4,5}
    Output: 2

    i)  i = 0
        jumps = 0
        maxValue = 0
        nextStop = 0

        maxValue = max(0, 0 + 2) = 2
        if(nextStop == 0)   -> True
            nextStop = 2    -> Because maxValue will be initialized to nextStop.
            jumps = 1       -> jumps += 1

            if(nextStop >= n-1)    -> False

    ii) i = 1
        jumps = 1
        maxValue = 2
        nextStop = 2

        maxValue = max(2, 1+3) = 4
        if(nextStop == 1)   -> False

    iii)i = 2
        jumps = 1
        maxValue = 4
        nextStop = 2

        maxValue = max(4, 2+4) = 6
        if(nextStop == 2)   -> True
            nextStop = 6    -> Because maxValue will be initialized to nextStop.
            jumps = 2       -> jumps += 1

            if(nextStop >= n-1)    -> True
                return 2    -> return jumps

*/

class Solution{
  public:
    int minJumps(int arr[], int n){
        // Your code here
        int jumps = 0, maxValue = 0, nextStop = 0;
        
        if(arr[0] == 0){
            return -1;
        }
        
        for(int i=0; i<n; i++){
            maxValue = max(maxValue, i + arr[i]);

            if(nextStop == i){
                nextStop = maxValue;
                jumps++;

                if(nextStop >= n-1){
                    return jumps;
                }
            }
        }
        return -1;
    }
};