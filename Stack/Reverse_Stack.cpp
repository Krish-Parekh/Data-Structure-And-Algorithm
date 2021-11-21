#include <iostream>
#include <bits/stdc++.h>
using namespace std;
stack<int> st;

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

void reverse_stack()
{
    if(st.empty())
    {
        return;
    }
    else
    {
        int x = st.top();
        st.pop();
        reverse_stack();
        insert_at_bottom(x);
    }
}

int main()
{
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    reverse_stack();

    cout << "Reverse: ";
    while(!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}