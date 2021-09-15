/********************************************************************************** 
*  
* Search in 2D Matrix
*
* Write an efficient algorithm that searches for a value in an m x n matrix. 
* This matrix has the following properties:
*   i) Integers in each row are sorted from left to right.
*   ii) The first integer of each row is greater than the last integer of the previous row.
*
* Love Babber Sheet
* Link: https://leetcode.com/problems/search-a-2d-matrix/
*
* Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
* Output: true
*
**********************************************************************************/

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

/*
1   Brute Force Solution:
    Time Complexity: O(N^2)
    Space Complexity: O(1)

    Explanation: 
    1. We wil traverse using nested for loop.

    2. If we find target element at any point of time, then we will return true.

    3. Even after traversing matrix, if we dont find target element, then we will return false.

*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[i].size(); j++)
            {
                if(target == matrix[i][j])
                {
                    return true;
                }
            }
        }
        return false;
    }
};

/*
1   Optimized Solution:
    Time Complexity: O(LogN*LogM)
    Space Complexity: O(1)

    Explanation: 
    [same as binary search algorithm]

    1.  We will use binary search for searching an element.

    2.  First of all we need two pointers.
        Start = It will point at starting of matrix.
        End = It will point at ending of matrix.

    3.  Inside a while loop, we will store current element into ele variable and then compare to given target.
        otherwise we will adjust pointers.

    4.  If we dont find element and code comes out of loop without returning a true. Then outside of loop we will return true.

    Debug:
    arr[][] =   { {1,2}
                  {3,4} }
    Target = 3
    
    Inside a function:
    m = 2, n = 2
    start = 0, end = 3

        Inside a loop
        i)  while(0 <= 3){
                mid = 1
                ele = 2      ->arr[1/2][1%2] = arr[0][1]

                if(2 == 3)    ->False
                else if(2 < 3 )    ->true
                    start = 2
            }   
        
        ii) while(2 <= 3){
                mid = 2
                ele = 3      ->arr[2/2][2%2] = arr[1][0]

                if(3 == 3)     ->True
                    return true
            }

*/


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int m = matrix.size(), n = matrix[0].size();
        int start = 0, end = (m*n)-1;
        
        while(start <= end)
        {
            int mid = (start+end)/2;
            int ele = matrix[mid/n][mid%n];
            
            if(ele == target)
            {
                return true;
            }
            else if(ele < target)
            {
                start = mid+1;
            }
            else
            {
                end = mid-1;
            }
        }
        return false;
    }
};