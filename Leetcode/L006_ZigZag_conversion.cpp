#include <bits/stdc++.h>
using namespace std;

class Solution1
{

public:
    string solve(string s, int numRows)
    {
        if (numRows == 1)
            return s;

        string ans = "";
        for (int r = 0; r < numRows; r++)
        {

            int increment = (numRows - 1) * 2;
            for (int i = r; i < s.size(); i += increment)
            {

                ans += s[i];
                if (r > 0 && r < numRows - 1 && i + increment - 2 * r < s.size())
                {
                    ans += s[i + increment - 2 * r];
                }
            }
        }
        return ans;
    }
};

// Easy solution.
class Solution2
{

public:
    string solve(string s, int numRows)
    {

        int i = 0;
        int n = s.size();

        vector<string> vec(numRows, "");

        while (i < n)
        {

            for (int j = 0; j < numRows && i < n; j++)
            { // vertically downward.
                vec[j].push_back(s[i++]);
            }

            for (int j = numRows - 2; j >= 1 && i < n; j--)
            { // diagonal upward
                vec[j].push_back(s[i++]);
            }
        }

        string zigzag = "";

        for (string v : vec)
            zigzag += v;

        return zigzag;
    }
};

class Solution
{
public:
    string convert(string s, int numRows)
    {

        // Solution1 sol;
        // return sol.solve(s, numRows);

        Solution2 sol;
        return sol.solve(s, numRows);
    }
};