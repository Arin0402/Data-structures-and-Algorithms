#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/lcs-of-three-strings0028/1

// memo
// O(n*n*n)
// O(n*n*n)
int LCSof3(string A, string B, string C, int n1, int n2, int n3)
{

    vector<vector<vector<int>>> dp(n1 + 1, vector<vector<int>>(n2 + 1, vector<int>(n3 + 1, 0)));

    for (int i = 1; i <= n1; i++)
    {
        for (int j = 1; j <= n2; j++)
        {
            for (int k = 1; k <= n3; k++)
            {

                if (A[i - 1] == B[j - 1] && B[j - 1] == C[k - 1])
                    dp[i][j][k] = 1 + dp[i - 1][j - 1][k - 1];
                else
                    // we have 6 options to decide the indexes.
                    dp[i][j][k] = max({dp[i][j - 1][k], dp[i][j][k - 1],
                                       dp[i - 1][j][k], dp[i][j][k - 1],
                                       dp[i - 1][j][k], dp[i][j - 1][k]});

                // The reduced form of the above part is( as they are repeated in the above part)
                // dp[i][j][k] = max({ dp[i][j-1][k], dp[i][j][k-1],dp[i-1][j][k]});
            }
        }
    }

    return dp[n1][n2][n3];
}

// space optimised
// O(n*n*n)
// O(2*n*n)
int LCSof3(string A, string B, string C, int n1, int n2, int n3)
{

    vector<vector<int>> prev(n2 + 1, vector<int>(n3 + 1, 0));
    for (int i = 1; i <= n1; i++)
    {

        vector<vector<int>> temp(n2 + 1, vector<int>(n3 + 1, 0));
        for (int j = 1; j <= n2; j++)
        {
            for (int k = 1; k <= n3; k++)
            {

                if (A[i - 1] == B[j - 1] && B[j - 1] == C[k - 1])
                    temp[j][k] = 1 + prev[j - 1][k - 1];
                else

                    temp[j][k] = max({temp[j - 1][k], temp[j][k - 1], prev[j][k]});
            }
        }

        prev = temp;
    }

    return prev[n2][n3];
}