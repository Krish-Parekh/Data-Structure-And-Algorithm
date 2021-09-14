/*************************************************************************************** 
*  
* Median of two sorted arrays of same size
* There are 2 sorted arrays A and B of size n each. 
* Write an algorithm to find the median of the array obtained after merging the above 2 arrays(i.e. array of length 2n). 
* The complexity should be O(log(n)). 
*
* Love Babber Sheet (Que-35).
* Link: https://www.geeksforgeeks.org/median-of-two-sorted-arrays/
*
* Input:
* a = {1, 2, 3, 6}
* b = {4, 6, 8, 10}
* 
* Output:
* Median is 5.
*          
***************************************************************************************/
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

/*
    Solution :
    Time Complexity : O(M)
    Space Complexity : O(M)    ->M is size of array b[].

    Explanation: 
    1. First we need to merge both the arrays.

    2. After that, we need to sort the array.

    3. Then we have to find min and max index, those are the middle elements of entire array.

    4. Then, we will do addition of both the array and divide by 2, that will be the answer.

    Debug:
    a = {1, 2, 3, 6};
    b = {4, 6, 8, 10};

    i) Merging both the arrays.
    a = {1, 2, 3, 6, 4, 6, 8, 10};

    ii) Sorting the array
    a = {1, 2, 3, 4, 6, 6, 8, 10};

    iii) min = 4
         max = 5
    
    iv) answer = 5        -> (a[3] + a[4])/2 = (4+6)/2
*/

int main()
{
    vector<int> a = {1, 2, 3, 6};
    vector<int> b = {4, 6, 8, 10};

    for(int i=0; i<b.size(); i++){
        a.push_back(b[i]);
    }
    sort(a.begin(), a.end());
    
    int min = ((a.size()/2) + (a.size()%2));
    int max = min + 1;
    int answer = (a[min-1] + a[max-1])/2;

    cout << "Median Element of both the array is " << answer << endl;

    return 0;
}