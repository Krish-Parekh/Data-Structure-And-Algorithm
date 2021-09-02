/*************************************************************************************** 
* 
* Cyclically rotate an array by one
*
* Love Babber Sheet (Que-7).
* Link: https://practice.geeksforgeeks.org/problems/cyclically-rotate-an-array-by-one2614/1
*
* Input:  arr[] = {2, 4, 6, 8, 10, 12, 14}
* Output: arr[] = {14, 2, 4, 6, 8, 10, 12}
*          
***************************************************************************************/

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

/*
1.  Solution
    Time Complexity  : O(N)
    Space Complexity : O(1)

    Explanation:
    1. Firstly, we need to store last array to temp variable.
    2. Then, we have to shift all the element to right side like, from arr[n-2] to arr[n-1], from arr[n-3] to arr[n-2] and so on.
    3. For shift all the element, we need to use for loop.
    4. After for loop, we need to shift temp variable to arr[0].

    Debug:
    Input: arr[] = {1, 2, 3};

    Code: 
        temp = 3    //because temp = arr[n-1]
        Iteration 1:
            arr[] = {1, 2, 2};

        Iteration 2:
            arr[] = {1, 1, 2};

        arr[0] = 3    //because arr[0] = temp

    Output: arr[] = {3, 2, 1}
    
       
*/

void rotate(int arr[], int n)
{
    int temp = arr[n-1];
    
    for(int i=n-2; i>=0; i--){
        arr[i+1] = arr[i];
    }
    arr[0] = temp;
}

int main(){
    int arr[] = {2, 4, 6, 8, 10, 12, 14};
    int size = sizeof(arr)/sizeof(arr[0]);
    rotate(arr, size);

    for(int i=0; i<size; i++){
        cout << arr[i] << " ";
    }
}