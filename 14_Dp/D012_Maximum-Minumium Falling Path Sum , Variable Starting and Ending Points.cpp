#include <bits/stdc++.h>
using namespace std;

// https://www.codingninjas.com/codestudio/problems/maximum-path-sum-in-the-matrix_797998?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

// 1
// memo

int helper(int row, int col, vector<vector<int>> &matrix, vector<vector<int>> &dp, int m){

    if(row == 0) return matrix[row][col];

    if(dp[row][col] != -1) return dp[row][col];

    int choice1 = INT_MIN;
    int choice2 = INT_MIN;
    int choice3 = INT_MIN;

    if(col - 1 >= 0) choice1 = helper(row - 1, col - 1, matrix, dp, m);
    choice2 = helper(row - 1, col, matrix, dp, m);
    if(col + 1 < m) choice3 = helper(row -1, col + 1, matrix, dp, m);

    return dp[row][col] = matrix[row][col] + max({choice1, choice2, choice3}); 

}

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    int ans = INT_MIN;

    vector<vector<int>> dp(n, vector<int>(m , -1));

    for(int i = 0; i < m; i++){
        ans = max(ans, helper(n-1, i, matrix, dp,  m));
    }
    
    return ans;

}

// 2
// tab

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    int ans = INT_MIN;

    vector<vector<int>> dp(n, vector<int>(m , 0));

    for(int i = 0; i < m; i++) dp[0][i] = matrix[0][i];
    
    for(int row = 1; row < n; row++){
        for(int col = 0; col < m; col++){
            int choice1 = INT_MIN;
            int choice2 = INT_MIN;
            int choice3 = INT_MIN;

            if(col - 1 >= 0) choice1 = dp[row - 1][col - 1];
            choice2 = dp[row - 1][col];
            if(col + 1 < m) choice3 = dp[row - 1][col + 1];

            dp[row][col] = matrix[row][col] + max({choice1, choice2, choice3});        
        }
    }

    for(int i = 0; i < m; i++){
        ans = max(ans, dp[n-1][i]);
    }
    
    return ans;

}

// 3
// space optimised

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    int ans = INT_MIN;

    vector<int> prev(m , 0);

    for(int i = 0; i < m; i++) prev[i] = matrix[0][i];
    
    for(int row = 1; row < n; row++){

        vector<int> curr(m, 0);

        for(int col = 0; col < m; col++){
            int choice1 = INT_MIN;
            int choice2 = INT_MIN;
            int choice3 = INT_MIN;

            if(col - 1 >= 0) choice1 = prev[col - 1];
            choice2 = prev[col];
            if(col + 1 < m) choice3 = prev[col + 1];

            curr[col] = matrix[row][col] + max({choice1, choice2, choice3});        
        }

        prev = curr;
    }

    for(int i = 0; i < m; i++){
        ans = max(ans, prev[i]);
    }
    
    return ans;

}
