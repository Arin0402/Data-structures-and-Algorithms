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

class Solution{
  public:	
	int distinctSubsequences(string s)
	{
	    int n = s.size();

		// character -> index  
	    unordered_map<char,int> mp;
	    
		// to store the count
	    vector<int> dp(n+1, 0);

		// for empty subsequence
	    dp[0] = 1;
	    
	    for(int i = 1; i <= n; i++){
	        
			// current character
	        char ch = s[i-1];
	        
			// total number of subsequences for the current character will twice the count of subsequences till the previous character
			// as the current character will attach with each subsequence till the previous chartacter
	        dp[i] = (2 * dp[i-1]%MOD);
	        
			// found the same character before
	        if(mp.find(ch) != mp.end()){
	            
				// index of the before occured character
	            int j = mp[ch];
	            
				// decrease the count of the subsequences before this repeated character.
				// this is done to avoid repetitions
	            dp[i]  = (dp[i] - dp[j - 1] + MOD)%MOD;
	        }

			// update the map with the current character's indxe.	        
	        mp[ch] = i;
	        
	    }

		// return the final count.   
	    return dp[n];
	}
};