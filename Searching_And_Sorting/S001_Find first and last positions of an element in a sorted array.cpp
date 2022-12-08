#include <bits/stdc++.h>
using namespace std;

// 1
// naive
// run a for loop and check for the first and last index.
// O(n);

// 2
// use Binary search
// use binary search for finding the first occurence in the left array.
// use binary search for finding the last occurence in the right array.

// find first occurence
int findLeft(int arr[], int low, int high, int x)
{

    int res = -1;

    while (low <= high)
    {

        int mid = low + (high - low) / 2;

        // go to left even if found the element as there can be more elements.
        if (arr[mid] == x)
        {
            res = mid;
            high = mid - 1;
        }
        else if (arr[mid] > x)
            high = mid - 1;
        else
            low = mid + 1;
    }

    return res;
}

// find last occurence
int findRight(int arr[], int low, int high, int x)
{

    int res = -1;

    while (low <= high)
    {

        int mid = low + (high - low) / 2;

        if (arr[mid] == x)
        {
            res = mid;
            low = mid + 1;
        }
        else if (arr[mid] > x)
            high = mid - 1;
        else
            low = mid + 1;
    }

    return res;
}

vector<int> find(int arr[], int n, int x)
{

    vector<int> ans(2, -1);

    ans[0] = findLeft(arr, 0, n - 1, x);
    ans[1] = findRight(arr, 0, n - 1, x);

    return ans;
}

// 3
// using inbuilt methods
void findFirstAndLast(int arr[], int n, int x)
{
    int first, last;
    // to store first occurrence
    first = lower_bound(arr, arr + n, x) - arr; // returns the pointer to less than or equal to x.

    // to store last occurrence
    last = upper_bound(arr, arr + n, x) - arr - 1; // returns the pointer to element just greater than x.

    // not found.
    if (first == n)
    {
        first = -1;
        last = -1;
    }
}
