/* Given n non-negative integers a1, a2, ..., an , where each represents a point 
* at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of * the line i is * at (i, ai) and (i, 0). Find two lines, which, together with the  * x-axis forms a container, such that the container contains the most water. 
* Notice that you may not slant the container.*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

    /*
        Brute-Force Solution :
        Time complexity : O(N^2)
        Space Complexity : O(1)

        Explanation :
        1. We use two for loop and check every possible combination to find max area within array
        2. mx -> is used to maintain max area
        3. Logic : 
            1. min(height[i],height[j]) : As water shouldn't slant inshort it shouldn't spill out of container
            for eg:
            we get two element 4 and 7 think this height as two side of containers
            So if we want to fill maximum water in this container I can fill upto 4 because we don't have to spill water 
            2. j-i : this acts like width between those element
            
            Inshort:
            area = width * length 
            length = min(height[i],height[j])
            width  = j-i  

    */
    int maxArea(vector<int>& height) {
        int n = height.size();
        int mx = INT_MIN;
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = i+1 ; j < n ; j++)
            {
                mx = max(mx , min(height[i],height[j]) * (j-i));   
            }
        }
        return mx;
    }

    /*
        Optimized Solution :
        Time complexity : O(N)
        Space Complexity : O(1)

        Explanation :
        1. We use two for loop and check every possible combination to find max area within array
        2. mx -> is used to maintain max area
        3. We use two pointer algorithm 
            -> why : as we see we have to make comparison between two elements + array is not sorted 
        4. Rest Logic remains same     
    */


    int maxArea(vector<int>& height){
        int n = height.size();
        int mx = INT_MIN;
        int i = 0;
        int j = n-1;
        while(i < j)
        {
            mx = max(mx ,min(height[i],height[j]) * (j-i));
            if(height[i] < height[j])
            {
                i++;
            }
            else
            {
                j--;    
            }
        }
        return mx;
    }   
};
