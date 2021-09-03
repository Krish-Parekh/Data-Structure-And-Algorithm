/********************************************************************************** 
*
* Intersection of two arrays.
* Given two arrays a[] and b[] of size n and m respectively, 
* The task is to find intersection between these two arrays.
*
* Love Babber Sheet (Que-6).
* Link: https://www.geeksforgeeks.org/find-union-and-intersection-of-two-unsorted-arrays/
*
* What is Intersection in array? = Only Same elements in both the array.
*
* Input: a[] = {85, 25, 1, 32, 54, 6}, n = 6, 
*        b[] = {85,2}, m = 2
*
* Output: Intersection: {85}
*         Total Intersection Elements: 1
*
**********************************************************************************/

#include <iostream>
#include <set>
using namespace std;

/*
1.  Brute-Force-Approach

    Time Complexity  : O((N*lon N) * (M*log M))
    Space Complexity : O(N+M)

    Explanation:
    1. In this approch, we will create one int type of set.
       Why Set?
       Set can only have unique elements. Even if we try to insert duplicate element, it will ignore.

    2. Then, We will use nested for loop to compare all the elements.

    3. If elements in both the array are same, then we will insert that element into set.

    4. By this way, Only same element will get stored in set.

    5. We will display all the elements and
       We will return count of total element using s.size() inbuilt function.
    
    Note: We need to include <set> library to use its function.
       
*/
void display(set<int> s){
    for(auto i=s.begin(); i!=s.end(); i++){
        cout << *i << " ";
    }
    cout << endl;
}

int doIntersection(int a[], int n, int b[], int m){
    set<int> s;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(a[i] == b[j]){
                s.insert(a[j]);
            }
        }
    }

    /*for Displaying Intersection*/
    cout << "Intersection: ";
    display(s);

    return s.size();
}

int main()
{
    int a[] = {85, 25, 1, 32, 54, 6};
    int b[] = {85,2};
    int n = sizeof(a)/sizeof(a[0]);
    int m = sizeof(b)/sizeof(b[0]);

    int i = doIntersection(a, n, b, m);

    cout << "Total Intersection Elements: " << i;
}