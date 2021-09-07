/******************************************************************************************** 
* 
* Common elements
* Given three arrays sorted in increasing order. Find the elements that are common in all three arrays.
*
* Love Babber Sheet (Q-19):
* Link: https://practice.geeksforgeeks.org/problems/common-elements1132/1#
*
* Input:
* n1 = 6; A = {1, 5, 10, 20, 40, 80}
* n2 = 5; B = {6, 7, 20, 80, 100}
* n3 = 8; C = {3, 4, 15, 20, 30, 70, 80, 120}
*
* Output: 20 80
* Explanation: 20 and 80 are the only common elements in A, B and C.
*          
********************************************************************************************/

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

/*
    Solution :
    Time Complexity : O(n1 + n2+ n3) [Not sure about vector.assign() time complexity]
    Space Complexity : O(1)

    Explanation: 
    We will traverse all the arrays same time and also maintain pointers for all the array.
    Inside a loop, If we found same element in all three arrays, then we will insert that element into set.
        Why set?
        Its highly possible that, same elements in one array can be available in other arrays also.
        Example. a[] = {3,3,3}
                 b[] = {3,3,3}
                 c[] = {3,3,3}

                 Output = {3}

                 If we dont use set, our output will be like {3,3,3}, Which is Wrong.   
                 Thats why we need to use set.

    After traversing, we will copy all set element into vector and return vector.

    Debug:
    a[] = {1,2,3}, b[] = {3,4,5}, c = {3,7,8}

    i)  i = 0, j = 0, k = 0
        if(1 == 3 && 3 == 3)    -> False
        if(1 < 3)               -> True
            i = 1
        set = {}

    ii) i = 1, j = 0, k = 0
        if(2 == 3 && 3 == 3)    -> False
        if(2 < 3)               -> True
            i = 2
        set = {}

    iii)i = 2, j = 0, k = 0
        if(3 == 3 && 3 == 3)    -> True
            s.insert(3)
            i = 3
            j = 1
            k = 1
        set = {3}

    After coming out of the loop we will assign all set elements into vector.
    v = {3} 
*/

class Solution
{
    public:    
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            int i=0, j=0, k=0;
            vector<int> v;
            set<int> s;

            while(i < n1 && j < n2 && k < n3){
                if(A[i]==B[j] && B[j]==C[k]){
                    s.insert(A[i]);
                    i++; 
                    j++;
                    k++;
                }
                else if (A[i] < B[j]){
                    i++;
                }
                else if(B[j] <C[k]){
                    j++;
                }
                else {
                    k++;
                }
            }

            v.assign(s.begin(), s.end());
            return v;
        }

};