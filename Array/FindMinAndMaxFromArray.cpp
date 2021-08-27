/*************************************************************************************** 
* 
* Maximum and minimum of an array using minimum number of comparisons
*
* Love Babber Sheet (Que-2).
* Link: https://www.geeksforgeeks.org/maximum-and-minimum-in-an-array/
*
* Input:  arr[] = {76, 45, 89, 43, 28, 56, 38}
* Output: Min = 28
*         Max = 89
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
Time Complexity  : O(N^2)
Space Complexity : O(1)

Explanation:
I have used Bubble Sort. 
There are many other sorting algorithm available, like Bubble Sort, Merge Sort, Selection Sort.

1. We will pass array and size of array to a function called sortArrayUsingBubbleSort().
2. There will be two for loops to traverse array and compare elements.
3. If(arr[j] > arr[j+1]), then we will swap the elememts.
4. After Sorting an array, We will print arr[0] (Which is minimum elements) and
                           We will print arr[size-1] (Which is maximum element).
*/

void sortArrayUsingBubbleSort(int *arr, int size){
    for(int i=0; i<size; i++){
        for(int j=0; j<size-i-1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void displayArray(int arr[], int size){
    for (int i=0; i<size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int arr[] = {76, 45, 89, 43, 28, 56, 38};
    int size = sizeof(arr)/sizeof(arr[0]);
    sortArrayUsingBubbleSort(arr, size);
    cout << "Min Element: " << arr[0] << endl;
    cout << "Max Element: " << arr[size-1] << endl;
}

/*
2.
Optimized Approach 
Time Complexity  : O(NLogN)
Space Complexity : O(1)

Explanation:
1. In this approach, We will use sort() in-built function in array.
   It will sort entire array.
2. Then, We will print arr[0] (Which is minimum elements) and
         We will print arr[size-1] (Which is maximum element).
*/

int main(){
    int arr[] = {76, 45, 89, 43, 28, 56, 38};
    int size = sizeof(arr)/sizeof(arr[0]);
    sort(arr, arr+size);
    cout << "Min: " << arr[0] << endl << "Max: " << arr[size-1];
}

/*
3.
Optimized Approach 
Time Complexity  : O(N)
Space Complexity : O(1)

Explanation:

1. We will pass array and size of array to a function called findMinMaxElement().
2. We will need two variable to store min and max element.
3. Intially, we will store arr[0] into min and max variable.
4. Then, We will use for loop to traverse an array
   Inside For loop, There will be if-else condition;
   if(min > arr[i]), 
       That means element available at index i is less than min.
       So, We will store element available at index i into min variable. 
   if(max < arr[i]), 
       That means element available at index i is greater than max.
       So, We will store element available at index i into max variable. 
5. Then, Finally we will print varible min and max.
*/

void findMinMaxElement(int *arr, int size){
    int min = arr[0], max = arr[0];
    for(int i=1; i<size; i++){
        if(min > arr[i]){
            min = arr[i];
        }
        else if(max < arr[i]){
            max = arr[i];
        }
    }
    cout << "Min: " << min << endl << "Max: " << max;
}

int main(){
    int arr[] = {76, 45, 89, 43, 28, 56, 38};
    int size = sizeof(arr)/sizeof(arr[0]);
    findMinMaxElement(arr, size);
}

/*
4.
Optimized Approach 
Time Complexity  : O(N)
Space Complexity : O(1)

Explanation:
1. In this approach, We will use vector<int> and two in-built function:
   *min_element(varr.begin(), varr.end());
   *max_element(varr.begin(), varr.end());
   That will give us min and max element, which we will store in different variables.

2. Then, We will simply print min and max element.
*/

int main(){
    vector<int> varr = {76, 45, 89, 43, 28, 56, 38};
    int min = *min_element(varr.begin(), varr.end());
    int max = *max_element(varr.begin(), varr.end());
    cout << min << endl << max;
}