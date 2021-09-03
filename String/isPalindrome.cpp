/*************************************************************************************** 
* 
* Palindrome String
* Given a string S, check if it is palindrome or not.
*
* Love Babber Sheet (Que-2).
* Link: https://practice.geeksforgeeks.org/problems/palindrome-string0817/1
*
* Input:  string s = abba
* Output: 1
*
* Input:  string s = abc
* Output: 0
*          
***************************************************************************************/

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

/*

1.  Brute Force Solution 
    Time Complexity  : O(N)
    Space Complexity : O(N)

    Explanation:
    Palindrome String: A string is said to be palindrome if it reads the same backward as forward.

    1. First of all, we need to copy given string to another string.
    2. Then, we will reverse entire copied string.
    3. Then, we will check whether given string and reversed string is same or not.
    4. If both the string is same, then string is palindrome, hence we will return 1.
       Else, String is not palindrom, hence we will return 0.

*/

class Solution{
public:	
	
	int isPlaindrome(string S)
	{
	    string pString = S;
	    int i=0, j=(pString.size()-1);
        while(i<j){
            int temp = pString[j];
            pString[j] = pString[i];
            pString[i] = temp;
            i++;
            j--;
        }

        if(S == pString){
            return 1;
        }
        return 0;
	}
};


/*

2.  Optimized Solution 
    Time Complexity  : O(N)
    Space Complexity : O(1)

    Explanation:
    Palindrome String: A string is said to be palindrome if it reads the same backward as forward.

    1. We will use two pointers. 
       i will track starting of string.
       j will track ending of string.
    2. We will compare elements available at i and j index.
    3. By any chance, if both the elements are not same, then we will return 0.
    4. After Comparing elements, we will increase i pointer and decrease j pointer.
    5. If loop gets over without returning 0, then string is palindrome and we will return 1.

*/


class Solution{
public:	

    int isPlaindrome(string S){

        int i=0, j=(S.size()-1);

        while(i<j){
            if(S[i++] != S[j--]){
                return 0;
            }
        }
        return 1;
    }
};