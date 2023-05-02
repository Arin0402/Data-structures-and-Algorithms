#include <bits/stdc++.h>
using namespace std;
#define MOD 1003

// https://practice.geeksforgeeks.org/problems/boolean-parenthesization5610/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

// 1
// memo
// O(n*n*2*n)  extra n for FOR LOOP
// O(n*n) + O(n)
class Solution{
public:
    
    int helper(int i, int j, int isTrue, string &s, vector<vector<vector<int>>> &dp){
        
        if(i > j) return 0;
        
        if(dp[i][j][isTrue] != -1) return dp[i][j][isTrue]; 
        
        if(i == j){
            if(isTrue) return s[i] == 'T';
            else  return s[i] == 'F';
        }
        
        long long int ways = 0;
        
        for(int ind = i + 1; ind < j ; ind += 2){
            
            int LT = helper(i, ind-1, 1, s, dp);
            int LF = helper(i, ind-1, 0, s, dp);
            
            int RT = helper(ind+1, j, 1, s, dp);
            int RF = helper(ind+1, j, 0, s, dp);
            
            if(s[ind] == '&'){
                
                if(isTrue) ways = (ways + (LT*RT) %MOD)%MOD ;
                else ways = (ways + (LT*RF) %MOD + (RT*LF) %MOD + (LF*RF) %MOD)%MOD;
            }
            else if(s[ind] == '|'){
                
                if(isTrue) ways = (ways + (LT*RT) %MOD + (LT*RF) %MOD + (LF*RT) %MOD)%MOD;
                else ways =(ways +(LF*RF)%MOD )%MOD;
            }
            else {
                
                if(isTrue) ways = (ways + (LT*RF) %MOD + (LF*RT) %MOD)%MOD;
                else ways = (ways + (LF*RF) %MOD + (LT*RT) %MOD)%MOD;
            }
        }
        
        return dp[i][j][isTrue] = ways;
    }
    
    int countWays(int N, string S){
        
        vector<vector<vector<int>>> dp(N, vector<vector<int>>(N, vector<int>(2, -1)));
        return helper(0, N-1, 1, S, dp);
        
    }
};

// 2
// tab
// O(n*n*2)
// O(n*n)
class Solution{
public:
    
    int countWays(int N, string s){
        
        vector<vector<vector<int>>> dp(N, vector<vector<int>>(N, vector<int>(2, -1)));
        
        for(int i = 0; i < N; i++){
            
            dp[i][i][1] = s[i] == 'T';
            dp[i][i][0] =  s[i] == 'F';   
        }
        
        for(int i = N-1; i >=  0; i--){
            for(int j = i + 1; j < N; j++){
                
                for(int isTrue = 0; isTrue < 2; isTrue++){
                    
                    long long int ways = 0;
                    
                    for(int ind = i + 1; ind < j ; ind += 2){
                        
                        int LT = dp[i][ind-1][1];
                        int LF = dp[i][ind-1][0];
                        
                        int RT = dp[ind+1][j][1];
                        int RF = dp[ind+1][j][0];
                        
                        if(s[ind] == '&'){
                            
                            if(isTrue) ways = (ways + (LT*RT) %MOD)%MOD ;
                            else ways = (ways + (LT*RF) %MOD + (RT*LF) %MOD + (LF*RF) %MOD)%MOD;
                        }
                        else if(s[ind] == '|'){
                            
                            if(isTrue) ways = (ways + (LT*RT) %MOD + (LT*RF) %MOD + (LF*RT) %MOD)%MOD;
                            else ways =(ways +(LF*RF)%MOD )%MOD;
                        }
                        else {
                            
                            if(isTrue) ways = (ways + (LT*RF) %MOD + (LF*RT) %MOD)%MOD;
                            else ways = (ways + (LF*RF) %MOD + (LT*RT) %MOD)%MOD;
                        }
                    }
                
                    dp[i][j][isTrue] = ways;
                }
                
            }
            
        }
        
        return dp[0][N-1][1];
        
    }
};