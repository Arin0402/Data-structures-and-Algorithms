#include <bits/stdc++.h>
using namespace std;

// 1
// naive
// search linearly

// 2
// use binary search
class Solution
{
public:
    int search(vector<int> &arr, int target)
    {

        int n = arr.size();

        int low = 0;
        int high = n - 1;

        while (low <= high)
        {

            int mid = low + (high - low) / 2;

            if (arr[mid] == target)
                return mid;

            // left part is sorted
            else if (arr[low] <= arr[mid])
            {

                // target lies in this range.
                if (arr[low] <= target && target < arr[mid])
                {
                    high = mid - 1;
                }
                // target does not lie in this range. go right.

                else
                    low = mid + 1;
            }
            // right part is sorted
            else
            {

                // target lies in that range.
                if (arr[high] >= target && target > arr[mid])
                {
                    low = mid + 1;
                }
                // target does not lies in this range, go left.
                else
                    high = mid - 1;
            }
        }

        return -1;
    }
};