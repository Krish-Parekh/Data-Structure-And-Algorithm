#include <iostream>
#include <bits/stdc++.h>
using namespace std;

stack<int>st;
void insert_at_bottom(int x) 
{
    if(st.empty())
    {
        st.push(x);
        return;
    }
    else
    {
        int a = st.top();
        st.pop();
        insert_at_bottom(x);
        st.push(a);
    }
}
int main()
{
    st.push(1);
    st.push(2);
    insert_at_bottom(3);
    while(!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}