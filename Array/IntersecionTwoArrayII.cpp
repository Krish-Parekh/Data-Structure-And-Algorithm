/*************************************************************************************** 
* 
* 350. Intersection of Two Arrays II
*
* Link: https://leetcode.com/problems/intersection-of-two-arrays-ii/
*
* Input: 
* nums1 = [1,2,2,1], nums2 = [2,2]
*
* Output: [2,2]
*          
***************************************************************************************/

#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;

/*
    1.  Brute Force Approach:
        Time Complexity: O(n^2)
        Space Complexity: O(n)

*/
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        for(int i=0; i<nums1.size(); i++){
            for(int j=0; j<nums2.size(); j++){
                if(nums1[i] == nums2[j]){
                    ans.push_back(nums2[j]);
                    nums2[j] = -1;
                    break;
                }
            }
        }
        return ans;
    }
};

/*
    2.  Optimized Approach: (Using map)
        Time Complexity: O(n)
        Space Complexity: O(n)

*/

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        map<int, int> count;
        
        for(int i=0; i<nums1.size(); i++){
            count[nums1[i]]++;
        }
        
        for(int i=0; i<nums2.size(); i++){
            if(count[nums2[i]] > 0){
                count[nums2[i]]--;
                ans.push_back(nums2[i]);
            }
        }
        return ans;
    }
};