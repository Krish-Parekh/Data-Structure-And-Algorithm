#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<long long> nextLargerElement(vector<long long> v, int n)
{
    stack<long long> st;
    vector<long long> ans;
    for (int i = n - 1; i >= 0; i--)
    {
        if (st.empty())
        {
            ans.push_back(-1);
            st.push(v[i]);
        }
        else if (st.top() > v[i] and !st.empty())
        {
            ans.push_back(st.top());
            st.push(v[i]);
        }
        else if (st.top() < v[i] and !st.empty())
        {
            while (!st.empty())
            {
                if (st.top() < v[i])
                {
                    st.pop();
                }
                else
                {
                    break;
                }
            }
            if (!st.empty())
            {
                ans.push_back(st.top());
            }
            else
            {
                ans.push_back(-1);
            }
            st.push(v[i]);
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main()
{
    vector<long long>v1 = {1,3,2,4};
    vector<long long>ans = nextLargerElement(v1,v1.size());
    for(int i = 0 ; i < ans.size() ; i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}