#include <bits/stdc++.h>
using namespace std;

// https://www.youtube.com/watch?v=JoF0Z7nVSrA
class Solution
{
public:
    vector<int> search(string pat, string txt)
    {
        // create lps;
        int n = pat.size();
        int j = 0;
        int i = 1;

        vector<int> lps(n, 0);

        while (j <= i && i < n)
        {

            if (pat[i] == pat[j])
            {
                lps[i] = j + 1;
                i++;
                j++;
            }
            else if (j == 0)
            {
                lps[i] = 0;
                i++;
            }
            else
                j = lps[j - 1];
        }

        // to store the answer
        vector<int> ans;

        i = 0;
        j = 0;

        while (i < txt.size())
        {

            if (txt[i] == pat[j])
            {
                i++;
                j++;
            }
            else if (j == 0)
            {
                i++;
            }
            else
                j = lps[j - 1];

            if (j == pat.size())
            {
                ans.push_back(i - pat.size() + 1);
                j = lps[j - 1];
            }
        }

        return ans;
    }
};