#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void generate(vector<string> &ans, string s, int open, int close, int n)
    {

        if (open == n && close == n)
        { // number of open '(' is equal to  ')' ;
            ans.push_back(s);
            return;
        }

        if (open < n)
        {
            generate(ans, s + '(', open + 1, close, n);
        }

        if (close < open)
        {

            generate(ans, s + ')', open, close + 1, n);
        }
    }

    vector<string> generateParenthesis(int n)
    {

        vector<string> ans;

        generate(ans, "", 0, 0, n);
        return ans;
    }
};