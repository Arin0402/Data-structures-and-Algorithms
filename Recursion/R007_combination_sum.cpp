// https://leetcode.com/problems/combination-sum/

#include <bits/stdc++.h>
using namespace std;

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