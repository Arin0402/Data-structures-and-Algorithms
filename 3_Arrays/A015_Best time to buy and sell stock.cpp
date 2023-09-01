#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

// 1
// Compare each element with others, get the max profit.
// O(n^2);

// 2
// O(n)
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {

        int minPrice = prices[0]; // minimum price.
        int profit = 0;           // maximum profit.

        for (int i = 1; i < prices.size(); i++)
        {

            // got the lesser price.
            if (prices[i] < minPrice)
                minPrice = prices[i];

            // price is greater , so calculate the profit.
            else
            {
                profit = max(profit, prices[i] - minPrice);
            }
        }

        return profit;
    }
};