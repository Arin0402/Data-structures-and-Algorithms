#include <bits/stdc++.h>
using namespace std;

// 1
// recursive solution
class Solution
{
public:
    void helper(char c, string &ans, string &S, int ind, int n)
    {

        if (ind >= n)
            return;

        if (S[ind] != c)
        {
            ans += S[ind];
            helper(S[ind], ans, S, ind + 1, n);
        }
        else
        {
            helper(c, ans, S, ind + 1, n);
        }
    }

    string removeConsecutiveCharacter(string S)
    {
        string ans = "";
        ans += S[0];
        helper(S[0], ans, S, 1, S.size());

        return ans;
    }
};