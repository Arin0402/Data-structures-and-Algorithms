#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/edit-distance3702/1

class Solution {
  public:
  
    int helper(int i, int j, string &s, string &t,vector<vector<int>> &dp ){
        // if s is empty , then minimum operations would be equal to the number of 
        // characters in t, as only insertion will be done.
        if(i < 0) return j + 1; 
        
        // if t is empty , then minimum operations would be equal to the number of 
        // characters in s, as only deletion will be done.
        if(j < 0) return i + 1; 
        
        if(dp[i][j] != -1) return dp[i][j];
        
        // character matched.
        if(s[i] == t[j]){
            
            return dp[i][j] =  helper(i-1, j-1, s, t, dp);
        }
        else{
            
            // insert the charcter.
            int choice1 = 1 + helper(i, j-1, s, t, dp);
            // delete character
            int choice2 = 1 + helper(i-1, j, s, t, dp);
            // replace
            int choice3 = 1 + helper(i -1, j-1,s, t, dp);
            
            return dp[i][j] = min({choice1, choice2, choice3});
        }
    }
    
    int editDistance(string s, string t) {
            
        int n = s.size();
        int m = t.size();
        
        vector<vector<int>> dp(n, vector<int>(m, -1));
        
        return helper(n-1, m-1, s, t , dp);
    }
};