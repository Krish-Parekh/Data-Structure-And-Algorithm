#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    vector<int> temp;
    int row = matrix.size();
    int col = matrix[0].size();
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
            temp.push_back(matrix[rowStart][i]);
            count++;
        }
        rowStart++;
        for (int i = rowStart; count < totalElement && i <= rowEnd; i++)
        {
            temp.push_back(matrix[i][colEnd]);
            count++;
        }
        colEnd--;
        for (int i = colEnd; count < totalElement && i >= colStart; i--)
        {
            temp.push_back(matrix[rowEnd][i]);
            count++;
        }
        rowEnd--;
        for (int i = rowEnd; count < totalElement && i >= rowStart; i--)
        {
            temp.push_back(matrix[i][colStart]);
            count++;
        }
        colStart++;
    }
    return temp;
}
int main()
{

    vector<vector<int>> temp = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
    };
    vector<int> ans = spiralOrder(temp);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}