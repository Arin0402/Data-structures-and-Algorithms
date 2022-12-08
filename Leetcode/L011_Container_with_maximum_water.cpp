#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {

        int water = 0;

        int i = 0, j = height.size() - 1;

        while (i < j)
        {

            int h = min(height[i], height[j]);

            water = max(water, (j - i) * h); // calculate maximum for the pointers.

            while (height[i] <= h && i < j)
                i++; // case - 1 1 1 1 10 6 7 9
            while (height[j] <= h && i < j)
                j--;
        }
        return water;
    }
};