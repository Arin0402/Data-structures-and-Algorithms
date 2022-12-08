#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {

        int n = nums.size();

        sort(nums.begin(), nums.end());

        int result = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < n - 2; i++)
        {

            if (i > 0 && nums[i] == nums[i - 1])
                continue; // skip repeated elements

            int start = i + 1;
            int end = n - 1;

            while (start < end)
            {

                int sum = nums[i] + nums[start] + nums[end];

                if (sum == target)
                    return target;
                else if (sum > target)
                {

                    while (start < end && nums[end] == nums[end - 1])
                        end--; // skip repeated elements
                    end--;
                }
                else
                {
                    while (start < end && nums[start] == nums[start - 1])
                        start++; // skip repeated elements
                    start++;
                }

                if (abs(sum - target) < abs(result - target))
                    result = sum; // compare the current sum and result.
            }
        }

        return result;
    }
};