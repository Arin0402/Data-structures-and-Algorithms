#include <bits/stdc++.h>
using namespace std;

// https://www.youtube.com/watch?v=YHSjvswCXC8
// video is lengthy but concept is clear.

class Solution{
    public:
    /*You are required to complete below method */
    long long int  countPS(string s)
    {
                
        long long int n = s.size();
        
        long long int mod = 1000000007;
        
        // dp array.
        vector<vector<long long int>> dp(n , vector<long long int>(n, 0));
        
        for(long long int g = 0; g < n ; g++ ){
            
            for(long long int i = 0, j = g ; j < n; i++, j++ ) {
                
                if(g == 0){
                    dp[i][j] = 1;
                }
                else if(g == 1){
                    
                    if(s[i] == s[j]) dp[i][j]  = 3;
                    else dp[i][j] = 2;
                }
                else {
                    
                    if(s[i] == s[j]){
                        dp[i][j]  = (dp[i][j-1] + dp[i+1][j] + 1 +mod)%mod;
                    }
                    else dp[i][j] = (dp[i][j-1] + dp[i+1][j] - dp[i+1][j-1] + mod)%mod;
                    
                }
                
                
            }
            
        }
        
        return dp[0][n-1]%mod;
       
    }
     
};