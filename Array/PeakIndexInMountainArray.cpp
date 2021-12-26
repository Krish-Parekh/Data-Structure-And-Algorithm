/*************************************************************************************** 
* 
* 852. Peak Index in a Mountain Array
*
* Link: https://leetcode.com/problems/peak-index-in-a-mountain-array/
*
* Input: arr = [0,1,0]
* Output: 1
*
* Input: arr = [24,69,100,99,79,78,67,36,26,19]
* Output: 2
*          
***************************************************************************************/

#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;

/*
1.  Brute Force Approach:
    Time Complexity: O(N)
    Space Complexity: O(1)
*/

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int arrSize = arr.size();
        
        if(arrSize < 3){
            return 0;
        }
        int prevValue = arr[0], index = 0;
        
        for(int i=1; i<arrSize; i++){
            int currValue = arr[i];
            int nextValue = arr[i+1];
            
            if(prevValue < currValue && currValue > nextValue){
                index = i;
            }
            prevValue = currValue;          
        }
        return index;
    }
};

/*
2.  Optimized Approach:
    Time Complexity: O(LogN)
    Space Complexity: O(1)
*/

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int arrSize = arr.size();

        if(arrSize < 3){
            return 0;
        }
        int low = 0;
        int high = arrSize-1;

        while(low < high){
            if(arr[low] >= arr[high]){
                high--;
            }
            else if(arr[low] < arr[high]){
                low++;
            }
        }
        return low;
    }
};