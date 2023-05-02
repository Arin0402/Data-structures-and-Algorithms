#include <bits/stdc++.h>
using namespace std;

// binary search to count the number of elements smaller than or equal to the given element.
int countElementsLessThanOrEqualTo(vector<int> &arr, int low, int high, int target)
{

    while (low <= high)
    {

        int mid = low + (high - low) / 2;

        if (arr[mid] <= target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return low;
}
