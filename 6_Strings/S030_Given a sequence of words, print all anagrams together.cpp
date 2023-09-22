#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/print-anagrams-together/1

// 1
// using map
// TC - O(n*mlogm) (m - avaearge length of words.)
class Solution
{
public:
    vector<vector<string>> Anagrams(vector<string> &string_list)
    {

        int n = string_list.size();

        // map to strore the frequencies.
        map<string, vector<string>> mp;

        for (int i = 0; i < n; i++)
        {

            string s = string_list[i];

            // sort the individual string.  O(mlogm)
            sort(s.begin(), s.end());

            // store the original string for this key.
            mp[s].push_back(string_list[i]);
        }

        vector<vector<string>> ans;

        for (auto itr = mp.begin(); itr != mp.end(); itr++)
        {
            ans.push_back(itr->second);
        }

        return ans;
    }
};

// 2
// O(m*n)
// using vector as a key in map. this reduces the sorting part.
class Solution
{
public:
    vector<vector<string>> Anagrams(vector<string> &string_list)
    {

        int n = string_list.size();

        // map to store the frequencies.
        map<vector<int>, vector<string>> mp;

        for (int i = 0; i < n; i++)
        {

            vector<int> freq(26, 0);

            for (int j = 0; j < string_list[i].size(); j++)
            {

                char c = string_list[i][j];

                freq[c - 'a']++;
            }

            mp[freq].push_back(string_list[i]);
        }

        vector<vector<string>> ans;

        for (auto itr = mp.begin(); itr != mp.end(); itr++)
        {
            ans.push_back(itr->second);
        }

        return ans;
    }
};
