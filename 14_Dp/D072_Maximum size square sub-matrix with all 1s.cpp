#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/largest-square-formed-in-a-matrix0806/1

// Same as D055 (count square matrices with all 1s)

// 1
// memo
// O(n*m)
// O(n*m)
class Solution{
public:

    int maxSquare(int n, int m, vector<vector<int>> matrix){
        
        vector<vector<int>> dp(n, vector<int>(m, 0));

        for (int j = 0; j < m; j++)
            dp[0][j] = matrix[0][j];
        for (int i = 0; i < n; i++)
            dp[i][0] = matrix[i][0];

        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {

                if (matrix[i][j] == 0)
                    dp[i][j] = 0;
                else
                {
                    dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
                }
            }
        }

        int sum = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                sum = max(sum, dp[i][j]);
            }
        }
        
        return sum;
    }
};