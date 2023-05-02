#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/single-number-ii/description/
// https:/  /www.youtube.com/watch?v=cOFAmaMBVps

// 1
// TC - O(32*n)

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {

        int ans = 0;

        for (int i = 0; i < 32; i++)
        {

            // count of set bits;
            int count = 0;

            for (auto ele : nums)
            {
                if (ele & (1 << i))
                {
                    count++;
                }
            }

            if (count % 3 == 1)
                ans += (1 << i);
        }

        return ans;
    }
};
