#include <bits/stdc++.h>
using namespace std;

// 1
// linear travese.

// 2
// skip the difference betweeen the element and the target.

int search(int arr[], int n, int x)
{
    // Traverse the given array starting from
    // leftmost element
    int i = 0;

    while (i < n)
    {
        // If x is found at index i
        if (arr[i] == x)
            return i;

        // Jump the difference between current
        // array element and x
        i = i + abs(arr[i] - x);
    }

    return -1;
}