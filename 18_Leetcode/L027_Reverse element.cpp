#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {

        int ptr = 0; // points to the occurence of val.

        for (int i = 0; i < nums.size(); i++)
        {

            if (nums[i] != val)
            {

                nums[ptr] = nums[i];
                ptr++;
            }
        }

        return ptr;
    }
};