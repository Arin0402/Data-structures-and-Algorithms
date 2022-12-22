#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/

// 1
// memo
// O(n*2)
// O(n*2) + O(n)
class Solution {
public:

    int helper(int ind, int canBuy, vector<int>& prices, int n, vector<vector<int>> &dp){

        if(ind == n) return 0;
        if(dp[ind][canBuy] != -1) return dp[ind][canBuy];

        int profit = 0;

        // buying
        if(canBuy == 1){

            int choice1 = -prices[ind] + helper(ind + 1, 0, prices, n, dp);
            int choice2 = 0 + helper(ind + 1, 1, prices, n, dp);

            profit = max(choice1, choice2);            
        }
        // selling
        else {

            int choice1 = prices[ind] + helper(ind + 1, 1, prices, n, dp);
            int choice2 = 0 + helper(ind + 1, 0, prices, n, dp);

            profit = max(choice1, choice2);
        }
        
        return dp[ind][canBuy] = profit;
    }

    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1)); 

        return helper(0, 1, prices, n, dp);

    }
};

// 2
// tab
// O(n*2)
// O(n*2)
class Solution {
public:

    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0)); 

        dp[n][0] = 0;
        dp[n][1] = 0;

        for(int i = n-1; i >= 0; i--){
            for(int j = 1; j >= 0; j--){
                
                int profit = 0;

                if(j == 1){

                    int choice1 = -prices[i] + dp[i + 1][0];
                    int choice2 = dp[i + 1][1];

                    profit = max(choice1, choice2);            
                }
                else {
                    int choice1 = prices[i] + dp[i + 1][1];
                    int choice2 = dp[i + 1][0];

                    profit = max(choice1, choice2);
                }        

                dp[i][j] = profit;
            }
        }

        return dp[0][1];

    }
};

// 3
// space optimised
// O(n*2)
// O(2*2)
class Solution {
public:

    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();        
        vector<int> prev(2, 0);

        prev[0] = 0;
        prev[1] = 0;

        for(int i = n-1; i >= 0; i--){

            vector<int> temp(2, 0);

            for(int j = 1; j >= 0; j--){
                
                int profit = 0;

                if(j == 1){

                    int choice1 = -prices[i] + prev[0];
                    int choice2 = prev[1];

                    profit = max(choice1, choice2);            
                }
                else {
                    int choice1 = prices[i] + prev[1];
                    int choice2 = prev[0];

                    profit = max(choice1, choice2);
                }        

                temp[j] = profit;
            }

            prev = temp;
        }

        return prev[1];

    }
};