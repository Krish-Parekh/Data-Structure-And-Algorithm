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
    Time Complexity : O(N^2)
    Space Complexity : O(1)

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