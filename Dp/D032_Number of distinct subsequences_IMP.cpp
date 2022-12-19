#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/number-of-distinct-subsequences0909/1

// This question is not part of striver dp series.

// 1
// generate all the subsequences and find unique using set

// 2
// dp
// https://www.youtube.com/watch?v=9UEHPiK53BA

#define MOD 1000000007

class Solution
{
public:
	int distinctSubsequences(string s)
	{
		int n = s.size();

		long long int dp[n + 1];

		dp[0] = 1;

		map<char, long long int> mp;

		for (int i = 1; i <= n; i++)
		{

			dp[i] = (2 * dp[i - 1] % MOD);

			char ch = s[i - 1];

			if (mp.find(ch) != mp.end())
			{

				int j = mp[ch];

				dp[i] = (dp[i] - dp[j - 1] + MOD) % MOD;
			}

			mp[ch] = i;
		}

		return dp[n];
	}
};