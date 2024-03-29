#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

// 1
// O(N)
// O(1)
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int maxProfit = 0, n = prices.size();
        int start = 0, end = 1;
        if (n == 1)
            return maxProfit;

        while (end < n)
        {
            if (prices[start] < prices[end])
                maxProfit = max(maxProfit, prices[end] - prices[start]);
            else
                start = end;
            end++;
        }
        return maxProfit;
    }
};

// OR

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();
        int mini = prices[0];
        int profit = 0;

        for(int i = 1; i < n; i++){            
            profit = max(profit, prices[i] - mini);
            mini = min(mini, prices[i]);
        }   
        return profit;
    }
};

