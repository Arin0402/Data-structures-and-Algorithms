#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/geek-and-its-game-of-coins4043/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

// 1
// O(N)
// O(N)
class Solution{
	public:
    // 	for n-1 or n-x or n-y coins , if B is losser, then for n coins A is winner.
	int findWinner(int N, int X, int Y)
	{
		vector<bool> dp(N+1, 0);
		
		dp[0] = false;
		dp[1] = true;
		
		for(int i = 2; i <= N; i++){
		    
		    if(i >= 1 && dp[i-1] == false) dp[i] = true;
		    else if(i >= X && dp[i-X] == false) dp[i] = true;
		    else if(i >= Y && dp[i-Y] == false) dp[i] = true;
		    else dp[i] = false;
		}
		
		return dp[N];
		
	}

};
	