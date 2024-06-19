#include <bits/stdc++.h>
using namespace std;

// https://www.codingninjas.com/codestudio/problems/ninja-and-his-friends_3125885?leftPanelTab=0

// 1
// memo
// top down
// O(n*m*m)
// O(n*m*m) + O(n)

class Solution
{
public:
    
    int helper(int row, int col1, int col2, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp, int n, int m){
    
        if(row == n-1){
            if(col1 == col2) return grid[row][col1];
            return grid[row][col1] + grid[row][col2];
        }
    
        if(dp[row][col1][col2] != -1) return dp[row][col1][col2];
    
        int maxi = INT_MIN;
    
        for(int i = -1 ; i < 2; i++){
            int ncol1 = col1 + i;
    
            if(ncol1 >= 0 && ncol1 < m){
    
              for (int j = -1; j < 2; j++) {
    
                int ncol2 = col2 + j;
    
                if (ncol2 >= 0 && ncol2 < m){                
                    maxi = max(maxi, helper(row + 1, ncol1, ncol2, grid, dp, n, m));
                }
    
              }
    
            }
        }
    
        if(col1 != col2) return dp[row][col1][col2] = grid[row][col1] + grid[row][col2] + maxi;
        return dp[row][col1][col2] = grid[row][col1] + maxi;
    
    
    }
    
    int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
        
        vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1)));
    
        return helper(0, 0, c - 1, grid, dp, r, c);
    
    }
};

// 2
// tab
// bottom up
// O(n*m*m)
// O(n*m*m)
class Solution
{
public:
    
    int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
        
        vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, 0)));
    
        for(int i = 0; i < c; i++){
            for(int j = 0; j < c; j++){
                if(i == j){
                    dp[r-1][i][j] = grid[r-1][i];
                }
                else dp[r-1][i][j] = grid[r-1][i] + grid[r-1][j];
            }
        }
    
        for(int row = r-2; row >= 0; row--){
            for(int col1 = 0; col1 < c; col1++){
                for(int col2 = 0; col2 < c; col2++){
                    
                    int maxi = INT_MIN;
    
                    for(int i = -1 ; i < 2; i++){
                        int ncol1 = col1 + i;
    
                        if(ncol1 >= 0 && ncol1 < c){
    
                        for (int j = -1; j < 2; j++) {
    
                            int ncol2 = col2 + j;
    
                            if (ncol2 >= 0 && ncol2 < c){                
                                maxi = max(maxi, dp[row + 1][ncol1][ncol2]);
                            }
    
                        }
    
                        }
                    }
    
                    if(col1 != col2) dp[row][col1][col2] = grid[row][col1] + grid[row][col2] + maxi;
                    else dp[row][col1][col2] = grid[row][col1] + maxi;
    
    
                }
            }
        }
    
    
        return dp[0][0][c - 1];
    
    
    
    }
};

// 3
// space optimised
// O(n*m*m)
// O(2*m*m)

class Solution
{
public:
    int maximumChocolates(int r, int c, vector<vector<int>> &grid)
    {

        vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1)));

        vector<vector<int>> prev(c, vector<int>(c, -1));

        // base case.
        for (int j1 = 0; j1 < c; j1++)
        {
            for (int j2 = 0; j2 < c; j2++)
            {

                if (j1 == j2)
                    prev[j1][j2] = grid[r - 1][j1];
                else
                    prev[j1][j2] = grid[r - 1][j1] + grid[r - 1][j2];
            }
        }

        for (int i = r - 2; i >= 0; i--)
        {

            vector<vector<int>> temp(c, vector<int>(c, -1));
            for (int j1 = 0; j1 < c; j1++)
            {
                for (int j2 = 0; j2 < c; j2++)
                {

                    int maxi = INT_MIN;
                    for (int a = -1; a < 2; a++)
                    {
                        for (int b = -1; b < 2; b++)
                        {

                            int chocolates = INT_MIN;
                            if (j1 + a >= 0 && j1 + a < c && j2 + b >= 0 && j2 + b < c)
                            {
                                if (j1 == j2)
                                    chocolates = grid[i][j1] + prev[j1 + a][j2 + b];
                                else
                                    chocolates = grid[i][j1] + grid[i][j2] + prev[j1 + a][j2 + b];
                            }
                            maxi = max(maxi, chocolates);
                        }
                    }

                    temp[j1][j2] = maxi;
                }
            }

            prev = temp;
        }

        return prev[0][c - 1];
    }
};
