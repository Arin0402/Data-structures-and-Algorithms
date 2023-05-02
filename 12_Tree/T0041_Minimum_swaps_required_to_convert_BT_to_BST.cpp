// https://practice.geeksforgeeks.org/problems/minimum-swap-required-to-convert-binary-tree-to-binary-search-tree/0?page=1&sortBy=newest&query=page1sortBynewest
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // this will give the inorder traversal of the tree.
    // It is different as we are working with indexes in it.
    void inorder(vector<int> &nums, vector<int> &v, int n, int index)
    {

        if (index >= n)
            return;

        inorder(nums, v, n, 2 * index + 1);
        v.push_back(nums[index]);
        inorder(nums, v, n, 2 * index + 2);
    }

    // pass the inorder traversal in this to get the minimum number of swaps;
    // https://www.youtube.com/watch?v=-2_c4lG7k_M
    int minSwapsHelper(vector<int> &nums)
    {
        int n = nums.size();

        vector<pair<int, int>> arr(n);

        // create a vector containing index of the elements also.
        for (int i = 0; i < n; i++)
        {
            arr[i] = {nums[i], i};
        }

        sort(arr.begin(), arr.end());

        int ans = 0;

        for (int i = 0; i < n; i++)
        {

            if (arr[i].second == i)
                continue;
            else
            {

                swap(arr[i], arr[arr[i].second]);
                ans++;
                i--;
            }
        }

        return ans;
    }

    int minSwaps(vector<int> &nums, int n)
    {

        vector<int> v;
        inorder(nums, v, n, 0);

        return minSwapsHelper(v);
    }
};