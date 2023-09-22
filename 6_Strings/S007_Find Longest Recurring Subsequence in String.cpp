#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1

//1 
// O(n^2)

class Solution {
	public:
	    
	    int helper(int ind1, int ind2, string &str1, string &str2, vector<vector<int>> &dp){
	        
	        if(ind1 < 0 || ind2 < 0) return 0;
	        
	        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
	        
	        if(str1[ind1] == str2[ind2] && ind1 != ind2) 
	            return dp[ind1][ind2] = 1 + helper(ind1 - 1, ind2 - 1, str1, str2, dp);
	        
	        return dp[ind1][ind2] = max( 
	                helper(ind1 - 1, ind2 , str1, str2, dp),
	                helper(ind1, ind2 - 1, str1, str2, dp)
	        );
	    }
	
		int LongestRepeatingSubsequence(string str){
		    
		    int n = str.size();
		    
		    vector<vector<int>> dp(n, vector<int>(n, -1));
		    
		    return helper(n - 1, n - 1, str, str, dp);
		    
		}

};

// 2
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