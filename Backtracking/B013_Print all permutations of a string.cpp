#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void permutations_approach_1(vector<int> &ds, vector<int> &indexes, vector<int> &nums, vector<vector<int>> &ans, int n)
    {

        // got the permutation.
        if (ds.size() == n)
        {
            ans.push_back(ds);
            return;
        }

        for (int i = 0; i < n; i++)
        {

            if (indexes[i] == 1)
                continue; // if the index is picked , then skip it.

            ds.push_back(nums[i]);
            indexes[i] = 1;

            permutations_approach_1(ds, indexes, nums, ans, n);

            indexes[i] = 0;
            ds.pop_back();
        }

        // TC  - n! * n ( n! for permutations and n for loop );
        // SC  -  O(n) + O(n) (one for ds and one for indexes list)
    }

    void swap(int *a, int *b)
    {
        int t = *a;
        *a = *b;
        *b = t;
    }
    void permutaions_approach_2(int index, vector<int> &nums, vector<vector<int>> &ans, int n)
    {

        if (index >= n)
        {
            ans.push_back(nums);
            return;
        }

        for (int i = index; i < n; i++)
        {

            swap(&nums[index], &nums[i]);
            permutaions_approach_2(index + 1, nums, ans, n);
            swap(&nums[i], &nums[index]);
        }
        // TC  - n! * n ( n! for permutations and n for loop );
    }
    vector<vector<int>> permute(vector<int> &nums)
    {

        vector<vector<int>> ans;
        vector<int> ds;
        vector<int> indexes(nums.size(), 0);

        permutations_approach_1(ds, indexes, nums, ans, nums.size());

        return ans;
    }
};