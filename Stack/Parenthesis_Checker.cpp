#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool checkPar(string str)
{
    stack<char>st;
    bool ans = true;
    for(int i = 0 ; i < str.length() ; i++)
    {
        if(str[i] == '{' || str[i] == '(' || str[i] == '[')
        {
            st.push(str[i]);
        }
        else
        {
            switch (str[i])
            {
            case '}':
                if(!st.empty() and st.top() == '{')
                {
                    st.pop();
                }
                else
                {
                    ans = false;
                }
                break;
            
            case ')':
                if(!st.empty() and st.top() == '(')
                {
                    st.pop();
                }
                else
                {
                    ans = false;
                }
                break;
                
            case ']':
                if(!st.empty() and st.top() == '[')
                {
                    st.pop();
                }
                else
                {
                    ans = false;
                }
                break;
            default:
                break;
            }
        }
    }
    if(st.size() != 0)
    {
        ans = false;
    }
    return ans;
}

int main(){
    string str = "([)]";
    if(checkPar(str))
    {
        cout << "Balanced" << endl;
    }
    else
    {
        cout << "Not Balanced" << endl;
    }
    return 0;
}