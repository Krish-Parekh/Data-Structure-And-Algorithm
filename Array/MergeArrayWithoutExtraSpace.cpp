/******************************************************************************************** 
* 
* Merge Without Extra Space
* Given two sorted arrays arr1[] of size N and arr2[] of size M. Each array is sorted in non-decreasing order. 
* Merge the two arrays into one sorted array in non-decreasing order without using any extra space.
*
* Love Babber Sheet (Q-12):
* Link: https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays5135/1#
*
* Input:
* N = 4, M = 5
* arr1[] = {1, 3, 5, 7}
* arr2[] = {0, 2, 6, 8, 9}
* Output: 0 1 2 3 5 6 7 8 9
*
* Explanation: Since you can't use any extra space, modify the given arrays to form 
* arr1[] = {0, 1, 2, 3}
* arr2[] = {5, 6, 7, 8, 9}
*          
********************************************************************************************/

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

/*
    Solution :
    Time Complexity : O(N + M + NLogN + MLogM)
    Space Complexity : O(1)

    Explanation: 
    Overall logic is to traverse first array from back to front and second array from front to back.
    If first array's element is greater than second array's element, then swap both the elements.
    Then decrease first arrays pointer and increase second array's pointer.
    After completing loop, Sort both the arrays.

    1. First we will initilize i and j variable to track both the array's index.
       i = n-1 (It will track arr1's index from back to front).
       j = 0 (It will track arr2's index from front to back).

    2. if(arr1[i] > arr2[j])
       If the condition becomes true, then we have to swap both the elements.

    3. Whether above condition becomes true or false, we have to decrease i pointer and increase j pointer.

    4. After completing loop, we have to sort both the arrays. 

    5. It will give final sorted array without using extra space.

    Debug:
    arr1[n] = {1,3,5,7}
    arr2[m] = {0,2,6,8,9}
    
    i)  Loop:
        1st Iteration:
            i=3, j=0;
            if(7 > 0)   ->True
                swap both the elements
            i = 2       -> Because of i--
            j = 1       -> Because of j++

            Output: arr1[] = {1,3,5,0}
                    arr2[] = {7,2,6,8,9}
        
        2nd Iteration:
            i=2, j=1;
            if(5 > 2)   -> True
                swap both the elements
            i = 1       -> Because of i--
            j = 2       -> Because of j++

            Output: arr1[] = {1,3,2,0}
                    arr2[] = {7,5,6,8,9}

        3rd Iteration:
            i=1, j=2;
            if(3 > 6)   -> False
                swap both the elements
            i = 0       -> Because of i--
            j = 3       -> Because of j++

            Output: arr1[] = {1,3,2,0}
                    arr2[] = {7,5,6,8,9}

        3rd Iteration:
            i=0, j=3;
            if(1 > 8)   -> False
                swap both the elements
            i = -1      -> Because of i--
            j = 4       -> Because of j++

            Output: arr1[] = {1,3,2,0}
                    arr2[] = {7,5,6,8,9}

    ii) sort(arr1, arr1+n)    -> arr1[] = {0,1,2,3}
        sort(arr1, arr1+n)    -> arr2[] = {5,6,7,8,9}

*/

class Solution{
public:
	void merge(int arr1[], int arr2[], int n, int m) {

	    int i = n-1, j = 0;
	    
	    while(i>=0 && j<m){
	        
	        if(arr1[i] > arr2[j]){
	            int temp = arr1[i];
	            arr1[i] = arr2[j];
	            arr2[j] = temp;
	        }
            i--;
            j++;

	    }
        sort(arr1, arr1+n);  
        sort(arr2, arr2+m);  
	}
};