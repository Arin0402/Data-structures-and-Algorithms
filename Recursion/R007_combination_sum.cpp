// https://leetcode.com/problems/combination-sum/

#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(2^t * k) where t is the target, k is the average length

// Reason: Assume if you were not allowed to pick a single element multiple times, every element will have a couple of options: pick or not pick which is 2^n different recursion calls, also assuming that the average length of every combination generated is k. (to put length k data structure into another data structure)
// Why not (2^n) but (2^t) (where n is the size of an array)?
// Assume that there is 1 and the target you want to reach is 10 so 10 times you can “pick or not pick” an element.

class Solution
{
public:
    void allthecombinations(int index, vector<int> &ds, vector<int> &candidates, int target, int sum, int size, vector<vector<int>> &ans)
    {

        // sum excedes the target but index remains less than size of candidates;
        // example - 2,2,2,2 --ds
        //         - 0 --index
        if (sum > target)
            return;

        if (index >= size)
        {

            if (sum == target)
            {
                ans.push_back(ds);
            }
            return;
        }

        ds.push_back(candidates[index]);
        sum += candidates[index];
        allthecombinations(index, ds, candidates, target, sum, size, ans);

        ds.pop_back();
        sum -= candidates[index];
        allthecombinations(index + 1, ds, candidates, target, sum, size, ans);
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {

        vector<vector<int>> ans;
        vector<int> ds;
        int size = candidates.size();

        allthecombinations(0, ds, candidates, target, 0, size, ans);

        return ans;
    }
};