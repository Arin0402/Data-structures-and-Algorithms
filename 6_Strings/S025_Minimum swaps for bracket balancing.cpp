#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/minimum-swaps-for-bracket-balancing2704/1

// 1
// TC -O(N)
// Sc -O(N)

class Solution
{
public:
    int minimumNumberOfSwaps(string S)
    {

        vector<int> openIndexes;
        int n = S.size();

        // indexes at which open brackets are present.
        for (int i = 0; i < n; i++)
        {

            if (S[i] == '[')
                openIndexes.push_back(i);
        }

        int ans = 0;
        int ind = 0; // iterator of index vector.

        int countOpen = 0; // count of the number of open bracket.

        for (int i = 0; i < n; i++)
        {

            if (S[i] == ']')
            {

                countOpen--; // decrease the count of open bracket (pair)

                if (countOpen < 0)
                { // if there was no open bracket

                    // this much steps would be require to swap the close bracket with first bracket occurence.
                    ans += openIndexes[ind] - i;

                    swap(S[i], S[openIndexes[ind]]); // swap them.

                    ind++;         // increase the iterator for the open bracket as the previous one has been used.
                    countOpen = 1; // after swap , i will be on open bracket so increase counter.
                }
            }
            else
            {
                countOpen++;
                ind++; // increase the iterator for the open bracket as it will not be used again.
            }
        }

        return ans;
    }
};

// 2
// O(1) SC solution is a bit complex.