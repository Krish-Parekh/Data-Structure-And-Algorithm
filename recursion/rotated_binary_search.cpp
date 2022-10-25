#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int rotatedBinarySearch(int arr[], int start, int end, int target)
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

    // First half is sorted
    if (arr[start] <= arr[mid])
    {
        // check if our target element lies in sorted range
        if (target >= arr[start] && target <= arr[mid])
        {
            return rotatedBinarySearch(arr, start, mid - 1, target);
        }
        else
        {
            // if the target element is out of range then we need to move our start pointer
            return rotatedBinarySearch(arr, mid + 1, end, target);
        }
    }
    // checking in the unsorted second half
    if (target >= arr[mid] && target <= arr[end])
    {
        return rotatedBinarySearch(arr, mid + 1, end, target);
    }
    return rotatedBinarySearch(arr, start, mid - 1, target);
    
}
int main()
{
    int arr[] = {5, 4, 1, 2, 3};
    int len = sizeof(arr) / sizeof(arr[0]);
    int index = rotatedBinarySearch(arr, 0, len, 5);

    cout << "Target is present at index : " << index;
}