#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    
    /*
        Solution:
        Time Complexity : O(N)
        Space Complexit : O(1)
        
        
        1. We will use kaden's algortirm to solve this question
        2. We take two variable 
            mx -> Total Maximum Sum
            sum -> Max So Far 
        3. We add every element in array with sum
        4. Then we check for 
            if mx(Maximum Sum) < sum(Max So Far)
             yes -> Update mx(Maximum sum) 
             No  -> Continue in loop
        5. Now Check 
                if Sum < 0 
                    yes -> Update Sum to 0 
            This condition is used because if Sum is less then 0 which means negative so 
            its no use to carry forward this Sum because we have to find Maimum Subarray sum 
    */
    int maxSubArray(vector<int>& nums) {
        int mx = INT_MIN;
        int sum = 0;
        for(int i = 0 ; i < nums.size() ; i++)
        {
            sum = sum + nums[i];
            if(mx < sum)
            {
                mx = sum;
            }
            sum = max(0,sum);
        }
        return mx;
    }
};



/*  
    When int is too large and we have to use long long int.
    Explanation, TC, SC are same as above approach.
*/

class Solution{
    public:
    // arr: input array
    // n: size of array
    // Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n){
        
        long long int mx = INT_MIN;
        long long int sum = 0;
        for(int i=0; i<n; i++){
            sum = sum + arr[i];
            if(sum > mx){
                mx = sum;
            }
            
    // Program will change from here for long long int
            if(sum < 0){
                sum = 0;
            }
        }
        return mx;
    }
};
