// https://www.geeksforgeeks.org/problems/shop-in-candy-store1145/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K)
    {

        sort(candies, candies + N);

        vector<int> ans;

        int minCost = 0;
        int maxCost = 0;

        int buy = 0;
        int free = N - 1;

        while (buy <= free)
        {

            minCost += candies[buy];
            buy++;
            free -= K;
        }

        buy = N - 1;
        free = 0;

        while (buy >= free)
        {
            maxCost += candies[buy];
            buy--;
            free += K;
        }

        ans.push_back(minCost);
        ans.push_back(maxCost);

        return ans;
    }
};
