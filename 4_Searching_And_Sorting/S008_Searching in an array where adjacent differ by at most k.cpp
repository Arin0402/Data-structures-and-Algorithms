#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/searching-in-an-array-where-adjacent-differ-by-at-most-k0456/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
// https://www.youtube.com/watch?v=KtrAWsfyBaA
// 1
// linear traversal.

// 2

int search(int arr[], int n, int x, int k)
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
        // array element and x divided by k
        // We use max here to make sure that i
        // moves at-least one step ahead.
        i = i + max(1, abs(arr[i] - x) / k);
    }

    return -1;
}