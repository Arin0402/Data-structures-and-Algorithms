#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/

// 1
// memo
// O(N*2*3)
// O(N*2*3) + O(N)
class Solution {
public:

    int helper(int ind, int canBuy, int count,  vector<int>& prices, int n, vector<vector<vector<int>>> &dp){

        if(count == 2) return 0;
        if(ind == n) return 0;
        
        if(dp[ind][canBuy][count] != -1) return dp[ind][canBuy][count];

        int profit = 0;

        if(canBuy == 1){

            int choice1 = -prices[ind] + helper(ind + 1, 0, count ,  prices, n, dp);
            int choice2 = 0 + helper(ind + 1, 1,  count , prices, n, dp);

            profit = max(choice1, choice2);            
        }
        else {

            int choice1 = prices[ind] + helper(ind + 1, 1, count + 1, prices, n, dp);
            int choice2 = 0 + helper(ind + 1, 0, count, prices, n, dp);

            profit = max(choice1, choice2);
        }
        
        
        return dp[ind][canBuy][count] = profit;
    }

    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(2, -1)));

        return helper(0, 1, 0, prices, n, dp);

    }
};

// 2
// tab
// O(N*2*3)
// O(N*2*3) 
class Solution {
public:

    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();

        // we do plus one for the state which is changed
        // here index and count are the states which are changed (i.e see in memo code)
        // but there is fixed value of canBuy( see in memo) so it is remained 2.
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2 , vector<int>(3, 0)));

        for(int i = n - 1; i >= 0; i--){
            for(int j = 1; j >= 0; j--){
                for(int k = 0; k < 2; k++){

                    int profit = 0;

                    if(j == 1){

                        int choice1 = -prices[i] + dp[i + 1][0][k];
                        int choice2 = 0 + dp[i + 1][1][k];

                        profit = max(choice1, choice2);            
                    }
                    else {

                        int choice1 = prices[i] + dp[i + 1][1][k + 1];
                        int choice2 = 0 + dp[i + 1][0][k];

                        profit = max(choice1, choice2);
                    }

                    dp[i][j][k] = profit;
                }
            }
        }

        return dp[0][1][0];
    }
};

// 3
// space optimised.
// O(N*2*3)
// O(2*2*3) 
class Solution {
public:

    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        
        vector<vector<int>> prev(2 , vector<int>(3, 0));

        for(int i = n - 1; i >= 0; i--){

            vector<vector<int>> temp(2 , vector<int>(3, 0));

            for(int j = 1; j >= 0; j--){                
                for(int k = 0; k < 2; k++){

                    int profit = 0;

                    if(j == 1){

                        int choice1 = -prices[i] + prev[0][k];
                        int choice2 = 0 + prev[1][k];

                        profit = max(choice1, choice2);            
                    }
                    else {

                        int choice1 = prices[i] + prev[1][k + 1];
                        int choice2 = 0 + prev[0][k];

                        profit = max(choice1, choice2);
                    }

                    temp[j][k] = profit;
                }
            }

            prev = temp;
        }

        return prev[1][0];
    }
};