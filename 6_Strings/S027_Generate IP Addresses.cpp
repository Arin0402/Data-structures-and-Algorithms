#include <bits/stdc++.h>
using namespace std;

// 1
// O(N^3)
// using for loops.


// can be done using recursion but complex handling indices.
// dp solution is complicated.

class Solution
{
public:
    bool check(string &s)
    {

        int n = s.size();

        if (n <= 0 || n > 3)
            return false; // size greater than 3 or less than 0.
        if (n > 1 && s[0] == '0')
            return false; // avoid prefix zero

        int val = stoi(s);
        if (val > 255 || val < 0)
            return false; // check for value.

        return true;
    }

    string generate(int i, int j, int k, int n, string s)
    {

        // individual parts
        string s1 = s.substr(0, i + 1);
        string s2 = s.substr(i + 1, j - i);
        string s3 = s.substr(j + 1, k - j);
        string s4 = s.substr(k + 1, n - k - 1);

        // check if the parts are valid.
        if (check(s1) && check(s2) && check(s3) && check(s4))
            return s1 + '.' + s2 + '.' + s3 + '.' + s4;

        return "";
    }

    vector<string> genIp(string &s)
    {

        vector<string> ans;

        int n = s.size();

        for (int i = 0; i < n - 3; i++)
        {

            for (int j = i + 1; j < n - 2; j++)
            {

                for (int k = j + 1; k < n - 1; k++)
                {

                    string st = generate(i, j, k, n, s);

                    if (st != "")
                        ans.push_back(st);
                }
            }
        }

        return ans;
    }
};