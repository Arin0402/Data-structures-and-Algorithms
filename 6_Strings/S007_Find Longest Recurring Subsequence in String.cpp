#include <bits/stdc++.h>
using namespace std;

// 1
// using Dp
// bottom up approach
// TC - O(n^2)
// SC - O(n^2)

// same as longest commom subsequence problem.
// but just a little variation that is we can not take elements which are at the same index in both the strings
// as one element cannot repeat in two strings which we require.

class Solution {
	public:
		int LongestRepeatingSubsequence(string str){
		    
		    int x = str.size();
		    
		    int dp[x+1][x+1];
        
            for(int i =0 ; i <= x; i++){
                for(int j = 0; j <= x; j++){
                    
                    if(i == 0 || j == 0) dp[i][j] = 0;
                    
                    else if(str[i-1] == str[j-1] && i != j ) dp[i][j] = dp[i-1][j-1] + 1;
                    
                    else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                    
                }
            }
            
            return dp[x][x];
            
		}

};