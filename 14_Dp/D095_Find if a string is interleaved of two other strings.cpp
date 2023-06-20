#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/interleaved-strings/1

// 1
// memo
// O(n*m)
// O(n*m)
class Solution{
  public:
    /*You are required to complete this method */
    
    bool helper(int i, int j, int k, string &A, string &B, string &C, vector<vector<int>> &dp){
        
        if(k < 0 ) return true;
        if(i < 0 || j < 0) return true;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        bool choice1 = false, choice2 = false;
        
        if(C[k] == A[i]){
            choice1 = helper(i-1, j, k-1, A, B, C, dp);
        }
        if(C[k] == B[j]){
            choice2 = helper(i, j-1, k-1, A, B, C, dp);
        }
        
        return dp[i][j] = choice1 | choice2;
        
    }
    
    bool isInterleave(string A, string B, string C) 
    {
        int n = A.size();
        int m = B.size();
        int s = C.size();
        
        if(n + m != s) return 0;
        
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return helper(n-1, m-1, s-1, A, B, C, dp);
    }

};

// OR

class Solution{
  public:
        
    bool helper(int i, int j, int k, string &A, string &B, string &C, vector<vector<int>> &dp){
        
        if(k == 0 ) return true;
        if(i== 0 || j == 0) return true;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        bool choice1 = false, choice2 = false;
        
        if(C[k-1] == A[i-1]){
            choice1 = helper(i-1, j, k-1, A, B, C, dp);
        }
        if(C[k-1] == B[j-1]){
            choice2 = helper(i, j-1, k-1, A, B, C, dp);
        }
        
        return dp[i][j] = choice1 | choice2;
        
    }
    
    bool isInterleave(string A, string B, string C) 
    {
        int n = A.size();
        int m = B.size();
        int s = C.size();
        
        if(n + m != s) return 0;
        
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return helper(n, m, s, A, B, C, dp);
    }

};