/******************************************************************************************** 
* 
* Shuffle String
* Given a string s and an integer array indices of the same length.
* The string s will be shuffled such that the character at the ith position moves to indices[i] in the shuffled string.
* Return the shuffled string.
*
* Link: https://leetcode.com/problems/shuffle-string/
*
* Input: s = "codeleet", indices = [4,5,6,7,0,2,1,3]
* Output: "leetcode"
*          
********************************************************************************************/

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

/*
    Solution :
    Time Complexity : O(N)
    Space Complexity : O(N)

    Explanation: 
    1. First of, we will copy give string to another new string.

    2. Then, we will traverse through entire string using for loop.

    3. At every iteration we will change character as per index.

    Debug:
    Input: s = "art", indices = [1, 0, 2]
    Output: "rat"

    i)  i = 0, s = "art", str = "art"

        Operation:
        str[1] = r   //str[indices[0]] = s[0]   (indices[0] is 1 and s[0] is r)       
        
        Ouput String: str = "rrt"


    ii)  i = 1, s = "art", str = "rrt"

        Operation:
        str[0] = a       //str[indices[1]] = s[1]   (indices[1] is 0 and s[1] is a)

        Ouput String: str = "rat"


    iii)  i = 1, s = "art", str = "rat"

        Operation:
        str[2] = t      //str[indices[2]] = s[2]   (indices[2] is 2 and s[2] is t)

        Ouput String: str = "rat"

*/

class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string str = s;
        for(int i=0; i<s.size(); i++){
            str[indices[i]] = s[i];
        }
        return str;
    }
};