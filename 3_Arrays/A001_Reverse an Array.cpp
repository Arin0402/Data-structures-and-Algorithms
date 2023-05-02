#include <iostream>
using namespace std;

// O(n)
void reverse(int arr[], int start, int end)
{

    // return when the end pointer is greater the starting pointer.
    if (start < end)
        return;

    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;

    reverse(arr, start + 1, end - 1);
}
