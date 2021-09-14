/*************************************************************************************** 
*  
* Median of two sorted arrays of different sizes
* Given two sorted arrays, a[] and b[], the task is to find the median of these sorted arrays, 
* in O(log n + log m) time complexity, when n is the number of elements in the first array, 
* and m is the number of elements in the second array. 
*
* Love Babber Sheet (Que-36).
* Link: https://www.geeksforgeeks.org/median-of-two-sorted-arrays-of-different-sizes/
*
* Input: ar1[] = {-5, 3, 6, 12, 15}
*        ar2[] = {-12, -10, -6, -3, 4, 10}
* Output : The median is 3.

* Explanation : The merged array is :
*        ar3[] = {-12, -10, -6, -5 , -3, 3, 4, 6, 10, 12, 15},
*        So the median of the merged array is 3
*          
***************************************************************************************/
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

/*
    Solution :
    Time Complexity : O(M)
    Space Complexity : O(M)    -> M is size of array b[].

    Explanation: 
    1.  We will merge both the array.

    2.  Then we will sort the array.

    3.  If size of array is even, then
        We will get median element and its next element.
        We will do addition of both the element and then divide by 2. 
        That is the answer.

    4.  If size of array is odd, then
        We will find middle element and return it.
    
*/

int main()
{
    vector<int> a = {-5, 3, 6, 12, 15};
    vector<int> b = {-12, -10, -6, -3, 4, 10};

    for(int i=0; i<b.size(); i++){
        a.push_back(b[i]);
    }
    sort(a.begin(), a.end());

    int n = a.size();
    int min, max, answer, i;
    if(n%2 == 0)
    {
        min = n/2;
        max = min+1;
        answer = (a[min-1] + a[max-1])/2;
    }
    else
    {
        i = n/2 + n%2;
        answer = a[i-1];
    }
    cout << "Median Element of both the array is " << answer << endl;

    return 0;
}