/******************************************************************************************** 
* 
* Move all negative numbers to beginning and positive to end with constant extra space
*
* Love Babber Sheet (Que-5).
* Link: https://www.geeksforgeeks.org/move-negative-numbers-beginning-positive-end-constant-extra-space/
*
* Input:  v = {-1, 3, -5, -2, 6}
* Output: v = {-1, -5, -2, 3, 6}
*          
********************************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

/*
Note: This problem can be solved using sorting algorithms like bubble sort or selection sort.
      Since, Those algorithms are expensive in terms of time complexity (O(N^2)),
             We will be not going to use sorting algorithm.

1.  Optimized Approach 
    Time Complexity  : O(N)
    Space Complexity : O(1)

    Explanation:

    1.  We need One extra pointer (track=0), along with for loop's pointer (i=0).
        Total, there will be two pointers.

    2.  We will start for loop from 0 to size-1.

    3.  We will check condition, whether current element is less than 0 or not.
        if Yes, then we will compare pointers. 
            If both pointer are at same place, then there is no need to swap element.
            If both pointer are at different place, then we will swap elements (v[i], v[track]).
            Irrespective of pointers are at same place or not. We will be going to increase track pointer.

        if No, Simply we will move to next iteration.
                                 
Debug:
Input: v = {-1, 3, -5, -2, 6}
Output: v = {-1, -5, -2, 3, 6}

1.  int track = 0
    for(int i=0; i<v.size(); i++)

    (i) 1st iteration
        track = 0, i = 0
        if v[i] < 0     (Condition True, because -1 < 0)
            if i != track   (Condtion False, because 0 != 0)
                //Code flow will not get in inside as condition is false
            track = 1    (Because track++)

        v = {-1, 3, -5, -2, 6}
    
    (ii) 2nd iteration
        track = 1, i = 1
        if v[i] < 0     (Condition False, because 3 < 0)
                //Code flow will not get in inside as condition is false

        v = {-1, 3, -5, -2, 6}
            
    (iii) 3rd iteration
        track = 1, i = 2
        if v[i] < 0     (Condition True, because -5 < 0)
            if i != track   (Condtion True, because -2 != 1)
                We will swap -5 and 3.
            track = 2    (Because track++)

        v = {-1, -5, 3, -2, 6}
        
    (iv) 4th iteration
        track = 2, i = 3
        if v[i] < 0     (Condition True, because -2 < 0)
            if i != track   (Condtion True, because 3 != 2)
                We will swap -2 and 3.
            track = 3    (Because track++)

        v = {-1, -5, -2, 3, 6}

    (v) 5th iteration
        track = 3, i = 4
        if v[i] < 0     (Condition False, because 6 < 0)
                //Code flow will not get in inside as condition is false

        v = {-1, -5, -2, 3, 6}
                  
*/

void swap(int &a, int &b){
    int temp = a;
        a = b;
        b = temp;
}

void moveNegativeElementToOneSide(vector<int> &v){
    int track = 0;

    for(int i=0; i<v.size(); i++){
        if(v[i] < 0){
            if(i != track){
                swap(v[i], v[track]);
            }
            track++;
        }
    }
}

int main()
{
    vector<int> v = {-1, 3, -5, -2, 6};
    moveNegativeElementToOneSide(v);
    for (int i=0; i<v.size() ; i++){
        cout << v[i] << " ";
    }
    return 0;
}