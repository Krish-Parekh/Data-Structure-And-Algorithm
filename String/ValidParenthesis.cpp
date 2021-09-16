/*************************************************************************************** 
*  
* Valid Parentheses
*
* Link: https://leetcode.com/problems/valid-parentheses/
*
* Input: s = "()"
* Output: true
*
* Input: s = "()[]{}"
* Output: true  

***************************************************************************************/

#include <bits/stdc++.h>
#include <iostream>
using namespace std;


/*
    Solution :
    Time Complexity : O(N)
    Space Complexity : O(1)

    Explanation: 
    1.  We will traverse string using for loop.

    2.  If we find opening bracket then we will push it to stack.

    3.  If we find closing bracket then we will compare top of stack element with the closing bracket
        If it does not match pattern then we will return false.

    4.  At the end of loop, we will return true. (If false never get returned.)
    
*/

class Solution {
public:
    bool isValid(string s) 
    {
        stack<char> st;

        for(int i=0; i<s.size(); i++)
        {
            if(s[i] == '('|| s[i] == '{' || s[i] == '[')
            {
                st.push(s[i]);
            }
            else
            {
                if(st.empty())
                {
                    return false;
                }
                else if(s[i] == ')' && st.top() != '(') 
                {
                    return false;
                }
                else if(s[i] == '}' && st.top() != '{')
                {
                    return false;
                }
                else if(s[i] == ']' && st.top() != '[') 
                {
                    return false;
                }
                st.pop();
            }
        }
        if(st.empty()){
            return true;
        }
        return false;
    }
};