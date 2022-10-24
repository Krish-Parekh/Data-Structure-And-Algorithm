#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool checkSorted(int arr[], int index, int arrLen)
{
    if (index == arrLen - 1)
    {
        return true;
    }
    return arr[index] < arr[index + 1] && checkSorted(arr, index + 1, arrLen);
}

int main()
{
    int arr[] = {1, 2, 3, 14, 5};
    int arrLen = sizeof(arr) / sizeof(arr[0]);
    bool ans = checkSorted(arr, 0, arrLen);
    if (ans)
    {
        cout << "Array is sorted" << endl;
    }
    else
    {
        cout << "Array is not sorted" << endl;
    }
}