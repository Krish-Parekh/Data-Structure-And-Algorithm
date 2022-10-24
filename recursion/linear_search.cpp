#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int linearSearch(int arr[], int index, int target, int len)
{
    if (index == len)
    {
        return -1;
    }

    if (arr[index] == target)
    {
        return index;
    }
    else
    {
        return linearSearch(arr, index + 1, target, len);
    }
}

vector<int> searchAll(int arr[], int index, int target, int len, vector<int>& ans)
{
    if (index == len)
    {
        return ans;
    }
    if (arr[index] == target)
    {
        ans.push_back(index);
    }
    return searchAll(arr, index + 1, target, len, ans);
}

int main()
{
    int arr[] = {1, 2, 2, 2, 3, 4, 5};
    int len = sizeof(arr) / sizeof(arr[0]);
    int index = linearSearch(arr, 0, 3, len);
    cout << "Target is present at index : " << index;
    
    vector<int> ans;
    vector<int> res = searchAll(arr, 0, 2, len, ans);
    for(int i : res){
        cout << i << " " << endl;
    }
    return 0;
}