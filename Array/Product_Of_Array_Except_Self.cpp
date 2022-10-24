#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/*
leetCode : https://leetcode.com/problems/product-of-array-except-self/
*/

vector<int> productExceptSelf(vector<int> &nums)
{
    int n = nums.size();
    vector<int> prefix(n);
    vector<int> suffix(n);
    prefix.at(0) = nums.at(0);
    suffix.at(n - 1) = nums.at(n - 1);
    for (int i = 1; i < n; i++)
    {
        prefix.at(i) = prefix.at(i - 1) * nums.at(i);
    }

    for (int j = n - 2; j >= 0; j--)
    {
        suffix.at(j) = suffix.at(j + 1) * nums.at(j);
    }

    vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            ans.at(i) = suffix.at(i + 1);
        }
        else if (i == n - 1)
        {
            ans.at(i) = prefix.at(i - 1);
        }
        else
        {
            ans.at(i) = prefix.at(i - 1) * suffix.at(i + 1);
        }
    }

}