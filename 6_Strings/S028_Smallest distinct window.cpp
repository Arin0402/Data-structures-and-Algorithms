#include <bits/stdc++.h>
using namespace std;

// 1
// naive
// generate all the substrings and check.
// O(n^2)

// 2
// sliding window technique.
// Expanding and shrinking window size technique.
// TC- O(N)
// Sc- O(N)

class Solution
{
public:
    int findSubString(string s)
    {
        int n = s.size();

        // find the number of distinct elements.
        unordered_set<char> st;
        for (int i = 0; i < n; i++)
            st.insert(s[i]);

        int distinctEle = st.size();

        unordered_map<char, int> mp;

        int i = 0;
        int j = 1;

        mp[s[0]] = 1; // first character.
        int cnt = 1;  // number of distinct elements in a window.

        int mini = INT_MAX;

        while (i <= j && j < n)
        {

            // distinct elements in current window are less than total distinct elements.
            if (cnt < distinctEle)
            {

                if (mp[s[j]] == 0)
                    cnt++; // new element
                mp[s[j]]++;
                j++; // increase window size.
            }
            // shrink the window.
            else if (cnt == distinctEle)
            {

                mini = min(mini, j - i); // update.
                if (mp[s[i]] == 1)
                    cnt--; // only one is left, so count would be decreased.
                mp[s[i]]--;
                i++; // shrink window.
            }
        }

        // try for last window.
        while (cnt == distinctEle)
        {

            mini = min(mini, j - i);
            if (mp[s[i]] == 1)
                cnt--;
            mp[s[i]]--;
            i++;
        }

        return mini;
    }
};