/*************************************************************************************** 
* You are given an array prices where prices[i] is the price of a given stock on the ith day.
* 
* You want to maximize your profit by choosing a single day to buy one stock and choosing a different day 
* in the future to sell that stock.
*
* Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return * 0.   
* Input: prices = [7,1,5,3,6,4]
* Output: 5
* Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
* Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.       
***************************************************************************************/
/*


    Solution:
    Time Complexity  : O(N)
    Space Complexity : O(1)

    Explanation:
    1. This question is similar to maximum subarray 
    2. We use two variable 
        -> max_profit = it is to maintain maximum profit so far
        -> buy = it is maintain to buy stock at minimum price
    
    Debug:
    prices = [7,1,5,3,6,4]

    max_profit = INT_MIN;
    buy = INT_MAX;
    
    when i = 0
        buy = min(INT_MAX , 7) // 7
        max_profit  = max(INT_MIN , 7-7) // 0
    
    when i = 1
        buy = min(7 , 1) // 1
        max_profit  = max(0 , 1-1) // 0
    
    when i = 2
        buy = min(1 , 5) // 1
        max_profit  = max(0 , 5-1) // 4
    
    when i = 3
        buy = min(1 , 3) // 1
        max_profit  = max(4 , 3-1) // 4
    
    when i = 4
        buy = min(1 , 6) // 1
        max_profit  = max(4 , 6-1) // 5
    
    when i = 5
        buy = min(1 , 4) // 1
        max_profit  = max(5 , 4-1) // 3
    
    return max_profit // 5
*/



#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = INT_MIN;
        int buy = INT_MAX;
        for(int i = 0; i < prices.size() ; i++)
        {
            buy = min(buy , prices[i]);
            max_profit = max(max_profit,prices[i] - buy);
        }
        return max_profit;
    }
};