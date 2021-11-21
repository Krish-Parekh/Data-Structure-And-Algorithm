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

void sort_stack()
{
    if(st.empty())
    {
        return;
    }
    else
    {
        int x = st.top();
        st.pop();
        sort_stack();
        if(st.size() > 0)
        {
            if(x < st.top())
            {
                insert_at_bottom(x);
            }
        }
        else
        {
            insert_at_bottom(x);
        }
    }
}



int main(){
    
    st.push(3);
    st.push(2);
    st.push(1);
    sort_stack();
    while(!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}