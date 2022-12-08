#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void helper(int r, vector<string> &temp, vector<vector<string>> &list, vector<vector<string>> &ans, int n)
    {

        int m = list[r].size(); // column size of current row.

        // reached last row, so return.
        if (r == n)
        {
            ans.push_back(temp);
            return;
        }

        // for every row, travel form 0 to m.
        for (int i = 0; i < m; i++)
        {

            temp.push_back(list[r][i]);

            helper(r + 1, temp, list, ans, n);

            temp.pop_back();
        }
    }

    vector<vector<string>> sentences(vector<vector<string>> &list)
    {

        vector<vector<string>> ans;

        // to store the strings for one iteration.
        vector<string> temp;

        int n = list.size(); // rows

        // start from frist row.
        helper(0, temp, list, ans, n);

        return ans;
    }
};
