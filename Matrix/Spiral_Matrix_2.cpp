#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/**
 * generateMatrix : https://leetcode.com/problems/spiral-matrix-ii/
*/

vector<vector<int>> generateMatrix(int n)
{
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    
    int row = n;
    int col = n;   
    int rowStart = 0;
    int rowEnd = row - 1;
    int colStart = 0;
    int colEnd = col - 1;
    int totalElement = row * col;
    int count = 0;
    while (count < totalElement)
    {

        for (int i = colStart; count < totalElement && i <= colEnd; i++)
        {
            matrix.at(rowStart).at(i) = count + 1;
            count++;
        }
        rowStart++;
        for (int i = rowStart; count < totalElement && i <= rowEnd; i++)
        {
            matrix.at(i).at(colEnd) = count + 1;
            count++;
        }
        colEnd--;
        for (int i = colEnd; count < totalElement && i >= colStart; i--)
        {
            matrix.at(rowEnd).at(i) = count + 1;
            count++;
        }
        rowEnd--;
        for (int i = rowEnd; count < totalElement && i >= rowStart; i--)
        {
            matrix.at(i).at(colStart) = count + 1;
            count++;
        }
        colStart++;
    }
    return matrix;
    
}
int main()
{

    vector<vector<int>> ans = generateMatrix(3);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}