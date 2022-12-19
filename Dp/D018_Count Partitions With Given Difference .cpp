#include <bits/stdc++.h>
using namespace std;

// https://www.codingninjas.com/codestudio/problems/partitions-with-given-difference_3751628?leftPanelTab=0

// 1
// memo
int code(int ind, int target, vector<vector<int>> &dp, vector<int> arr)
{
    if (ind < 0)
    {
        if (target == 0)
            return 1;
        return 0;
    }

    // OR

    // if(ind == 0){
    //     if(target == 0 && arr[0] == 0) return 2;
    //     if(target == 0 || arr[0] == target) return 1;
    //     return 0;
    // }

    if (dp[ind][target] != -1)
        return dp[ind][target];

    int take = 0;

    if (arr[ind] <= target)
        take = code(ind - 1, target - arr[ind], dp, arr);
    int not_take = code(ind - 1, target, dp, arr);

    dp[ind][target] = (take + not_take) % 1000000007;
}
int countPartitions(int n, int d, vector<int> &arr)
{

    int total = 0;
    for (int i = 0; i < n; i++)
        total += arr[i];

    if ((total - d) & 1 == 1)
        return 0;

    vector<vector<int>> dp(n, vector<int>(total + 1, -1));

    return code(n - 1, (total - d) / 2, dp, arr);
}
