#include <bits/stdc++.h>
using namespace std;

// NOTE - This problem depicts how binary search can be used to count the number of elemnets
// smaller than or equal to the given element.

// 1
// extra space , convert into array and then find median.

// 2
// O(32*N*logm)
// using binary search. 
// https://www.youtube.com/watch?v=63fPPOdIr2c
class Solution
{
public:
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

    int median(vector<vector<int>> &matrix, int r, int c)
    {

        int low = 1;
        int high = 1e9;

        while (low <= high)
        {

            int mid = low + (high - low) / 2;

            int cnt = 0;

            for (int i = 0; i < r; i++)
            {

                cnt += countElementsLessThanOrEqualTo(matrix[i], 0, c - 1, mid);
            }

            if (cnt <= (r * c) / 2)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return low;
    }
};