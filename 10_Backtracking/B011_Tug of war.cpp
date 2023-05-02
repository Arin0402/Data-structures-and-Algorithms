#include <bits/stdc++.h>
using namespace std;

// https://www.codingninjas.com/codestudio/problems/tug-of-war_985253?leftPanelTab=0

// we need to go through all the subsets of size n/2.
// calculate the sum of that subset (call it sum1).
// the sum of other subset will be sum2 =   n - sum1.
// difference = abs(sum1 - sum2).

#include <bits/stdc++.h>

long int total(vector<int> &arr, int n)
{
    long int total = 0;
    for (auto ele : arr)
        total += ele;
    return total;
}

int helper(int pos, int count, int members, long int tempSum, long int sum, vector<int> &arr, int n, vector<vector<int>> &dp)
{

    if (count == members)
        return abs(sum - 2 * tempSum); // (sum - tempsum) - tempsum;
    if (pos >= n)
        return INT_MAX; // out of bound.

    if (dp[pos][tempSum] != -1)
        return dp[pos][tempSum];

    int pick = helper(pos + 1, count + 1, members, tempSum + arr[pos], sum, arr, n, dp);
    int not_pick = helper(pos + 1, count, members, tempSum, sum, arr, n, dp);

    return dp[pos][tempSum] = min(pick, not_pick); // return the minimum of the two.
}

int tugOfWar(vector<int> &arr, int n)
{
    long int sum = total(arr, n);
    int members = n / 2;  // half of the members.
    long int tempSum = 0; // current sum.
    int count = 0;        // current count.

    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));

    return helper(0, count, members, tempSum, sum, arr, n, dp);
}