#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>> arr)
{
    stack<pair<int,int>>st;
    vector<vector<int>>ans;
    sort(arr.begin() , arr.end());
    st.push({arr[0][0],arr[0][1]});

    for(int i = 1 ; i < arr.size() ; i++)
    {
        int start1 = st.top().first;
        int end1 = st.top().second;

        int start2 = arr[i][0];
        int end2 = arr[i][1];

        if(end1 < start2)
        {
            st.push({start2,end2});
        }
        else
        {
            st.pop();
            end1 = max(end1,end2);
            st.push({start1,end1});
        }
    }
    while(!st.empty())
    {
        ans.push_back({st.top().first,st.top().second});
        st.pop();
    }
    sort(ans.begin(),ans.end());
    return ans;
}

int main(){
    vector<vector<int>> arr = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> ans = mergeIntervals(arr);
    for(int i = 0 ; i < ans.size() ; i++)
    {
        cout << ans[i][0] << " " << ans[i][1] << endl;
    }
    return 0;
}