/**************************************************************************************** 
* 
* Array Subset of another array
*
* Given two arrays: 
* a1[0..n-1] of size n and a2[0..m-1] of size m. 
* Task is to check whether a2[] is a subset of a1[] or not. 
* Both the arrays can be sorted or unsorted. 
* It may be assumed that elements in both array are distinct.
*
* Love Babber Sheet (Q-27):
* Link: https://practice.geeksforgeeks.org/problems/array-subset-of-another-array2317/1#
*
* Input:
* a1[] = {11, 1, 13, 21, 3, 7} 
* a2[] = {11, 3, 7, 1}
*
* Output:
* Yes
*
* Explanation:
* a2[] is a subset of a1[]
*          
****************************************************************************************/

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

/*
1.  Solution:
    Time Complexity : O(N) [n+n+n = 3n ~ N]
    Space Complexity : O(1)

    Explanation: 
    1)  First of, we will sort both the given array.

    2)  We will use two pointer concept. 
        i = It will traverse in a1[].
        j = It will traverse in a2[].

        Also, we need count variable, which will store the number of same elements in both the array.
    
    3)  Then we will use while loop,
        Inside while loop, we will compare both the array's element as per i and j index.
        If both are same then, we will increase count pointer.
        If a1[i] < a2[j], then we will incraese only i pointer to compare with a2[j] element.
        Else we will increase j pointer.

    4)  After coming out of while loop, we will compare count and size of a2[] array.
        If both are same then all the elements of a2[] are available in a1[], and we will return "Yes".
        If count is not same as size of a2[], then we will return "No".


    Debug:
    n = 5
    a1[] = {4, 2, 7, 3, 9}
    m = 2
    a2[] = {2, 4}

    Solution:

    i = 0, j = 0; count = 0;
    sort(a1, a1+n)   -> {2, 3, 4, 7, 9}
    sort(a2, a2+m)   -> {2, 4}

    1) While loop:
        i)  i = 0, j = 0
            if(a1[i] == a2[j])    -> (2 == 2, True)
                count = 1;
                i = 1
                j = 1

        ii)  i = 1, j = 1
            if(a1[i] == a2[j])    -> (3 == 7, False)
            if(a1[i] < a2[j])     -> (3 < 7, True)
                i = 2

        ii)  i = 2, j = 1
            if(a1[i] == a2[j])    -> (4 == 4, True)
                count = 2;
                i = 3
                j = 2
    
    Since (j<m) condition will not satisfy from here, so it will come out of the loop)

    2)  if (count == m)   (2 == 2, True)
            return "Yes";

*/

string isSubset(int a1[], int a2[], int n, int m)
{
    sort(a1, a1+n);
    sort(a2, a2+m);

    int i = 0, j = 0, count = 0;
    while(i<n && j<m)
    {
        if(a1[i] == a2[j])
        {
            count = count+1;
            i++;
            j++;
        }
        else if(a1[i] < a2[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    if(count == m)
    {
        return "Yes";
    }
    return "No";
}