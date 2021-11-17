#include <iostream>
#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Stack
{
    T *arr;
    int top;
    int capacity;

public:
    Stack()
    {
        arr = new T[5];
        this->top = 0;
        this->capacity = 5;
    }

    bool isEmpty()
    {
        return top == 0;
    }

    int size()
    {
        return top;
    }

    T top()
    {
        return arr[top - 1];
    }
    void push(T data)
    {
        if (top == capacity)
        {
            T *newArr = new T[2 * capacity];
            for (int i = 0; i < capacity; i++)
            {
                newArr[i] = arr[i];
            }
            capacity = capacity * 2;
            delete [] arr;
            arr = newArr;
        }
        arr[top++] = data;
    }

    T pop()
    {
        if(isEmpty())
        {
            cout << "Stack is Empty" << endl;
            return INT_MIN;
        }
        else
        {
            return arr[--top];
        }
    }
};

int main()
{
    Stack<int>s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    cout << "Top most element of stack " << s1.top() << endl;
    cout << s1.pop() << endl;
    cout << "Total size of stack " << s1.size() << endl;
    while (!s1.isEmpty())
    {
        cout << s1.pop() << endl;
    }
    
    return 0;
}