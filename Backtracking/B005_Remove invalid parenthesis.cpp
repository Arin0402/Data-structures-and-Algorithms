#include <bits/stdc++.h>
using namespace std;

// O(2^n)
// recursion

// this code is getting accepted as well as giving TLE also.
class Solution
{
public:
    int minimumToRemove(string s)
    {

        int rightCnt = 0;
        int leftCnt = 0;

        for (int i = 0; i < s.size(); i++)
        {

            if (s[i] == '(')
            {
                leftCnt++;
            }
            else if (s[i] == ')')
            {
                if (leftCnt == 0)
                    rightCnt++;
                else
                    leftCnt--;
            }
        }

        return rightCnt + leftCnt;
    }

    void helper(int pos, string temp, int removed, int leftCnt, int rightCnt, int n, int toRemove, string &s, vector<string> &ans, unordered_map<string, int> &mp)
    {

        if (mp[temp] > 0)
            return; // string is already present in the ans.

        // number of brackets removed is greater than the minimum number of brackets to be removed.
        if (removed > toRemove)
            return;

        // base case.
        if (pos == n)
        {

            // brackets are balanced and size is equal to n - minimum to be removed.
            if (leftCnt == 0 && rightCnt == 0 && temp.size() == n - toRemove)
            {

                mp[temp]++; // update.
                ans.push_back(temp);
            }

            return;
        }

        // if rightCnt increases then return.
        if (rightCnt > 0)
            return;

        char c = s[pos];

        // pick.
        if (c == '(' || c == ')')
        {
            if (c == '(')
            {

                // increase leftCnt.
                helper(pos + 1, temp + c, removed, leftCnt + 1, rightCnt, n, toRemove, s, ans, mp);
            }
            else if (c == ')')
            {

                // decrease leftCnt.
                if (leftCnt > 0)
                    helper(pos + 1, temp + c, removed, leftCnt - 1, rightCnt, n, toRemove, s, ans, mp);

                // increase rightCnt.
                else
                    helper(pos + 1, temp + c, removed, leftCnt, rightCnt + 1, n, toRemove, s, ans, mp);
                ;
            }

            // not pick
            // increase removed cnt.
            helper(pos + 1, temp, removed + 1, leftCnt, rightCnt, n, toRemove, s, ans, mp);
        }

        // alphabet
        else
        {

            // pick and go to next index.
            helper(pos + 1, temp + c, removed, leftCnt, rightCnt, n, toRemove, s, ans, mp);
        }
    }

    vector<string> removeInvalidParentheses(string s)
    {

        int n = s.size();
        vector<string> ans;

        // to avoid duplicate strings in the answer.
        unordered_map<string, int> mp;

        // minimum number of parenthesis required to be removed.
        int toRemove = minimumToRemove(s);

        // if the string is already valid then return.
        if (toRemove == 0)
        {
            ans.push_back(s);
            return ans;
        }

        int leftCnt = 0;  // count of '(' till now.
        int rightCnt = 0; // count of ')' till now.
        int removed = 0;  // number of brackets removed till now (not pick case).

        helper(0, "", removed, leftCnt, rightCnt, n, toRemove, s, ans, mp);

        return ans;
    }
};