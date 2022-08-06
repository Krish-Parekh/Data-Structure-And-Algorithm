#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
leetCode : https://leetcode.com/problems/flipping-an-image/
*/

vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
    for(int i = 0 ; i < image.size() ; i++)
    {
        for(int j = 0 ; j < image[i].size() ; j++)
        {
            image[i][j] ^= 1;
        }
        reverse(image[i].begin(), image[i].end());
    }
    return image;
}