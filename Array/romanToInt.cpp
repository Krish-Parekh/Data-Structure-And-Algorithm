/*************************************************************************************** 
* 
* Roman to Integer
*
* Love Babber Sheet (Que-1).
* Link: https://leetcode.com/problems/roman-to-integer/
*
* Input: s = "III"
* Output: 3
*          
***************************************************************************************/

/*
    1. Brute-Force-Approach        
*/

/*
#include <iostream>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        long long int count = 0;
        
        for(int i=0; i<s.length(); i++){
            
            if(s[i] == 'I'){
                if(s[i+1] == 'V'){
                    count += 4;
                    i++;
                }
                else if(s[i+1] == 'X'){
                    count += 9;
                    i++;
                }
                else{
                    count += 1;
                }
            }
            
            else if(s[i] == 'V'){
                count += 5;
            }
            
            else if(s[i] == 'X'){
                if(s[i+1] == 'L'){
                    count += 40;
                    i++;
                }
                else if(s[i+1] == 'C'){
                    count += 90;
                    i++;
                }
                else{
                    count += 10;
                }
            }
            
            else if(s[i] == 'L'){
                count += 50;
            }
            
            else if(s[i] == 'C'){
                if(s[i+1] == 'D'){
                    count += 400;
                    i++;
                }
                else if(s[i+1] == 'M'){
                    count += 900;
                    i++;
                }
                else{
                    count += 100;
                }
            }  
            else if(s[i] == 'D'){
                count += 500;
            }
            else if(s[i] == 'M'){
                count += 1000;
            }
        }
        return count;
    }
};
*/

/*
    2. Optimized Approach (IN TERMS OF CODE READABILITY))  
*/

#include <iostream>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        long long int count = 0;
        
        for(int i=0; i<s.length(); i++){
            int value;
            switch(s[i]){
                case 'I':
                    if(s[i+1] == 'V' || s[i+1] == 'X'){
                        count -= 1;
                    }
                    else{
                        count += 1;
                    }
                    break;
                case 'V':
                    count += 5;
                    break;
                case 'X':
                    if(s[i+1] == 'L' || s[i+1] == 'C'){
                        count -= 10;
                    }
                    else{
                        count += 10;
                    }
                    break;
                case 'L':
                    count += 50;
                    break;
                case 'C':
                    if(s[i+1] == 'D' || s[i+1] == 'M'){
                        count -= 100;
                    }
                    else{
                        count += 100;
                    }
                    break;
                case 'D':
                    count += 500;
                    break;
                case 'M':
                    count += 1000;
                    break;
            }           
        }
        
        return count;
    }
};
