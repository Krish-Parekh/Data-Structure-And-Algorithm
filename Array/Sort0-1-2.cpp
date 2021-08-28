/******************************************************************************************** 
* 
* Given an array of size N containing only 0s, 1s, and 2s; sort the array in ascending order.
*
* Love Babber Sheet (Que-4).
* Link: https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1
*
* Input:  a[] = {0 2 1 2 0}
* Output: a[] = {0 0 1 2 2}
*          
********************************************************************************************/

#include<bits/stdc++.h>
using namespace std;

/*
1.  Brute-Force-Approach 
    Time Complexity  : O(N)
    Space Complexity : O(1)

    Explanation:

    1.  We need three pointers, which can point to series of 0s, 1s and 2s.

    2.  Then, We will use while loop to traverse through 
        avg(intialially index is 0) to max(intialially index is n-1).

    3.  Inside While loop, We have to compare all the element with 0, 1 and 2 with avg element.
        if(element is 0), then swap a[min](min is meant to store 0) and a[avg].
            Also, We will increase min and avg pointer to compare next element.

        if(element is 1), then there is no need to swap as avg is meant to store 1s. 
            Just have to increase avg pointer.

        if(element is 2), then swap a[max](max is meant to store 2) and a[avg].
            Also, We will decrease max pointer.
            Note: Here, we dont increase avg pointer, as we do not know, 
                  what we will receive at a[avg] after swapping with a[max], so we again have to compare that element.

*/

class Solution
{
    public:
    void swap(int *a, int *b){
        int temp = *a;
            *a = *b;
            *b = temp;
    }
    void sort012(int a[], int n)
    {
        int min=0, avg=0, max=n-1;
        
        while(avg <= max){
            if(a[avg] == 0){
                swap(&a[avg], &a[min]);
                min++;
                avg++;
            }
            else if(a[avg] == 1){
                avg++;
            }
            else if(a[avg] == 2){
                swap(&a[avg], &a[max]);
                max--;
            }
        }
    }
};