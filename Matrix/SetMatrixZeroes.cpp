#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void setZeroes(vector<vector<int>> &matrix)
{
    int H = matrix.size();
    int W = matrix[0].size();
    vector<bool> row_zeros(H);
    vector<bool> col_zeros(W);

    for(int row = 0; row < H; row++)
    {
        for(int col = 0; col < W; col++)
        {
            if(matrix[row][col] == 0)
            {
                row_zeros[row] = true;
                col_zeros[col] = true;
            }
        }
    }

    for(int row = 0; row < H; row++)
    {
        for(int col = 0 ; col < W; col++)
        {
            if(row_zeros[row] || col_zeros[col])
            {
                matrix[row][col] = 0;
            }
        }
    }
}
int main()
{
    vector<vector<int>> temp = {
        {1,1,1},
        {1,0,1},
        {1,1,1}
    };

    setZeroes(temp);

    for (int i = 0; i < temp.size(); i++)
    {
        for (int j = 0; j < temp[i].size(); j++)
        {
            cout << temp[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}