#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> pad = { // pad.
        "", "", "abc", "def", "ghi", "jkl",
        "mno", "pqrs", "tuv", "wxyz"};

    // Dry run.
    vector<string> letterCombinations(string digits)
    {

        if (digits.empty())
            return {};

        vector<string> result;
        result.push_back("");

        for (auto d : digits)
        {

            vector<string> tmp;
            for (auto s : pad[d - '0'])
            {

                for (auto t : result)
                {

                    tmp.push_back(t + s);
                }
            }

            result = tmp;
        }

        return result;
    }
};