#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/reach-a-given-score-1587115621/1

// 1
long long helper(int ind, long long int n, vector<int> &arr, vector<vector<long long>> &dp){
    
    if(n == 0) return 1;
    
    if(ind < 0){
        return n == 0;
    }
    
    if(dp[ind][n] != -1) return dp[ind][n];
    
    int not_take = helper(ind - 1, n, arr, dp);
    
    int take = 0;
    
    if(arr[ind] <= n) take = helper(ind, n - arr[ind], arr, dp);
    
    return dp[ind][n] = take + not_take;
    
}

long long int count(long long int n)
{
    vector<int> arr = {3,5,10};
    vector<vector<long long>> dp(3, vector<long long>(n+1, -1));
    
    return helper(2, n, arr, dp);
}

// OR
// 2
// https://www.youtube.com/watch?v=SzaLN2r6P4E

long long int count(long long int n)
{

    vector<int> dp(n + 1, 0);
    dp[0] = 1;

    for (int i = 3; i <= n; i++)
    {
        dp[i] += dp[i - 3];
    }

    for (int i = 5; i <= n; i++)
    {
        dp[i] += dp[i - 5];
    }

    for (int i = 10; i <= n; i++)
    {
        dp[i] += dp[i - 10];
    }

    return dp[n];
}
