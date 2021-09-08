/******************************************************************************************** 
* 
* Print all the duplicates in the input string
* 
* Love Babber Sheet (Q-3):
* Link: https://www.geeksforgeeks.org/print-all-the-duplicates-in-the-input-string/
*
* Input:
* s = "aaabcc"
*
* Output: 
* a, 3
* c, 2
*          
********************************************************************************************/

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

/*
1.  Solution using map:
    Time Complexity : O(NLogN)
    Space Complexity : O(size of map)

    Note: Map will take O(LogN) time for insertion.

    Explanation: 
    1) First of all, we will create a map to store character and it's count.

    2) We will run for loop to traverse entire string. While traversing, we will insert every character to map.
       If character already exist, than map will increase its count.
       Else, It will store character.
    
    3) After that, we will run second for loop for dislaying elements, which exist more than 1 times in string using map count.

    Debug:
    i)  In first for loop,
        map will be:
        Char-> a, Count-> 3
        Char-> d, Count-> 1
        Char-> h, Count-> 1
        Char-> i, Count-> 2
        Char-> k, Count-> 1
        Char-> m, Count-> 1
        Char-> n, Count-> 1
        Char-> p, Count-> 1
        Char-> r, Count-> 2
        Char-> s, Count-> 1
        Char-> u, Count-> 1
        Char-> y, Count-> 1

    ii) In second for loop,
        If(i.second > 1),
            If count is more than one, then it will print character and its count.
            Char-> a, Count-> 3
            Char-> i, Count-> 2
            Char-> r, Count-> 2
    
*/

int main()
{
    string s = "dharmikpansuriya";
    map<char, int> mp;

    for(int i=0; i<s.size(); i++){
        mp[s[i]]++;
    }

    for(auto i:mp){
        if(i.second > 1){
            cout << "Char-> " << i.first << ", "
                 << "Count-> " << i.second << endl;
        }
    }
    return 0;
}

/*
2.  Solution using unordered map:
    Time Complexity : O(N)
    Space Complexity : O(size of map)

    Note: Unordered Map will take O(1) time for insertion.

    Explanation: 
    1) First of all, we will create a unordered map to store character and it's count.

    2) We will run for loop to traverse entire string. While traversing, we will insert every character to unordered map.
       If character already exist, than map will increase its count.
       Else, It will store character.
    
    3) After that, we will run second for loop for dislaying elements, which exist more than 1 times in string using unordered map count.

    Debug:
    i)  In first for loop,
        map will be:
        Char-> y, Count-> 1
        Char-> a, Count-> 3
        Char-> d, Count-> 1
        Char-> m, Count-> 1
        Char-> r, Count-> 2
        Char-> h, Count-> 1
        Char-> s, Count-> 1
        Char-> i, Count-> 2
        Char-> k, Count-> 1
        Char-> p, Count-> 1
        Char-> n, Count-> 1
        Char-> u, Count-> 1

    ii) In second for loop,
        If(i.second > 1),
            If count is more than one, then it will print character and its count.
            Char-> a, Count-> 3
            Char-> r, Count-> 2
            Char-> i, Count-> 2
    
*/

int main()
{
    string s = "dharmikpansuriya";
    unordered_map<char, int> umap;

    for(int i=0; i<s.size(); i++){
        umap[s[i]]++;
    }

    for(auto i:umap){
        if(i.second > 1){
            cout << "Char-> " << i.first << ", "
                 << "Count-> " << i.second << endl;
        }
    }
    return 0;
}
