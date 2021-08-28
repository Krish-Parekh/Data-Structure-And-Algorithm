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
        Those pointers are zero, one and two.

    2.  Then, We will use while loop to traverse through array,
        one(intialially index is 0) to two(intialially index is n-1).

    3.  Inside While loop, We have to compare all the element with 0, 1 and 2 with a[one] element.
        if(element is 0), then swap a[zero](zero is meant to store 0) and a[one].
            Also, We will increase min and avg pointer to compare next element.

        if(element is 1), then there is no need to swap as a[one] is meant to store 1s. 
            Just have to increase one pointer.

        if(element is 2), then swap a[two](two is meant to store 2) and a[one].
            Also, We will decrease two pointer.
            Note: Here, we dont increase one pointer, as we do not know, 
                  What we will receive at a[one] after swapping with a[two], 
                  So again, We have to compare that element.
                  
                  
    Dry Run:
    Input: [0, 2, 1, 2, 0]
    Output: [0, 0, 1, 2, 2]
   
    1.  while (0 <= 5)
    
        (i) 1st iteration
            zero=0, one=0, two=4
            if a[one] == 0 (condition is true)
                swap (a[one], a[zero])   (Because, zero will track series of 0s)
                zero = 1
                one = 1
            array[] : [0, 2, 1, 0, 2]
        
        (ii) 2nd iteration
            zero=1, one=1, two=4
            if a[two] == 2  (condition is true)
                swap (a[one], a[two])   (Because, two will track series of 2s)
                two = 3
            array[] : [0, 2, 1, 0, 2]
            
             
        (iii) 3rd iteration
            zero=1, one=1, two=3
            if a[two] == 2  (condition is true)
                swap (a[one], a[two])   (Because, two will track series of 2s)
                two = 2
            array[] : [0, 0, 1, 2, 2]
           
        (iv) 4th iteration
            zero=1, one=1, two=2
            if a[one] == 0 (condition is true)
                swap (a[one], a[zero])   (Because, zero will track series of 0s)
                zero = 2
                one = 2
            array[] : [0, 0, 1, 2, 2]
    
        (v) 5th iteration
            zero=2, one=2, two=2
            if a[one] == 1 (condition is true)
                one = 3
            array[] : [0, 0, 1, 2, 2]
                  
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
        int zero=0, one=0, two=n-1;
        
        while(one <= two){
            if(a[one] == 0){
                swap(&a[one], &a[zero]);
                zero++;
                one++;
            }
            else if(a[one] == 1){
                one++;
            }
            else if(a[one] == 2){
                swap(&a[one], &a[two]);
                two--;
            }
        }
    }
};
