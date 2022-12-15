#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/unique-paths-ii/

// similar to previuos one. 

// 1
// memo
// O(m*n)
// O(m*n) + O(m-1 + n-1) (stack space)

class Solution {
public:
    int helper(int i, int j, vector<vector<int>>& obstacleGrid, vector<vector<int>> &dp  ){

        if(i >= 0 && j >= 0 && obstacleGrid[i][j]  == 1) return 0;
        if(i == 0 && j == 0) return 1;
        if(i < 0  || j < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int left = helper(i, j - 1, obstacleGrid, dp);
        int upper = helper(i - 1, j, obstacleGrid, dp);        

        return dp[i][j] =  left + upper;
        
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        if(obstacleGrid[0][0] == 1 || obstacleGrid[n-1][m-1] == 1 ) return 0;

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return helper(n-1, m-1, obstacleGrid, dp );
    }
};

// 2
// tab
// O(m*n)
// O(m*n)

class Solution {
public:

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        if(obstacleGrid[0][0] == 1 || obstacleGrid[n-1][m-1] == 1 ) return 0;

        vector<vector<int>> dp(n, vector<int>(m, -1));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                
                if(obstacleGrid[i][j] == 1) dp[i][j] = 0;
                else if( i == 0 && j == 0) dp[i][j] = 1;
                else {
                    
                    int left = 0, upper = 0;

                    if( j > 0 ) left = dp[i][j-1];
                    if(i > 0 ) upper = dp[i-1][j];
                    
                    dp[i][j] = left + upper;

                }

            }
        }

        return dp[n-1][m-1];
    }
};

// 3
// space optimised.
// O(n*m)
// O(2*m)

class Solution {
public:

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        if(obstacleGrid[0][0] == 1 || obstacleGrid[n-1][m-1] == 1 ) return 0;
        
        vector<int> prev(m, -1);        

        for(int i = 0; i < n; i++){

            vector<int> temp(m, -1);        
            for(int j = 0; j < m; j++){
                
                if(obstacleGrid[i][j] == 1) temp[j] = 0;
                else if( i == 0 && j == 0) temp[j] = 1;
                else {
                    
                    int left = 0, upper = 0;

                    if( j > 0 ) left = temp[j-1];
                    if(i > 0 ) upper = prev[j];
                    
                    temp[j] = left + upper;
                }
            }

            prev = temp;
        }

        return prev[m-1];
    }
};

// 3
// optimised
// O(n*m)
// O(2*m)

class Solution {
public:

    int minPathSum(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();

        vector<int> prev(m, -1);

        for(int i =0 ; i < n; i++){

            vector<int> temp(m, -1);
            for(int j =0; j < m; j++){
                
                if(i == 0 && j == 0) temp[j] = grid[i][j];
                else{

                    int left = 1e9 , upper = 1e9;
                    if( j > 0) left = grid[i][j] + temp[j-1];
                    if( i > 0) upper = grid[i][j] + prev[j];

                    temp[j] = min(left, upper);
                }
            }

            prev = temp;
        }

        return prev[m-1];

    }
};