/*************************************************************************************** 
* 
* Merge Intervals (Leetcode Medium)
*
* Link: https://leetcode.com/problems/merge-intervals/
*
* Input: 
* intervals = [[1,3],[2,6],[8,10],[15,18]]
*
* Output: 
* [[1,6],[8,10],[15,18]]
*          
***************************************************************************************/

#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> v;
        v.push_back(intervals[0]);

        int j = 0;
        
        for(int i=1; i<intervals.size(); i++){
            if(v[j][1] >= intervals[i][0]){
                v[j][1] = max(v[j][1], intervals[i][1]);
            }
            else{
                v.push_back(intervals[i]);
                j++;
            }      
        }
        return v;
    }
};