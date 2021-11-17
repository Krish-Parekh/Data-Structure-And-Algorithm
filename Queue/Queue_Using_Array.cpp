#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class QueuesUsingArray{
    int *data;
    int nextIndex;
    int firstIndex;
    int size;
    int capacity;
    public: 
    QueuesUsingArray(int totalSize){
        data = new int[totalSize];
        nextIndex = 0;
        firstIndex = -1;
        size = 0;
        capacity = totalSize;
    }
    int getsize(){
        return size;
    }
    bool isEmpty(){
        return size == 0;
    }
    void enqueue(int element){
        if(size == capacity){
            cout << "Queue is full" <<endl;
            return;
        }
        data[nextIndex] = element;
        nextIndex  = (nextIndex + 1)%capacity;
        if(firstIndex == -1){
            firstIndex = 0;
        }
        size++;
    }
    int dequeue(){
        if(size == capacity){
            cout << "Queue is full" <<endl;
            return 0;
        }
        int ans = data[firstIndex];
        firstIndex = (firstIndex + 1) % capacity;
        size--;
        return ans;
    }
    int top(){
        if(size == capacity){
            cout << "Queue is full" <<endl;
            return 0;
        }
        return data[firstIndex];
    }

};
int main(){
    QueuesUsingArray q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    cout << q.getsize() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.top() <<endl;
    return 0; 
}