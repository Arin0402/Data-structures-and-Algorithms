#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/

// same as Buy and sell stocks 2 (D037). just a minor change as we have to pay transaction fee for each buying.
// we are assuming that transaction is completed after selling, so deduce the transaction fee.

// 1

class Solution {
public:

    int helper(int ind, int canBuy, vector<int>& prices, int n, int fee, vector<vector<int>> &dp){

        if(ind == n) return 0;
        if(dp[ind][canBuy] != -1) return dp[ind][canBuy];

        int profit = 0;

        // buying
        if(canBuy == 1){

            int choice1 = -prices[ind] + helper(ind + 1, 0, prices, n, fee, dp);
            int choice2 = 0 + helper(ind + 1, 1, prices, n, fee, dp);

            profit = max(choice1, choice2);            
        }
        // selling
        else {

            // deduce the transaction fee.
            int choice1 = prices[ind] - fee + helper(ind + 1, 1, prices, n, fee, dp);
            int choice2 = 0 + helper(ind + 1, 0, prices, n, fee, dp);

            profit = max(choice1, choice2);
        }
        
        return dp[ind][canBuy] = profit;
    }

    int maxProfit(vector<int>& prices, int fee) {
        
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1)); 

        return helper(0, 1, prices, n, fee, dp);

    }
};
