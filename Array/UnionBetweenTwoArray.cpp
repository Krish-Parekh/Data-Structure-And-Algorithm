/********************************************************************************** 
*
* Union of two arrays.
* Given two arrays a[] and b[] of size n and m respectively, 
* The task is to find union between these two arrays.
*
* What is Union in array? = All the elements of both the array (without repeating).
*
* Input: a[] = {85, 25, 1, 32, 54, 6}, n = 6, 
*        b[] = {85,2}, m = 2
*
* Output: Union: {1, 2, 6, 25, 32, 54, 85}
*         Total Union Elements: 7
*
**********************************************************************************/

#include <iostream>
#include <set>
using namespace std;

/*
1.  Brute-Force-Approach

    Time Complexity  : O(N+M)
    Space Complexity : O(N+M)

    Explanation:
    1. In this approch, we will create one int type of set.
       Why Set?
       Set can only have unique elements. Even if we try to insert duplicate element, it will ignore.

    2. Then, We will use for loop for first array to insert all the element into set.

    3. Again, we will use for loop for second array to insert all the elemwnts into set.

    4. Now, Set contains all the elements from both the array. (It cannot have a duplicate elements).

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

int doUnion(int a[], int n, int b[], int m)
{
    set<int> s;

    for (int i = 0; i < n; i++){
        s.insert(a[i]);
    }
    for (int i = 0; i < m; i++){
        s.insert(b[i]);
    }

    /*for Displaying union*/
    cout << "Union: ";
    display(s);

    return s.size();
}

int main()
{
    int a[] = {85, 25, 1, 32, 54, 6};
    int b[] = {85,2};
    int n = sizeof(a)/sizeof(a[0]);
    int m = sizeof(b)/sizeof(b[0]);

    int u = doUnion(a, n, b, m);

    cout << "Total Union Elements: " << u << endl;
}