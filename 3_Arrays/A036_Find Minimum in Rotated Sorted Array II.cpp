#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/description/

class Solution
{
public:
    int findMin(vector<int> &nums)
    {

        int low = 0;
        int high = nums.size() - 1;

        while (low < high)
        {

            int mid = low + (high - low) / 2;

            if (nums[mid] < nums[high])
                high = mid;
            else if (nums[mid] > nums[high])
                low = mid + 1;
            else
                high--;
        }

        return nums[low];
    }
};