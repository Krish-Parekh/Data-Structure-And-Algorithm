/*************************************************************************************** 
* 
* Given an array (or string), the task is to reverse the array/string
*
* Love Babber Sheet (Que-1).
* Link: https://www.geeksforgeeks.org/write-a-program-to-reverse-an-array-or-string/#
*
* Input:  arr[] = {10, 29, 37, 46, 58, 64, 76, 82, 94}
* Output: arr[] = {94, 82, 76, 64, 58, 46, 37, 29, 10}
*          
***************************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"
using namespace std;

/*
1.
Brute-Force-Approach 
Time Complexity  : O(N)
Space Complexity : O(1)

Explanation:
1. We will pass array and size of array to a function called reverseArray().
2. Then, We will intilize start=0 and end=size-1.
3. Then, We will use loop and traverse through entire array and swap element as per start and end index.
4. Also, We need to increase start and decrease end pointer/variable at the end of loop.

Debug:

while(0 < 9)
    temp = 10
    arr[start] = 94
    arr[end] = 10
    start++ (start will become 1)
    end-- (end will become 8)
       
*/

void reverseArray(int *arr, int size){
    int start = 0, end = size-1;
    while(start<end){
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void displayArray(int arr[], int size){
    for (int i=0; i<size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main(){
    //Sorting Using Array
    int arr[] = {10, 29, 37, 46, 58, 64, 76, 82, 94};
    int size = sizeof(arr)/sizeof(arr[0]);
    reverseArray(arr, size);
    displayArray(arr, size);
}



/*
2.
Optimized Approach using Vector
Time Complexity  : O(N)
Space Complexity : O(1)

Explanation:
1. We will call in-built function reverse() 
2. Note: For Using Vector, We need to use <vector> library.
         For Using Reverse Function, We need to use <algorithm> library.
       
*/
int main()
{
    //Sorting Using Vector and In-built Function
    vector<int> varr = {10, 29, 37, 46, 58, 64, 76, 82, 94};
    reverse(varr.begin(),varr.end());
    for (int i=0; i<varr.size() ; i++){
        cout << varr[i] << " ";
    }
    return 0;
}