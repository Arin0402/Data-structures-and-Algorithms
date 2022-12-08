#include <bits/stdc++.h>
using namespace std;

// 1
// TC - O(2^N * logn) (logn beacuse of set )
// SC - O(N^2)

class Solution
{
public:
    void helper(int pos, int tempSum, int n, int B, vector<int> &temp, vector<vector<int>> &ans, vector<int> &A)
    {

        if (tempSum > B)
            return; // sum > target

        if (tempSum == B)
        {
            ans.push_back(temp);
            return;
        }

        if (pos >= n)
            return; // out of bound.

        // select same index.
        temp.push_back(A[pos]);
        helper(pos, tempSum + A[pos], n, B, temp, ans, A);

        // next index.
        temp.pop_back();
        helper(pos + 1, tempSum, n, B, temp, ans, A);
    }

    vector<vector<int>> combinationSum(vector<int> &A, int B)
    {

        // remove duplicates.
        set<int> st;
        for (auto ele : A)
            st.insert(ele);

        // clear the vector.
        A.clear();

        // vector without duplicates.
        for (auto itr = st.begin(); itr != st.end(); itr++)
        {
            A.push_back(*itr);
        }

        vector<vector<int>> ans;
        vector<int> temp;
        int n = A.size();

        helper(0, 0, n, B, temp, ans, A);

        return ans;
    }
};