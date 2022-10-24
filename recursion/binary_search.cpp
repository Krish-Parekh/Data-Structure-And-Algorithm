#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int binarySearch(int arr[], int start, int end, int target)
{
    if (start > end)
    {
        return -1;
    }
    int mid = (start + end) / 2;
    if (arr[mid] == target)
    {
        return mid;
    }
    else if (arr[mid] < target)
    {
        return binarySearch(arr, mid + 1, end, target);
    }
    else if (arr[mid] > target)
    {
        return binarySearch(arr, start, mid - 1, target);
    }
    else{
        return -1;
    }
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int len = sizeof(arr) / sizeof(arr[0]);
    int index = binarySearch(arr, 0, len, 5);
    cout << "Target is present at index : " << index;
}