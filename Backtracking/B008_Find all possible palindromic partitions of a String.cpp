#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {

        int n = s.size();

        int l = 0;
        int r = n - 1;

        while (l <= r)
        {

            if (s[l] != s[r])
                return false;
            l++;
            r--;
        }

        return true;
    }

    void helper(int pos, string &s, vector<string> &temp, vector<vector<string>> &ans, int n)
    {

        if (pos >= n)
        {

            ans.push_back(temp);
            return;
        }

        for (int i = pos; i < n; i++)
        {

            string st = s.substr(pos, i - pos + 1);

            if (isPalindrome(st))
            {

                temp.push_back(st);
                helper(i + 1, s, temp, ans, n);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> allPalindromicPerms(string S)
    {

        vector<vector<string>> ans;
        vector<string> temp;

        int n = S.size();

        helper(0, S, temp, ans, n);

        return ans;
    }
};